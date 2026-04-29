// Room: /d/lingjiu/leftroad.c

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
这是一条由青石板铺成的小路。西边是骆驼房。
LONG
	);
	set("outdoors", "lingjiu");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"road2",
  "east" : __DIR__"path1",
  "west" : __DIR__"camelroom",
]));

	setup();
	replace_program(ROOM);
}
