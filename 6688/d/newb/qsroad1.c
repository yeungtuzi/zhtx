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
这是一条宽敞的大道，整齐的铺满了大块的青石。北边是当铺，
南边是一家武器店。往东就是新村广场了。西边开始荒凉起来，路
上长满了荒草。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                  "east" : __DIR__"guangchang",
                  "west": __DIR__"hcroad1",
                  "north": __DIR__"dangpu",
                  "south": __DIR__"wuqipu",
                ]));
                set("outdoors", "newbie");

                setup();
}



