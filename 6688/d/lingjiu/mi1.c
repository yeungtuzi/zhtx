// Room: /d/lingjiu/mi1.c

inherit ROOM;

void create()
{
	set("short", "密室");
	set("long", @LONG
你看到一条用青石板铺成的小路，两边的墙壁皆是花岗岩所筑。
墙上每隔十几步就挂着一盏油灯，用来照亮密室。北边你看到了
一个石窟。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"mi0",
  "north" : __DIR__"mi2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
