// Room: /d/xixia/eaststreet1.c

inherit ROOM;

void create()
{
	set("short", "东大街");
	set("long", @LONG
你的脚下是一条宽阔的街道，清一色的白石板铺成，笔直地
向着前方延伸开去，也不知道有多长。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"eastgate",
  "west" : __DIR__"eastsquare",
]));

	setup();
	replace_program(ROOM);
}
