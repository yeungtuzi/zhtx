// Room: /d/lingjiu/rightroad.c

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
这是一条由青石板铺成的小路。往北你看到一缕炊烟。
LONG
	);
	set("outdoors", "lingjiu");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"road3",
  "west" : __DIR__"path1",
]));

	setup();
	replace_program(ROOM);
}
