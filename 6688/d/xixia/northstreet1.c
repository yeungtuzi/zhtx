// Room: /d/xixia/northstreet1.c

inherit ROOM;

void create()
{
	set("short", "北大街");
	set("long", @LONG
一条全用白石板铺成的宽敞街道，往北可以出城门，往南是北门
广场。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"northsquare",
  "north" : __DIR__"northgate",
]));

	setup();
	replace_program(ROOM);
}
