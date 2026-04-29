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
这儿已经到了森林的中部，光线显得有些昏暗。抬头看是茂密的大树，
地上长满了杂草和荆棘，基本上已经没有路了。你发现四周不时有一些动
静，看来这儿比较适合打猎。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                  "west" : __DIR__"forest2",
                  "southwest" : __DIR__"forest1",
                  "northwest" : __DIR__"forest5",
                  "north" : __DIR__"forest6",
                  "south" : __DIR__"forest3",
                ]));

        setup();
}


