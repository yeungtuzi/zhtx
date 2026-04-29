// Room: /d/xingxiu/room1.c

#include <room.h>

inherit ROOM;
#include "/std/room/check_room_family.c"

void create()
{
	set("short", "星宿弟子居");
	set("long", @LONG
这里是星宿弟子的起居室，屋内陈设简陋，盖因星宿海乃偏僻之地。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"houshan1",
  "south" : __DIR__"floor",
]));
        set("sleep_room", "1");
        set("family","星宿派");
        set("no_faint",1);

	create_door("northup", "后门", "southdown", DOOR_CLOSED);

	setup();
}
