// Room: /d/lingjiu/path1.c

inherit ROOM;

void create()
{
	set("short", "青石路");
	set("long", @LONG
这是一青石板铺成的小路，北边你通向独尊厅。
LONG
	);
	set("outdoors", "lingjiu");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"palace",
  "east" : __DIR__"rightroad",
  "west" : __DIR__"leftroad",
  "south" : __DIR__"path0",
]));

	setup();
	replace_program(ROOM);
}
