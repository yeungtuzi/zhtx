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
这是一条铺满碎石子的小路，南边就是新村广场，北边通往森林。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                  "south" : __DIR__"guangchang",
                  "north": __DIR__"ssroad2",
                ]));
                set("outdoors", "newbie");

        setup();
}



