///////////////////////////////////////////////////////
//------Newbie Area @ ZHTX2 -------------------------//
//------Made by flyaway -----------------------------//
//------------------------- Jun 2003 ----------------//
///////////////////////////////////////////////////////

#include <ansi.h>
inherit __DIR__"newbie_room";

void create()
{
        set("short", YEL"荒草路"NOR);
        set("long", @LONG
一条长满了荒草的小路。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                  "southeast" : __DIR__"hcroad1",
                  "north": __DIR__"hcroad3",
                ]));
                set("outdoors", "newbie");

                setup();
}



