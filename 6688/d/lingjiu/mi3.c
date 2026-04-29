// Room: /d/lingjiu/mi3.c

inherit ROOM;

void create()
{
	set("short", "密室");
	set("long", @LONG
你看到一条用青石板铺成的小路，两边的墙壁皆是花岗岩所筑。
墙上每隔十几步就挂着一盏油灯，用来照亮密室。东边你看到了
一个石窟。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "eastup" : __DIR__"mi2",
  "west" : __DIR__"mi4",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
