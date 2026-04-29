///////////////////////////////////////////////////////
//------Newbie Area @ ZHTX2 -------------------------//
//------Made by flyaway -----------------------------//
//------------------------- Jun 2003 ----------------//
///////////////////////////////////////////////////////

#include <ansi.h>
inherit __DIR__"newbie_room";

void create()
{
        set("short", "客房");
        set("long", @LONG
这是一间宽敞的客房，不少过客都在这儿休息。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                  "east" : __DIR__"houyuan",
                  "north": __DIR__"kezhan",
                ]));
                set("no_fight", 1);
                set("sleep_room", "1");
                set("objects", ([
                                __DIR__"npc/cunson": 1,
                        ]));
        setup();
}



