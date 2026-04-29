// Room: /d/xingxiu/xxh2.c

inherit ROOM;

void create()
{
	set("short", "小径");
	set("long", @LONG
小路弯弯曲曲，向着星宿海深处延伸。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"xxh1",
  "northwest" : __DIR__"xxh3",
]));
	set("objects", ([
		__DIR__"npc/shihou" : 1,
	]));
	set("no_clean_up", 0);
	set("outdoors", "xingxiu");

	setup();
	replace_program(ROOM);
}
