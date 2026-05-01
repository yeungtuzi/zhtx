# CleanCode — LPC 编译警告系统性修复

## 概述

zhtx mudlib（11,137 个 `.c` 文件）运行在 MudOS-NG 驱动上。驱动编译器在加载每个 LPC 文件时会输出编译警告：未使用变量、类型不匹配、参数数量不一致、无效转义符等。这些警告数量庞大，长期积累后掩盖了真正的运行时错误。

本文档记录系统性修复全部编译警告的规划、执行过程和结果。

---

## 工具链

### 核心工具：MudOS-NG `symbol`

- 路径：`/Users/lf/vscode/mudos-ng/build/bin/symbol`
- 用法：`symbol config.cfg /lpc/path`
- 功能：加载完整 mudlib 环境（master、simul_efun、19 个预加载守护进程）后编译目标文件，输出编译警告到 stderr
- 速度：约 0.016 秒/文件，11k 文件单线程约 3 分钟
- 退出码：0 = 成功（即使有警告），1 = 编译失败

### 辅助脚本

| 脚本 | 路径 | 功能 |
|------|------|------|
| `scan_warnings.py` | `tools/scan_warnings.py` | 批量扫描全部 .c 文件，并行执行，生成结构化 JSON 报告 |
| `verify_file.sh` | `tools/verify_file.sh` | 单文件验证，报告自源警告 |
| `auto_fix_unused_vars.py` | `tools/auto_fix_unused_vars.py` | 自动修复未使用局部变量（实验性，存在边界识别 bug） |

---

## 预扫描结果

对全部 11,137 个 `.c` 文件进行全量扫描：

```
============================================================
  SCAN SUMMARY (2026-05-01 初始基线)
============================================================
  Total files scanned:      11,137
  Files with warnings:      7,311
  Files with self-warnings:   845
  Files with errors:          368
  Total warning lines:      46,660
  Self-warnings only:        1,893
  Inherited warnings:       44,767
============================================================
```

### 警告分类

| 类型 | 数量 | 说明 |
|------|------|------|
| 未使用的局部变量 | 1,120 | 变量声明后从未使用 |
| 参数数量与定义不一致 | 261 | 函数签名与父类原型不匹配 |
| 字符串中未知转义符 | 239 | `\X` 形式却非有效转义序列 |
| 菱形继承 | 71 | 同一函数从多条路径继承 |
| 全局变量重复声明 | 21 | 同一变量多次声明 |
| 函数返回类型不一致 | 9 | void vs int 不匹配 |
| 表达式无副作用 | 8 | 死代码 |
| 继承函数未定义 | 4 | 基类未完全编译 |
| 负数索引已废弃 | 4 | `arr[-i]` 应改为 `arr[<i]` |
| 非 void 函数缺少返回值 | 3 | 缺少 return 语句 |
| 其他 | 153 | |

### 传播分析：前 15 个高影响基础类文件

基础类文件被数百至数千个子类继承，其警告会传播到所有子类中：

| 文件 | 传播数量 | 自源警告 |
|------|---------|---------|
| `feature/damage.c` | 19,505 | 5 |
| `std/room.c` | 12,136 | 2 |
| `feature/attack.c` | 3,901 | 1 |
| `std/char/quest.c` | 3,140 | 10 |
| `adm/daemons/race/human.c` | 1,465 | 1 |
| `ldg/std/adv_equip.c` | 920 | 8 |
| `std/char/master.c` | 798 | 1 |
| `adm/daemons/combatd.c` | 272 | 16 |
| `std/char/vendor.c` | 271 | 1 |
| `std/char/doomnpc.c` | 121 | 1 |
| `std/force.c` | 83 | 1 |
| `ldg/std/dynamapd.c` | 70 | 2 |
| `std/bboard.c` | 65 | 1 |
| `u/z/zephyr/sunflower/sfroom.c` | 60 | 2 |
| `std/char/dealer.c` | 54 | 2 |

