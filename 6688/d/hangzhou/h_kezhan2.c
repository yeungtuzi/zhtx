//by tlang

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG "西子客栈" NOR);
	set("long", @LONG
	这儿可以睡觉，而且不必担心被人打扰。
LONG
	);

	set("no_fight", 1);
	set("valid_startroom", 0);
        set("sleep_room",1);

	set("exits", ([
		"down" : __DIR__"h_kezhan",
	]));

	setup();
}

