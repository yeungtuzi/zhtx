// Room: /d/xixia/yipintang2.c

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "一品堂嘉宾室");
	set("long", @LONG
这里是一品堂的嘉宾室，室内铺着红色地毯，一张张茶几排列
成行，每个茶几上都放着四色点心，四壁挂着名家字画，几个一品
堂的高手正坐在这里休息，北边你看到一扇小门。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"yipintang3",
  "east" : __DIR__"yipintang",
]));
	set("objects", ([
		__DIR__"npc/yeerniang": 1,
		__DIR__"npc/nanhaieshen": 1,
                __DIR__"npc/gfighter": 2,
		__DIR__"npc/yunzhonghe": 1,
		__DIR__"obj/chaji": 1,
	]));
	create_door("north", "小门", "south", DOOR_CLOSED);

	setup();
}
