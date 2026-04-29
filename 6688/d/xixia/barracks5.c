// Room: /d/xixia/barracks5.c

inherit ROOM;

void create()
{
	set("short", "后军都督府");
	set("long", @LONG
这里是后军都督府，专门负责粮草运输、武器装备等事宜。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"eroad2",
]));

	setup();
	replace_program(ROOM);
}
