// /d/xizang/class/gold_wh/hole.c

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "山洞");
        set("long", @LONG
这里是一个黑乎乎的山洞,阴暗潮湿,弥漫着一股发霉腐烂的气味.
LONG
        );
        set("exits", ([
		 "east" : __DIR__"hole1",
		 "west" : __DIR__"slope",
]));
	create_door("east", "铁栅栏门", "west", DOOR_CLOSED);
        setup();
	replace_program(ROOM);
}
