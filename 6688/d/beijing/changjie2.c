// changjie2.c
// written by pock 98/09/04

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", CYN"十里长街"NOR);
	set("long", @LONG
这是一条宽阔的青石街道，向东西两头延伸。北边就是金水河，南边是
个大广场。广场上人山人海，来游览的，做买卖的，或匆匆而过的，各色人
等，不一而足，的确是一个繁华的地方。
LONG
	);
        set("outdoors", "bj");

	set("exits", ([
		"west" : __DIR__"changjie1",
		"south" : __DIR__"square",
		"east" : __DIR__"changjie3",
		"north" : __DIR__"bridge1",
	]));
	set("objects", ([

	]));

	setup();
	replace_program(ROOM);
}

