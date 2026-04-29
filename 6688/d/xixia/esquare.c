// Room: /d/xixia/esquare.c

inherit ROOM;

void create()
{
	set("short", "天街");
	set("long", @LONG
这里是宫廷广场，因为连接着南面的六军六部，正好呈“Ｔ”字，
故又名天街。朝廷的许多活动就在这里举行。西边是虎门，东边则是龙
门，往北通向承天门。
LONG
	);
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"longmen",
  "enter" : __DIR__"chengtianmen",
  "south" : __DIR__"eroad6",
  "west" : __DIR__"humen",
]));

	setup();
	replace_program(ROOM);
}
