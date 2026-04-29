// Room: /d/lingjiu/path0.c

inherit ROOM;

void create()
{
	set("short", "朱天部总部");
	set("long", @LONG
这里是朱天部的总部，屋里正上方摆着一把太师椅，
两边依次各摆着两把椅子，平时朱天部的首领就在这
里商议大事。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"path3",
]));
	set("objects", ([
		__DIR__"npc/dizi4" : 2,
	]));

	setup();
	replace_program(ROOM);
}
