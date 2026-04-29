///////////////////////////////////////////////////////
//------Newbie Area @ ZHTX2 -------------------------//
//------Made by flyaway -----------------------------//
//------------------------- Jun 2003 ----------------//
///////////////////////////////////////////////////////

#include <ansi.h>
inherit __DIR__"newbie_room";

void create()
{
        set("short", HIR"新村广场"NOR);
        set("long", @LONG
这里是新手村最繁华热闹的地方了，来来往往的行人络绎不绝。
往北去比较荒凉，可以通向附近的森林。往南是悦来客栈，生意也
是十分兴隆。东西两边是大路，铺着整齐的青石。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                  "south" : __DIR__"kezhan",
                  "north": __DIR__"ssroad1",
                  "west": __DIR__"qsroad1",
                  "east": __DIR__"qsroad2",
                ]));
                set("outdoors", "newbie");
                set("objects", ([
//                                __DIR__"npc/xiaoqingnian": 1,
                                __DIR__"npc/yong": 1,
                        ]));
        setup();
}



