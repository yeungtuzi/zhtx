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
- 速度：约 0.016 秒/文件，11k 文件并行扫描约 30 秒
- 退出码：0 = 成功（即使有警告），1 = 编译失败
- 局限：离线编译无法加载需要虚拟对象服务的区域文件（`d/` 目录），此类文件显示 "Fail to load object"

### 自建工具

| 脚本 | 路径 | 功能 | 状态 |
|------|------|------|------|
| `scan_warnings.py` | `tools/scan_warnings.py` | 批量扫描全部 .c 文件，8 进程并行，生成 JSON 报告 | 稳定 |
| `verify_file.sh` | `tools/verify_file.sh` | 单文件验证，报告自源警告 | 稳定 |
| `fix_escapes.py` | `tools/fix_escapes.py` | 自动修复无效反斜杠转义（仅处理 UTF-8 字节前的 `\`） | 稳定 |
| `auto_fix_unused_vars.py` | `tools/auto_fix_unused_vars.py` | 自动修复未使用局部变量 | **实验性** — 函数边界识别有 bug，已回滚 |

---

## 预扫描结果（2026-05-01 初始基线）

```
============================================================
  SCAN SUMMARY
============================================================
  Total files scanned:      11,137
  Files with warnings:       7,311
  Files with self-warnings:    845
  Files with errors:           368
  Files exit != 0:             368
  Total warning lines:       46,660
  Self-warnings only:         1,893
  Inherited warnings:        44,767
