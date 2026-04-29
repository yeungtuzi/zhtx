///////////////////////////////////////////////////////
//------Newbie Area @ ZHTX2 -------------------------//
//------Made by flyaway -----------------------------//
//------------------------- Jun 2003 ----------------//
///////////////////////////////////////////////////////

#include <ansi.h>
inherit __DIR__"newbie_room";

void create()
{
        set("short", "石子路");
        set("long", @LONG
这是一条铺满石子的小路，隐隐可以听到潺潺的流水声从东
边传来。再往东就是一条小溪了。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                  "east" : __DIR__"brook",
                  "west": __DIR__"qsroad3",
                ]));
                set("outdoors", "newbie");

        setup();
}



