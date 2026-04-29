//      cedian1.c 侧殿
//      Designed by secret (秘密)
//      97/04/09
// /d/xizang/cedian1.c

#include <room.h>
inherit ROOM;

void create()
{
        set("short","侧殿");
        set("long",@LONG
这里是雪山寺的东侧殿。殿内有神态各异的十八罗汉塑像。
LONG
        );

        set("exits",([
                "up" : __DIR__"zoulang1",
                "west" : __DIR__"dadian",
        ]));
        set("objects",([
                __DIR__"npc/jiamu" : 1,
                __DIR__"npc/xiang-ke" : 1,
        ]));

        setup();

}
int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam=(mapping)me->query("family");
        if( (!myfam || myfam["family_name"] !="雪山寺" ) && dir=="up"
        && objectp(present ("jiamu dafashi", environment(me))))
            return notify_fail("嘉木大法师说道: 你非雪山寺弟子,不能入内\n");
        return ::valid_leave(me,dir);
}