============================================================
```

### 警告分类（初始）

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
| 其他 | 153 | 各类杂项 |

### 传播分析：前 15 个高影响基础类文件

基础类被数百至数千个子类继承，其警告会传播到所有子类中：

| 文件 | 传播数 | 自源警告 | 影响范围 |
|------|--------|---------|---------|
| `feature/damage.c` | 19,505 | 5 | 伤害系统 |
| `std/room.c` | 12,136 | 2 | 所有房间 |
| `feature/attack.c` | 3,901 | 1 | 战斗系统 |
| `std/char/quest.c` | 3,140 | 10 | 任务系统 |
| `adm/daemons/race/human.c` | 1,465 | 1 | 人类种族 |
| `ldg/std/adv_equip.c` | 920 | 8 | 高级装备 |
| `std/char/master.c` | 798 | 1 | 师徒系统 |
| `adm/daemons/combatd.c` | 272 | 16 | 战斗守护 |
| `std/char/vendor.c` | 271 | 1 | 商人 |
| `std/char/doomnpc.c` | 121 | 1 | 末日 NPC |
| `std/force.c` | 83 | 1 | 内功基础 |
| `ldg/std/dynamapd.c` | 70 | 2 | 动态地图 |
| `std/bboard.c` | 65 | 1 | 留言板 |
| `u/z/zephyr/sunflower/sfroom.c` | 60 | 2 | 葵花宝典 |
| `std/char/dealer.c` | 54 | 2 | 交易商 |

**关键洞察：修复这 15 个文件可消除 44,767 条传播警告（97%）。**

---

## 修复策略

按影响力递减，每阶段完成后重新扫描验证：

```
Phase 1  ████████████ 搭建检查基础设施                     ✅ 完成
Phase 2  ████████████ 全量初始扫描，建立基线               ✅ 完成
Phase 3a ████████████ 修复 15 个高影响基础类文件            ✅ 完成
Phase 3b ████████████ 修复 globals.h 重复包含              ✅ 完成
Phase 4  ████████████ 修复无效转义符（190 处 / 131 文件）   ✅ 完成
Phase 5  ██████░░░░░░ 批量修复未使用局部变量               ⚠ 实验性（已回滚）
Phase 6  ░░░░░░░░░░░░ 修复参数数量不匹配（261）             ⬜ 待办
Phase 7  ░░░░░░░░░░░░ 修复其余类别（~119）                  ⬜ 待办
Phase 8  ░░░░░░░░░░░░ 最终验证扫描 → 0 自源警告            ⬜ 待办
```

---

## 执行日志

### Commit 1: `a939123` — 运行时错误修复（金钱交易找零）

**问题**：游戏中购买物品后找零用白银时出错。

```
apply() with insufficient permission:
cob: null, ob: obj/money/gold#160, function: destruct_me
origin: internal, needs: private, has: hidden
```

**根因**：`std/item/combined.c:19` — `destruct_me()` 声明为 `private`，但 `set_amount(0)` 通过 `call_out("destruct_me", 1)` 延迟调用；MudOS 运行时的 `call_out` 通过 `apply()` 调用仅有 `hidden` 权限级别，无法访问 `private` 函数。

**修复**：

| 文件 | 行号 | 修改前 | 修改后 |
|------|------|--------|--------|
| `std/item/combined.c` | 19 | `private void destruct_me()` | `void destruct_me()` |
| `adm/daemons/moneyd.c` | 84 | `int tencash,cash,gc, sc, cc, left, mage;` | `int tencash,cash,gc, sc, cc, left;` |

---

### Commit 2: `4519380` — 高影响基础类修复（15 文件，消除 97% 传播）

#### feature/damage.c（传播 19,505 → 0）

| 行号 | 修改前 | 修改后 | 函数 |
|------|--------|--------|------|
| 24 | `int mana,atman,maxforce,jiuyang,xishu;` | `int mana,jiuyang,xishu;` | `receive_damage()` |
| 98 | `int val,mana,atman,maxforce;` | `int val,mana,maxforce;` | `receive_wound()` |
| 304 | `int i,tmp_pot,xiandan,bonze;` | `int tmp_pot,xiandan,bonze;` | `die()` |
| 453 | `int update_flag, i;` | `int update_flag;` | `update_condition()` |

#### std/room.c（传播 12,136 → 0）

| 行号 | 修改前 | 修改后 |
|------|--------|--------|
| 202 | `mapping d, item_desc;` | `mapping d;` |
| 248 | `object guard, *ob;` | `object *ob;` |

#### feature/attack.c（传播 3,901 → 0）

| 行号 | 修改前 | 修改后 |
|------|--------|--------|
| 287 | `object *ob;` | （删除整行） |

#### std/char/quest.c（传播 3,140 → 0，10 条自源警告）

| 行号 | 修改前 | 修改后 | 函数 |
|------|--------|--------|------|
| 58 | `object me,help_obj;` | `object me;` | `give_quest()` |
| 59 | `int fft=2, j, combatexp, timep, r_kar, q_bonus, s_fail=0;` | `int fft=2, j, combatexp, timep, r_kar, s_fail=0;` | `give_quest()` |
| 60 | `string tag = "1000000",err;` | `string tag = "1000000";` | `give_quest()` |
| 361 | `int bonus, exp, pot, score,val;` | `int val;` | `accept_object()` |
| 362 | `string test;` | （删除整行） | `accept_object()` |
| 436 | `int bonus, exp, pot, score, val, faith;` | `int bonus, exp, pot, score, faith;` | `give_bonus()` |
| 665 | `int timep, bonus;` | `int bonus;` | `special_quest()` |

#### 其余 9 个基础类文件

| 文件 | 修改 | 传播降幅 |
|------|------|---------|
| `adm/daemons/race/human.c:45` | `int tmp,i,j;` → `int i,j;` | 1,465 → 0 |
| `std/char/master.c:35` | `功\夫` → `功夫`（无效转义） | 798 → 0 |
| `std/char/vendor.c:156` | `string file, *name;` → `string file;` | 271 → 0 |
| `adm/daemons/combatd.c` | 16 处删除（env, coefficient, damage_bonus, defense_factor, absorb_vic, bounce, ob, rate, block_time, i, force/exp/skill_punish, factor, atman/mana_punish） | 272 → 0 |
| `std/char/doomnpc.c:82` | `int fighting,hurt,force_fac,i;` → `int fighting,hurt,force_fac;` | 121 → 0 |
| `std/force.c:28` | `丈许\！！` → `丈许！！`（无效转义） | 83 → 0 |
| `std/bboard.c:59` | `string msg, myid;` → `string msg;` | 65 → 0 |
| `ldg/std/adv_equip.c` | 8 处删除（owner×2, props, prop, type, kee, sen, gin） | 920 → 0 |
| `ldg/std/dynamapd.c` | 删除 `kk`, `enter` | 70 → 0 |

#### include/globals.h — include guard + 移除重复包含

在文件首尾添加：
```c
#ifndef __GLOBALS_H__
#define __GLOBALS_H__
// ... 原有内容 ...
#endif // __GLOBALS_H__
```

从 12 个文件中移除冗余的 `#include <globals.h>`（驱动通过 `config.cfg` 已自动包含）：
`ldg/std/adv_quest.c`, `std/char/quest_bak.c`, `std/char/g_quest.c`, `std/char/quest.c`,
`cmds/wiz/chblk.c`, `cmds/wiz/wizlian.c`, `cmds/debug/dbxwhere.c`, `cmds/debug/dbxframe.c`,
`class/guard/npc/obj/hsword.c`, `d/taishan/npc/meng-zhu.c`, `d/wizard/npc/jean.c`, `d/wizard/npc/nstar.c`

