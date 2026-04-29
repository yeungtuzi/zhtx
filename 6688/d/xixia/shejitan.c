// Room: /d/xixia/shejitan.c

inherit ROOM;

void create()
{
	set("short", "社稷坛");
	set("long", @LONG
这里是皇帝祭天的地方。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"eroad7",
]));

	setup();
	replace_program(ROOM);
}
