// stone3.c
// by meteoric
#include "ansi.h"
inherit "/ldg/std/dyna_room.c";

void create()
{
	set("short", "石室");
	set("long", BLK@LONG
走过一道通巷，你眼前红光大浓，简直是血光一般。只见又是一座
大石室，空气十分潮湿，石室一间又一间，愈渐往地底下深入，不
知前人建此石室，有所用处？
LONG NOR);
	set("exits", ([ /* sizeof() == 2 */
	  "east": __DIR__"stone2",
	]));
       set("blocks", ([
              "east" : "chi qi",
      ]));

        set("objects",([
                 "/d/moyu/npc/hut_guard4.c" : 1,
        ]));


	setup();
}
