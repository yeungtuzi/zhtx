// Room: /d/xixia/weststreet1.c

inherit ROOM;

void create()
{
	set("short", "西大街");
	set("long", @LONG
一条白石板铺成的宽敞街道，往西可以出城，往东则是城西各大
街道的交汇之处──西门广场。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"westsquare",
  "west" : __DIR__"westgate",
]));

	setup();
	replace_program(ROOM);
}
