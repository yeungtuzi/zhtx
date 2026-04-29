// exit.c 洞口
// by Masterall
#include <ansi.h>
inherit "/u/l/lazypig/room/qiankuncave.c";
void create()
{
        set("short", "洞口");
        set("long", @LONG
    前面似乎有光亮，好像就是宝库的出口了，你不由得睁大了眼睛，加快脚步冲上前
去。但似乎感到后面恶风不善，未等你反应过来，一道剑光已经扑面而来！
LONG
        );
        set("blocks", ([
                "north" : "wraith",
        ]));

        set("exits", ([
                "north" : __DIR__"shanlu2",
        ]));
        set("objects",([
                 __DIR__"npc/wraith" : 1,
        ]));
        setup();

}
 
int valid_leave(object ob,string dir)
{
        message_vision(HIY"$N深深的吸了一口气，顺着光亮走出了洞穴，有惊无险的离开了宝藏库。\n"NOR,ob);
        return 1;
}


