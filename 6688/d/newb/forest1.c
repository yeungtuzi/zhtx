///////////////////////////////////////////////////////
//------Newbie Area @ ZHTX2 -------------------------//
//------Made by flyaway -----------------------------//
//------------------------- Jun 2003 ----------------//
///////////////////////////////////////////////////////

#include <ansi.h>
//inherit ROOM;
inherit __DIR__"huntarea.c";

void create()
{
        set("short", CYN"森林"NOR);
        set("long", @LONG
刚进森林，光线开始暗淡起来。抬头看是茂密的大树，地上
长满了杂草和荆棘，有几条小路向四周延伸。你发现四周不时有
一些动静，看来这儿比较适合打猎。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                  "north" : __DIR__"forest2",
                  "northeast" : __DIR__"forest4",
                  "east" : __DIR__"forest3",
                  "southeast" : __DIR__"forest",
                ]));

        setup();
}


