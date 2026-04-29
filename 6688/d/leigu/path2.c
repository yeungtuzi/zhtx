// Room: /d/leigu/path2.c

inherit ROOM;

void create()
{
	set("short", "上山小径");
	set("long", @LONG
山路到达此处，却向北一拐，盘旋而上。这时你整个人已经完全淹没
在竹林之中，耳边竹林哗啦啦之声不禁使你想起了当年岳飞巧计退敌
的情景。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"path3",
  "westdown" : __DIR__"path1",
]));
	set("objects", ([
		__DIR__"npc/kang" : 1,
]));
	set("no_clean_up", 0);
	set("outdoors", "leigu");

	setup();
	replace_program(ROOM);
}
