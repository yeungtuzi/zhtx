// charset.c — charset switching command (English-only to avoid garbled text)

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    string encoding;

    seteuid(getuid(me));

    if (!arg || arg == "") {
        encoding = query_encoding();
        write("Current charset: " + encoding + "\n");
        write("Usage: charset <utf8|gbk|big5>\n");
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
        write("Unknown charset: " + arg + "\n");
        write("Available: utf8, gbk, big5\n");
        return 1;
    }

    write("Charset switched to " + encoding + ".\n");
    return 1;
}

int help(object me)
{
    write(@HELP
Usage: charset [utf8|gbk|big5]

Switch client charset encoding for compatibility:

  charset          Show current charset
  charset utf8     UTF-8 (default for modern clients like Mudlet)
  charset gbk      GBK/GB2312 (Chinese Simplified, for zMUD/cMUD)
  charset big5     Big5 (Chinese Traditional)

The system will auto-translate I/O between UTF-8 and the target encoding.
For zMUD/cMUD users, GBK is auto-detected on connect via terminal type.
HELP
    );
    return 1;
}
