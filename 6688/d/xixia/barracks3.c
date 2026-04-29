// Room: /d/xixia/barracks3.c

inherit ROOM;

void create()
{
	set("short", "右军都督府");
	set("long", @LONG
这里是右军都督府，专门负责右军的招募，训练，调动，作
战等事宜。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"eroad4",
]));

	setup();
	replace_program(ROOM);
}
