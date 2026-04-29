// Room: /d/xixia/northsquare.c

inherit ROOM;

void create()
{
	set("short", "北门广场");
	set("long", @LONG
这里虽说是也是东南西北大街道的交汇之处，但较之东、南门
广场，则显得冷清多了，只有南边经常有人来往。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"northstreet2",
  "north" : __DIR__"northstreet1",
  "south" : __DIR__"marketplace2",
  "west" : __DIR__"northstreet5",
]));

	setup();
	replace_program(ROOM);
}
