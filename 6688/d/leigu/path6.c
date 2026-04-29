// Room: /d/leigu/path5.c

inherit ROOM;

void create()
{
	set("short", "上山小道");
	set("long", @LONG
几经周折，你终于走到了松林的尽头，前面你看到了一块颇为宽阔
的空地，好象有人坐在那里下棋。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"path5",
  "south" : __DIR__"floor",
]));
	set("objects", ([
		__DIR__"npc/feng" : 1,
]));
	set("outdoors", "leigu");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
