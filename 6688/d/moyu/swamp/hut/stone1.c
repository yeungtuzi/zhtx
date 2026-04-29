// stone1.c
// by meteoric
#include "ansi.h"
inherit "/ldg/std/dyna_room.c";

void create()
{
	set("short", "石室");
	set("long", BLK@LONG
一间偌大的石室，成长方形，却是空无一物。直至石室末端左方，
却有一道甬巷，只见红光隐动，竟不知是什么事物身上发出来的。
LONG NOR);
	set("exits", ([ /* sizeof() == 2 */
	  "west": __DIR__"stone2",
	  "southup":__DIR__"hut1",
	]));
        set("blocks", ([
                "west" : "wang wu",
                "southup" : "wang wu",
        ]));
        set("objects",([
                 "/d/moyu/npc/hut_guard2.c" : 1,
        ]));

	setup();
}
