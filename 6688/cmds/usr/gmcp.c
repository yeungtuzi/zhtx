// gmcp.c — GMCP debug toggle command

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    seteuid(getuid(me));

    if (!function_exists("gmcp_debug_toggle", me))
        return notify_fail("GMCP 功能未启用，请确认客户端支持 GMCP。\n");

    me->gmcp_debug_toggle();
    return 1;
}

int help(object me)
{
    write(@HELP
指令格式 : gmcp

切换 GMCP 调试模式。开启后，每次向客户端推送的 GMCP
Char.Vitals 消息会同时输出到主频道，方便确认数据是否正
确发送。

需要客户端支持 GMCP 协议（如 Mudlet）。
HELP
    );
    return 1;
}
