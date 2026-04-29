///////////////////////////////////////////////////////
//------Newbie Area @ ZHTX2 -------------------------//
//------Made by flyaway -----------------------------//
//------------------------- Jun 2003 ----------------//
///////////////////////////////////////////////////////

#include <ansi.h>
inherit __DIR__"newbie_room";

void create()
{
        set("short", "青石大道");
        set("long", @LONG
这是一条宽敞的大道，整齐的铺满了大块的青石。北边就是夫子书院，
不时传来啷啷的读书声。东边通往小溪。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                  "west": __DIR__"qsroad2",
                  "north": __DIR__"shuyuan",
                  "east": __DIR__"szroad1",
                ]));
                set("outdoors", "newbie");
                set("objects", ([
                                                __DIR__"npc/cunmin1": 1,
                        ]));

                setup();
}



