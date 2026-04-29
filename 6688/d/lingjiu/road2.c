// Room: /d/lingjiu/road2.c

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
这是一由青石板铺成的小路。西边是书房。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"leftroad",
  "east" : __DIR__"floor2",
  "west" : __DIR__"bookroom",
]));
	set("outdoors", "lingjiu");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
