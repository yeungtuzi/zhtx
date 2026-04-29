// uptime.c
#include <ansi.h>
inherit F_CLEAN_UP;

// This command is also called by LOGIN_D, so we don't want it use
// arguments.
int main()
{
        write("纵横天下II已经运行了" + CHINESE_D->chinese_period(uptime()) + "。\n");
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : uptime

这个指令告诉你纵横天下已经连续执行了多久.

HELP
    );
    return 1;
}


