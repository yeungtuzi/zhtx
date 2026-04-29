// TIE@FY3
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
        string msg;
        me->delete_temp("block_msg/all");
        write(CLR);
        write("这么提心吊胆的玩值得吗？\n");
        return 1;
}

int help(object me)
{
     write(@HELP
指令格式: bossgone  

这个指令让你(玩家)在老板走后恢复正常游戏。

有关指令：boss
HELP
    );
    return 1;
}
