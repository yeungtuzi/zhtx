// Room: /d/xixia/npc/yipintang3.c

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "一品堂休息室");
	set("long", @LONG
这里是专门供一品堂高手练功和打坐的地方。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"yipintang2",
]));

	set("sleep_room", 1);
	set("no_faint", 1);
	create_door("south", "小门", "north", DOOR_CLOSED);
	setup();
}
