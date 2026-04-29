// Room: /d/lingjiu/path0.c

inherit ROOM;

void create()
{
	set("short", "青石路");
	set("long", @LONG
一条有青石板铺成的小路，南边是演武场，东西两边
是灵鹫宫九天九部的总部。
LONG
	);
	set("outdoors", "lingjiu");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"path1",
  "east" : __DIR__"path4",
  "west" : __DIR__"path2",
  "south" : __DIR__"floor",
]));

	setup();
	replace_program(ROOM);
}
