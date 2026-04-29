// Room: /d/xixia/ebridge.c

inherit ROOM;

void create()
{
	set("short", "金水桥");
	set("long", @LONG
这是一架造型优美的汉白玉石桥，横跨在自西而东蜿蜒而下的
金水河上。站在桥上，三宫六院金碧辉煌、巍峨壮丽的景象尽收眼
里。
LONG
	);
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"taihemen",
  "south" : __DIR__"eroad9",
]));

	setup();
	replace_program(ROOM);
}
