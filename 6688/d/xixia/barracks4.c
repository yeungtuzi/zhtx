// Room: /d/xixia/barracks4.c

inherit ROOM;

void create()
{
	set("short", "前军都督府");
	set("long", @LONG
这里是前军都督府，专门负责前军的招募，训练，调动，作
战等事宜。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"eroad3",
]));

	setup();
	replace_program(ROOM);
}
