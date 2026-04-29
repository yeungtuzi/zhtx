// Room: /d/xixia/duanmen.c

inherit ROOM;

void create()
{
	set("short", "端门");
	set("long", @LONG
这里是端门，往北通向午门。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"eroad7",
  "north" : __DIR__"eroad8",
]));
	set("objects", ([
		__DIR__"npc/shiwei7": 4,
	]));
	set("outdoors", "xixia");

	setup();
	replace_program(ROOM);
}