（`class/guard/npc/goldend.c` 原有 `#include <globals.h>` 已注释，无需修改。）

---

### Commit 3: `02243d4` — 无效反斜杠转义修复（131 文件 / 190 处）

**问题**：LPC 字符串中 `\` 后跟中文字符（如 `功\夫`）或非有效转义字符时，编译器报告 `Unknown \ escape`。

**修复策略**：

| 场景 | 处理方式 | 示例 |
|------|---------|------|
| `\` 后跟 UTF-8 字符（中文等） | 删除 `\` | `功\夫` → `功夫` |
| `\` 后跟空格/制表符 | 双写为 `\\` | ASCII 地图线绘制 |
| `\n` `\t` `\\` `\"` 等合法转义 | **不动** | — |

**工具**：`tools/fix_escapes.py` — 逐文件扫描、修复、`symbol` 验证。

**执行结果**：
```
Found 131 files with unknown escape warnings
128 OK (verified 0 remaining)
  3 FAIL → 手动修复:
    cmds/std/exercise.c     — 内功\ .... → 内功 ....（\后跟空格）
    obj/map/map.c           — \/水 → \\/水（\后跟中文）
    d/hangzhou/npc/obj/hzmap.c — ASCII 地图 \ → \\（7 处）
    u/m/masterall/cmds/advexercise.c — 同 exercise.c
```

**涉及目录**：`class/`（51 文件）、`d/`（32 文件）、`obj/`（16 文件）、`cmds/`（7 文件）、`u/`（9 文件）、`daemon/`（1 文件）、`feature/`（1 文件）、其余（14 文件）。

---

### Commit 4: `014ebd2` — 本文档

---

## 效果对比

```
============================================================
                      修复前          修复后         降幅
============================================================
总警告行数           46,660          ~2,730        94.1%
传播警告             44,767          ~1,270        97.2%
自源警告              1,893          ~1,460        22.9%
有警告的文件数        7,311          ~1,150        84.3%
有自源警告的文件        845            ~700        17.2%
============================================================
```

> 注：修复后数据基于 Phase 3a + 3b + 4 完成后重新扫描。

---

## 剩余工作

### 按类别

| 类别 | 约数 | 优先级 | 说明 |
|------|------|--------|------|
| 未使用局部变量 | ~1,200 | 中 | `auto_fix_unused_vars.py` 需修复函数边界识别后重跑 |
| 参数数量不匹配 | 261 | 高 | class/ 技能文件，需逐文件对齐函数签名 |
| 菱形继承 | 71 | 低 | 编译器已自动选择正确路径，删除重复 inherit |
| 全局变量重声明 | 21 | 中 | 删除重复声明 |
| 返回类型不匹配 | 9 | 中 | void/int 对齐 |
| 表达式无副作用 | 8 | 低 | 删除死代码 |
| 继承函数未定义 | 4 | 高 | `class/guard/npc/redshw.c` 需修复继承链 |
| 负数索引废弃 | 4 | 低 | `arr[-i]` → `arr[<i]` |
| 缺少返回值 | 3 | 中 | 添加 return 或改 void |
| 其他杂项 | ~60 | 低 | |

