///////////////////////////////////////////////////////
//------Newbie Area @ ZHTX2 -------------------------//
//------Made by flyaway -----------------------------//
//------------------------- Jun 2003 ----------------//
///////////////////////////////////////////////////////

#include <ansi.h>
inherit __DIR__"newbie_room";

void create()
{
        set("short", "碎石路");
        set("long", @LONG
这是一条铺满碎石子的小路，北边通往森林。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                  "south" : __DIR__"ssroad1",
                  "north": __DIR__"forest",
                ]));
                set("outdoors", "newbie");
                set("objects", ([
                                __DIR__"npc/wolfdog": 1,
                        ]));
        setup();
}



