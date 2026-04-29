// Room: /d/xixia/southstreet1.c

inherit ROOM;

void create()
{
	set("short", "南大街");
	set("long", @LONG
一条宽阔的大街道，街道全部用白石板铺成，甚是干净。往南就是
南城门，从那里可以出城，往北你看到了络绎不绝的人群，那里正是城
南的中心地带。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"southgate",
  "north" : __DIR__"southsquare",
]));

	setup();
	replace_program(ROOM);
}
