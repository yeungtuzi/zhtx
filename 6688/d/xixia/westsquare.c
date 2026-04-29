// Room: /d/xixia/westsquare.c

inherit ROOM;

void create()
{
	set("short", "西门广场");
	set("long", @LONG
这里是城西各大街道的交汇之处，整个广场方圆十余丈，清
一色的白石板铺成。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"weststreet5",
  "south" : __DIR__"weststreet2",
  "west" : __DIR__"weststreet1",
]));

	setup();
	replace_program(ROOM);
}