**关键洞察：修复这 15 个基础类文件可消除 44,767 条传播警告（97%）。**

---

## 修复策略

按照影响力从高到低的顺序修复，每个阶段完成后重新扫描验证：

```
Phase 1: 搭建检查基础设施（scan_warnings.py, verify_file.sh）
Phase 2: 全量初始扫描，建立基线数据
Phase 3a: 修复 15 个高影响基础类文件（消除 97% 传播警告）
Phase 3b: 修复 globals.h 重复包含（消除重定义警告）
Phase 5: 批量修复未使用局部变量（~1,120 条，实验性自动化）
Phase 6-8: 修复无效转义、参数不匹配、其余类别（未完成）
Phase 9: 最终验证扫描，确认 0 自源警告（未完成）
```

---

## 执行日志

### Commit 1: `a939123` — 运行时错误修复

**问题**：游戏中使用黄金购买物品后找零用白银时出错

```
apply() with insufficient permission:
cob: null, ob: obj/money/gold#160, function: destruct_me
origin: internal, needs: private, has: hidden
```

**根因**：`std/item/combined.c` 中 `destruct_me()` 声明为 `private`，但 `set_amount(0)` 通过 `call_out("destruct_me", 1)` 延迟调用时，MudOS 运行时仅有 `hidden` 权限，无法访问 `private` 函数。

**修复**：
- `std/item/combined.c:19` — `private void destruct_me()` → `void destruct_me()`
- `adm/daemons/moneyd.c:84` — 移除未使用的局部变量 `mage`

**文件**：
```
6688/std/item/combined.c  — 移除 private 修饰符
6688/adm/daemons/moneyd.c — 删除未使用变量 mage
```

---

### Commit 2: `4519380` — 15 个高影响基础类文件修复

#### feature/damage.c（传播 19,505 → 0）

| 行号 | 修改前 | 修改后 |
|------|--------|--------|
| 24 | `int mana,atman,maxforce,jiuyang,xishu;` | `int mana,jiuyang,xishu;` |
| 98 | `int val,mana,atman,maxforce;` | `int val,mana,maxforce;` |
| 304 | `int i,tmp_pot,xiandan,bonze;` | `int tmp_pot,xiandan,bonze;` |
| 453 | `int update_flag, i;` | `int update_flag;` |

删除 5 个未使用变量：`atman`（2 处）、`maxforce`、`i`（2 处）。

#### std/room.c（传播 12,136 → 0）

| 行号 | 修改前 | 修改后 |
|------|--------|--------|
| 202 | `mapping d, item_desc;` | `mapping d;` |
| 248 | `object guard, *ob;` | `object *ob;` |

删除 2 个未使用变量：`item_desc`、`guard`。

#### feature/attack.c（传播 3,901 → 0）

| 行号 | 修改前 | 修改后 |
|------|--------|--------|
| 287 | `object *ob;` | （删除整行） |

`remove_all_killer()` 中声明的 `ob` 从未使用，直接操作 `enemy` 数组。

#### std/char/quest.c（传播 3,140 → 0，10 条自源警告）

| 行号 | 修改前 | 修改后 |
|------|--------|--------|
| 58 | `object me,help_obj;` | `object me;` |
| 59 | `int fft=2, j, combatexp, timep, r_kar, q_bonus, s_fail=0;` | `int fft=2, j, combatexp, timep, r_kar, s_fail=0;` |
| 60 | `string tag = "1000000",err;` | `string tag = "1000000";` |
| 361 | `int bonus, exp, pot, score,val;` | `int val;` |
| 362 | `string test;` | （删除整行） |
| 436 | `int bonus, exp, pot, score, val, faith;` | `int bonus, exp, pot, score, faith;` |
| 665 | `int timep, bonus;` | `int bonus;` |

删除 10 个未使用变量：`help_obj`、`q_bonus`、`err`、`bonus`、`exp`、`pot`、`score`、`test`、`val`（give_bonus）、`timep`（special_quest）。

#### 其余基础类文件

