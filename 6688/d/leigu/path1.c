// Room: /d/leigu/path1.c

inherit ROOM;

void create()
{
	set("short", "山道");
	set("long", @LONG
你看到一片竹林，郁郁葱葱，微风拂过，哗哗作响。竹林中间
开一幽僻小径，通向竹林深处。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "eastup" : __DIR__"path2",
  "west" : __DIR__"path0",
]));
	set("objects", ([
		__DIR__"npc/shi" : 1,
]));

	set("no_clean_up", 0);
	set("outdoors", "leigu");

	setup();
	replace_program(ROOM);
}
