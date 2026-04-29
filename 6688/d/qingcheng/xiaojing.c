// This is a room made by roommaker.
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "小径");
	set("long", @LONG
这里是一条幽静的小径，它有两面都被茂盛的松树包围着。
而它的南边是青城的接待室，西边有一个小阁楼。
LONG
	);
	set("exits",([
		"south":__DIR__"tearoom",
		"west":__DIR__"ge",
		     ]));
	create_door("south", "小门", "north", DOOR_CLOSED);
	setup();
	
}
