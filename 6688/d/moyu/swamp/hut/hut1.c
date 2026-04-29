// hut1.c
// by meteoric
#include <ansi.h>
//#include <room.h>
inherit "/ldg/std/dyna_room.c";
//#define MOYU_DIR "/d/moyu/"

void create()
{
	set("short", "小屋内");
	set("long", @LONG
    屋子里潮湿而阴暗，屋子并不十分窄小，但只有一桌，一床，
一凳．更显得四壁箫然，空洞寂寞．也衬得那一盏孤灯更昏黄暗淡．
壁上的积尘未除，屋面上还结着蛛网，屋角有一甬道，深达地下。
LONG );
	set("exits", ([
                "northdown":__DIR__"stone1",
                "out":"/d/moyu/swamp/hut",
        ]));
        set("blocks", ([
                "northdown" : "liang si",
        ]));
        set("objects",([
                 "/d/moyu/npc/hut_guard.c" : 1,
        ]));
	
	setup();
}
