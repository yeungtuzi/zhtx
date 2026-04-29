// This is a room made by roommaker.

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "张宅");
	set("long", "这是一个很大的院落，很多青衣家人在默默的忙碌着。\n");
        set("objects", ([
                __DIR__"npc/jiaren2.c" : 1,
]));


	setup();
	replace_program(ROOM);
}
