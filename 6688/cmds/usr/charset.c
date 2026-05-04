// charset.c — 字符集切换命令

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    string encoding;

    seteuid(getuid(me));

    if (!arg || arg == "") {
        encoding = query_encoding();
        write("当前字符集：" + encoding + "\n");
        write("可用字符集：utf8, gbk, big5\n");
        write("切换指令：charset <编码>\n");
        return 1;
    }

    switch (arg) {
    case "utf8":
    case "utf-8":
        encoding = set_encoding("UTF-8");
        break;
    case "gbk":
    case "gb2312":
        encoding = set_encoding("GBK");
        break;
    case "big5":
        encoding = set_encoding("BIG5");
        break;
    default:
        write("不支持的编码：" + arg + "\n");
        write("可用字符集：utf8, gbk, big5\n");
        return 1;
    }

    write("字符集已切换为 " + encoding + "。\n");
    return 1;
}

int help(object me)
{
    write(@HELP
指令格式 : charset [utf8|gbk|big5]

切换客户端字符集编码，以兼容不同 MUD 客户端：

  charset          查看当前字符集
  charset utf8     切换为 UTF-8（Mudlet 等现代客户端默认）
  charset gbk      切换为 GBK/GB2312（zMUD 简体中文版等）
  charset big5     切换为 Big5（zMUD 繁体中文版等）

切换后系统会自动将输入/输出在 UTF-8 与目标编码之间转码。
HELP
    );
    return 1;
}
