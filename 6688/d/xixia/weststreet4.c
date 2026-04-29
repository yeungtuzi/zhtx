// Room: /d/xixia/weststreet4.c

inherit ROOM;

void create()
{
	set("short", "西大街");
	set("long", @LONG
你的脚下是一条宽阔的街道，清一色的白石板铺成，笔直地
向着前方延伸开去，也不知道有多长。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"weststreet3",
  "south" : __DIR__"southstreet9",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/tubo3" : 2,
]));
	set("no_clean_up", 0);
	set("outdoors", "xixia");

	setup();
	replace_program(ROOM);
}
