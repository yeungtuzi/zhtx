// Room: /d/xixia/northstreet4.c

inherit ROOM;

void create()
{
	set("short", "北大街");
	set("long", @LONG
你的脚下是一条宽阔的街道，清一色的白石板铺成，笔直地
向着前方延伸开去，也不知道有多长。
LONG
	);
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"eaststreet7",
  "north" : __DIR__"yamen",
  "west" : __DIR__"northstreet3",
]));

	setup();
	replace_program(ROOM);
}
