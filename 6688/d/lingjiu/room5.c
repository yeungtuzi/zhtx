// Room: /d/lingjiu/room5.c

inherit ROOM;

void create()
{
	set("short", "成天部总部");
	set("long", @LONG
这里是成天部的总部，屋里正上方摆着一把太师椅，
两边依次各摆着两把椅子，平时成天部的首领就在这
里商议大事。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"path3",
]));
	set("objects", ([
		__DIR__"npc/dizi5" : 2,
		__DIR__"npc/cheng" : 1,
	]));

	setup();
	replace_program(ROOM);
}
