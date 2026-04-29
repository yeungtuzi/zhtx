// Room: /d/lingjiu/road3.c

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
这是一条由青石板铺成的小路。东边是休息室，北边是厨房。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"chufang",
  "south" : __DIR__"rightroad",
  "east" : __DIR__"sleeproom",
  "west" : __DIR__"floor2",
]));
	set("outdoors", "lingjiu");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
