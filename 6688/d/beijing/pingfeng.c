// Room: /u/p/pock/bj/pingfeng.c

inherit ROOM;

void create()
{
	set("short", "屏风");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"north" : __DIR__"shenwumen",
		"east" : __DIR__"eastdoor",
		"west" : __DIR__"westdoor",
]));

	setup();
	replace_program(ROOM);
}
