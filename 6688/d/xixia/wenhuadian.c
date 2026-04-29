// Room: /d/xixia/wenhuadian.c

inherit ROOM;

void create()
{
	set("short", "文华殿");
	set("long", @LONG
这里是皇帝与文学侍从谈论学问的地方。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"taihemen",
]));

	setup();
	replace_program(ROOM);
}
