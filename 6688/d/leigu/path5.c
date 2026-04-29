// Room: /d/leigu/path5.c

inherit ROOM;

void create()
{
	set("short", "上山小道");
	set("long", @LONG
松林小道继续弯弯曲曲，往南你隐约可以看到松林的尽头。
你不由地加快了脚步。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northdown" : __DIR__"path4",
  "south" : __DIR__"path6",
]));
	set("objects", ([
		__DIR__"npc/gou" : 1,
]));
	set("outdoors", "leigu");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
