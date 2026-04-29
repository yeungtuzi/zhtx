// Room: /d/xingxiu/road1.c

inherit ROOM;

void create()
{
	set("short", "小道");
	set("long", @LONG
这是一条经过修理的小路，比起在沼泽地好走多啦！路上有星宿派弟子来来往往。
北边是一间比较大的房屋，正是星宿派的总舵。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"room2",
  "east" : __DIR__"road2",
  "west" : __DIR__"floor",
]));
	set("no_clean_up", 0);

	set("outdoors", "xingxiu");
	setup();
	replace_program(ROOM);
}
