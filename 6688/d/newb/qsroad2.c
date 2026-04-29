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
这是一条宽敞的大道，整齐的铺满了大块的青石。北边是杂货铺，南
边是一家钱庄。往西就是新村广场了。东边可以通往夫子书院和小溪。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                  "west" : __DIR__"guangchang",
                  "east": __DIR__"qsroad3",
                  "north": __DIR__"zahuopu",
                  "south": __DIR__"qianzhuang",
                ]));
                set("outdoors", "newbie");

                setup();
}