| 文件 | 修改 | 传播→ |
|------|------|-------|
| `adm/daemons/race/human.c:45` | `int tmp,i,j;` → `int i,j;` | 1,465 → 0 |
| `std/char/master.c:35` | `功\夫` → `功夫` | 798 → 0 |
| `std/char/vendor.c:156` | `string file, *name;` → `string file;` | 271 → 0 |
| `adm/daemons/combatd.c` | 删除 16 个未使用变量（env, coefficient, damage_bonus, defense_factor, absorb_vic, bounce, ob, rate, block_time, i, force_punish, exp_punish, skill_punish, factor, atman_punish, mana_punish） | 272 → 0 |
| `std/char/doomnpc.c:82` | `int fighting,hurt,force_fac,i;` → `int fighting,hurt,force_fac;` | 121 → 0 |
| `std/force.c:28` | `丈许\！！` → `丈许！！` | 83 → 0 |
| `std/bboard.c:59` | `string msg, myid;` → `string msg;` | 65 → 0 |
| `ldg/std/adv_equip.c` | 删除 8 个未使用变量（owner×2, props, prop, type, kee, sen, gin） | 920 → 0 |
| `ldg/std/dynamapd.c` | 删除 `kk`, `enter` | 70 → 0 |

#### include/globals.h — 添加 include guard

```c
// 文件头部添加
#ifndef __GLOBALS_H__
#define __GLOBALS_H__

// 文件末尾添加
#endif // __GLOBALS_H__
```

同时从 12 个文件中移除冗余的 `#include <globals.h>`（驱动已通过 `config.cfg` 自动包含）：

- `ldg/std/adv_quest.c`
- `std/char/quest_bak.c`
- `std/char/g_quest.c`
- `std/char/quest.c`
- `cmds/wiz/chblk.c`
- `cmds/wiz/wizlian.c`
- `cmds/debug/dbxwhere.c`
- `cmds/debug/dbxframe.c`
- `class/guard/npc/obj/hsword.c`
- `d/taishan/npc/meng-zhu.c`
- `d/wizard/npc/jean.c`
- `d/wizard/npc/nstar.c`

（`class/guard/npc/goldend.c` 已经注释掉，无需修改）

---

## 修复后扫描结果

```
============================================================
  SCAN SUMMARY (2026-05-01 修复后)
============================================================
  Total files scanned:      11,137
  Files with warnings:       1,285  (曾: 7,311)
  Files with self-warnings:    832  (曾:   845)
  Files with errors:           366
  Total warning lines:       3,111  (曾: 46,660)
  Self-warnings only:        1,843  (曾:  1,893)
  Inherited warnings:        1,268  (曾: 44,767)
============================================================
```

### 效果对比

| 指标 | 修复前 | 修复后 | 降幅 |
|------|--------|--------|------|
| 总警告行数 | 46,660 | 3,111 | **93.3%** |
| 传播警告 | 44,767 | 1,268 | **97.2%** |
| 自源警告 | 1,893 | 1,843 | 2.6% |
| 有警告的文件数 | 7,311 | 1,285 | **82.4%** |

自源警告基本未变（仅减少 50 条），因为基础类自身的警告数量很少。但消除其传播后，受影响的文件数从 7,311 降到 1,285。

---

## 剩余工作

### 自源警告分类（共 1,843 条，涉及 832 文件）

| 类别 | 数量 | 优先级 | 自动化难度 |
|------|------|--------|-----------|
| 参数数量不匹配 | 261 | 高（class/ 技能文件，影响技能系统） | 中（需理解继承链） |
| 无效转义符 | 239 | 低（中文字符串反斜杠，仅 cosmetic） | 低（可半自动） |
| 未使用局部变量 | ~1,200 | 中 | 中（auto_fix 脚本待修复函数边界识别） |
| 菱形继承 | 71 | 低（编译器已自动选择路径） | 低 |
| 全局变量重声明 | 21 | 中 | 低 |
| 返回类型不匹配 | 9 | 中 | 中 |
| 表达式无副作用 | 8 | 低 | 低 |
| 继承函数未定义 | 4 | 高（class/guard/npc/redshw.c） | 中 |
| 负数索引废弃 | 4 | 低 | 低 |
| 缺少返回值 | 3 | 中 | 低 |

