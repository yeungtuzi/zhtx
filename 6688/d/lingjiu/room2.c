// Room: /d/lingjiu/path0.c

inherit ROOM;

void create()
{
	set("short", "赤天部总部");
	set("long", @LONG
这里是赤天部的总部，屋里正上方摆着一把太师椅，
两边依次各摆着两把椅子，平时赤天部的首领就在这
里商议大事。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"path2",
]));
	set("objects", ([
		__DIR__"npc/dizi2" : 2,
		__DIR__"npc/chi" : 1,
	]));

	setup();
	replace_program(ROOM);
}
