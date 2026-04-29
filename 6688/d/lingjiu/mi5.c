// Room: /d/lingjiu/mi5.c

inherit ROOM;

void create()
{
	set("short", "地道");
	set("long", @LONG
地道曲曲折折，盘旋而下，你感到离入口越来越远了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"mi6",
  "east" : __DIR__"mi4",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
