// stone2.c
// by meteoric
#include "ansi.h"
inherit "/ldg/std/dyna_room.c";

void create()
{
	set("short", "石室");
	set("long", BLK@LONG
你慢慢穿过通道，猛见又是一间长方形的石室，红光大炽。这红光隐隐
浮动看。似大焰吐舌一般，不过绝不是火焰的光芒。你注视了一阵，不
觉被这种红光弄得目眩脑昏，心血贲动，而这石室之中，除红光之外，
也空荡无物，而红光便是在这室内末端左方发出来的，该处红光大盛。 
LONG NOR);
	set("exits", ([ /* sizeof() == 2 */
	  "east": __DIR__"stone1",
	  "west": __DIR__"stone3",
	]));
        set("blocks", ([
                "west" : "mei liu",
                "east" : "mei liu",
        ]));
        set("objects",([
                 "/d/moyu/npc/hut_guard3.c" : 1,
        ]));

	setup();
}
