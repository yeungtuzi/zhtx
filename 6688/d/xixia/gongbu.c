// Room: /d/xixia/gongbu.c

inherit ROOM;

void create()
{
	set("short", "工部");
	set("long", @LONG
这里是工部，专门负责全国各地的各项工程、屯田、水利、交通等政令。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"eroad1",
]));

	setup();
	replace_program(ROOM);
}
