// Room: /d/lingjiu/room7.c

inherit ROOM;

void create()
{
	set("short", "玄天部总部");
	set("long", @LONG
这里是玄天部的总部，屋里正上方摆着一把太师椅，
两边依次各摆着两把椅子，平时玄天部的首领就在这
里商议大事。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"path4",
]));
	set("objects", ([
		__DIR__"npc/dizi7" : 2,
	]));

	setup();
	replace_program(ROOM);
}
