// Room: /d/xixia/zhonghedian.c

inherit ROOM;

void create()
{
	set("short", "中和殿");
	set("long", @LONG
这是一座亭形方殿，供皇帝上朝前休息之用。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"taihedian",
  "north" : __DIR__"baohedian",
]));
	set("objects", ([
		__DIR__"npc/pfighter1": 2,
		__DIR__"npc/pfighter2": 2,
		__DIR__"npc/pfighter3": 2,
	]));

	setup();
	replace_program(ROOM);
}
