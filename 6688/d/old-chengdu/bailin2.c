
#include <room.h>

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "甬道");
	set("long", @LONG
	这是一条笔直的大道，道路向南北延伸。道路两侧种满了苍松翠柏，
LONG
	);


	set("exits", ([
		"south" : __DIR__"bailin1",
		"north" : __DIR__"bailin3",
	]));

	set("outdoors", "city");
	setup();
}

