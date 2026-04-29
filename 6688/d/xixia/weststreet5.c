// Room: /d/xixia/weststreet5.c

inherit ROOM;

void create()
{
	set("short", "西大街");
	set("long", @LONG
你的脚下是一条宽阔的街道，清一色的白石板铺成，笔直地
向着前方延伸开去，也不知道有多长。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"weststreet6",
  "south" : __DIR__"westsquare",
]));

	setup();
	replace_program(ROOM);
}