### 需运行中 MUD 环境处理的文件

586 个文件在 `symbol` 离线编译时显示 "Fail to load object"（主要 `d/` 区域文件），需要虚拟对象服务运行时支持。这些文件的警告需在实际 MUD 驱动中通过 `update` 命令捕获。

前 10 个 Fail to load 文件：

| # | 文件 | 自源警告 | 备注 |
|---|------|---------|------|
| 1 | `obj/marry_card.c` | 5 | 未使用变量 |
| 2 | `obj/token.c` | 0 | 纯依赖 |
| 3 | `obj/feilong.c` | 15 | 未使用变量 + 菱形继承 |
| 4 | `obj/jujing.c` | 15 | 同上 |
| 5 | `obj/connection.c` | 0 | 纯依赖 |
| 6 | `obj/toy/noname.c` | 0 | 纯依赖 |
| 7 | `obj/toy/book.c` | 0 | 纯依赖 |
| 8 | `obj/misc/marry_card.c` | 5 | 同 #1 |
| 9 | `obj/weapon/cannon.c` | 0 | 纯依赖 |
| 10 | `obj/weapon/bomb.c` | 0 | 纯依赖 |

### 自动修复工具改进方向（`auto_fix_unused_vars.py`）

在处理 `marry_card.c` 时暴露的 bug：当目标函数 A 有大括号嵌套层级错误时，脚本搜索到函数 B 的变量声明并错误删除。

**改进要点**：
1. 修复 brace matching，确保 `find_func_bounds()` 返回正确的函数范围
2. 添加跨函数声明验证（变量声明的函数 ≠ 警告所在的函数 → 跳过）
3. 每次修复后 `symbol` 验证，失败则回滚

---

## 相关提交

| Commit | 日期 | 说明 |
|--------|------|------|
| `a939123` | 2026-05-01 | fix: 修复金钱交易找零时 destruct_me 权限错误及未使用变量警告 |
| `4519380` | 2026-05-01 | fix: 15 个高影响基础类文件 + globals.h include guard + 检查工具 |
| `02243d4` | 2026-05-01 | fix: 131 个文件 190 处无效反斜杠转义警告 |
| `014ebd2` | 2026-05-01 | docs: CleanCode.md 完整规划与执行文档 |

## 相关文件

| 文件 | 行数 | 说明 |
|------|------|------|
| `tools/scan_warnings.py` | 219 | 批量扫描，8 进程并行，JSON 输出 |
| `tools/fix_escapes.py` | 96 | 无效转义自动修复（安全限定 UTF-8） |
| `tools/auto_fix_unused_vars.py` | 201 | 未使用变量自动修复（实验性） |
| `tools/verify_file.sh` | 46 | 单文件快速验证 |
| `tools/scan_results.json` | — | 全量扫描结果，供分析脚本读取 |
| `docs/CleanCode.md` | — | 本文档 |

---

## 经验教训

1. **传播分析优先**：修复 15 个基础类文件消除了 97% 的传播警告 — 这是最高 ROI 的策略
2. **离线工具有局限**：`symbol` 无法加载需要虚拟对象服务的文件（586 个），真正完整的验证需要运行中的 MUD 驱动
3. **自动化需严格校验**：代码自动修改必须逐文件 `symbol` 验证，失败立即回滚。对关键逻辑代码，手动修复更安全
4. **每次提交一个类别**：便于 git bisect 和代码审查
5. **include guard 简单高效**：两个预处理指令消除了 698 条重定义警告
6. **LPC 编译器的警告行号是函数关闭大括号**：需反向搜索到函数开头的变量声明行才能定位问题
