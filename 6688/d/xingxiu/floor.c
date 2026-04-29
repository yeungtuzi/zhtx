// Room: /d/xingxiu/floor.c

inherit ROOM;

void create()
{
	set("short", "星宿海尽头");
	set("long", @LONG
这里已经到了星宿海的尽头，没想到居然有一片比较平坦的地方。许多星宿派的人
聚集在这里，大都在说一些令人肉麻的话。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"room1",
  "southdown" : __DIR__"xxh5",
  "east" : __DIR__"road1",
]));
	set("objects", ([
		__DIR__"npc/gushou" : 1,
		__DIR__"npc/haoshou" : 1,
		__DIR__"npc/boshou" : 1,
		__DIR__"npc/zhaixing" : 1,
]));
	set("no_clean_up", 0);
	set("outdoors", "xingxiu");

	setup();
	replace_program(ROOM);
}
