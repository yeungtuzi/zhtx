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
        set("short", CYN"森林深处"NOR);
        set("long", @LONG
这儿已经到了森林的深处，光线非常昏暗。抬头看是茂密的大树，
地上长满了杂草和荆棘，你已经快迷失方向了。你发现四周不时有一
些动静，看来这儿比较适合打猎。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                  "west" : __DIR__"forest5",
                  "southwest" : __DIR__"forest2",
                  "south" : __DIR__"forest4",
                ]));

        setup();
}