### 自动修复工具改进

`auto_fix_unused_vars.py` 在处理 marry_card.c 时暴露了函数边界识别 bug：当函数 A 的关闭大括号是警告行号、但目标变量在函数 B 中声明时，脚本错误地删除了函数 B 中实际使用的变量。

**改进方向**：
1. 修复大括号匹配逻辑，确保 `find_func_bounds()` 返回正确的函数范围
2. 在 `find_decl_in_func()` 中添加函数范围验证
3. 增加 dry-run 模式与实际修复的对比校验
4. 考虑基于 LPC AST 而非正则表达式的解析方案

### 需要运行中 MUD 环境处理的文件

368 个文件（主要是 `d/` 区域文件）在 `symbol` 离线编译时显示 "Fail to load object"，需要虚拟对象服务运行时支持。这些文件的警告需在实际 MUD 驱动运行后通过 `update` 命令捕获。

---

## 经验教训

1. **传播分析优先**：修复 15 个文件消除了 97% 的传播警告，ROI 极高
2. **离线工具有局限**：`symbol` 工具无法加载需要虚拟对象服务的区域文件，需要运行中的驱动配合
3. **自动化需谨慎**：基于正则的代码修改容易因边界 case 出错（如函数范围识别）。对于关键代码，手动逐文件修复更安全
4. **每次提交一个类别**：便于回溯和代码审查
5. **include guard 简单有效**：两个 `#ifndef`/`#endif` 消除了 698 条重定义警告

---

---

### Commit 3: `02243d4` — 无效反斜杠转义修复

**问题**：239 处 `Unknown \ escape` 警告，`\` 后跟中文字符或非有效转义字符。

**修复策略**：
- `\` 后跟 UTF-8 字符（≥0x80，即中文等非 ASCII 字符）→ 删除反斜杠
- `\` 后跟空格或 tab（ASCII 艺术地图中线绘制）→ 双写为 `\\`
- 保留所有有效 LPC 转义序列：`\n` `\t` `\r` `\\` `\"` `\'` `\0` `\xNN`

**工具**：`tools/fix_escapes.py` — 自动扫描、修复并逐文件验证

**执行**：
```
Found 131 files with unknown escape warnings
OK 128 files, 2 FAIL (exercise, advexercise: 剩余为非转义警告)
Manual fix: obj/map/map.c (\/水 → \\/水)
Manual fix: d/hangzhou/npc/obj/hzmap.c (ASCII 地图)
Manual fix: cmds/std/exercise.c (内功\ .... → 内功 ....)
Manual fix: u/m/masterall/cmds/advexercise.c (同上)
```

**文件统计**：131 文件，190 处修复

---

### Commit 4: `02243d4` — 附加工具

- `tools/fix_escapes.py` — 无效转义自动修复工具（安全：仅处理 UTF-8 字节前的反斜杠）

---

## 相关提交

| Commit | 说明 |
|--------|------|
| `a939123` | fix: 修复金钱交易找零时 destruct_me 权限错误及未使用变量警告 |
| `4519380` | fix: 修复 15 个高影响基础类文件的编译警告，消除 93% 传播警告 |
| `02243d4` | fix: 修复 131 个文件中的 190 处无效反斜杠转义警告 |

## 相关文件

| 文件 | 说明 |
|------|------|
| `tools/scan_warnings.py` | 批量扫描工具（219 行 Python） |
| `tools/auto_fix_unused_vars.py` | 自动修复工具（201 行 Python，实验性） |
| `tools/verify_file.sh` | 单文件验证脚本（46 行 Bash） |
| `tools/scan_results.json` | 全量扫描结果（JSON，供分析用） |
