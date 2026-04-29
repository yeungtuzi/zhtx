// Room: /d/xixia/yneitang2.c

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "内堂");
	set("long", @LONG
这里是银川公主的闺房。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"yneitang",
]));
	set("objects", ([
		__DIR__"npc/gongzhu": 1,
		__DIR__"npc/ymaid": 2,
	]));

	create_door("south", "小帘门", "north", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
