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
一条长满了荒草的小路。北边是一片沙滩。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                  "south" : __DIR__"hcroad2",
                  "north": __DIR__"satan1",
                ]));
                set("outdoors", "newbie");

                setup();
}



