// Room: /d/xixia/northstreet5.c

inherit ROOM;

void create()
{
	set("short", "北大街");
	set("long", @LONG
你的脚下是一条宽阔的街道，清一色的白石板铺成，笔直地
向着前方延伸开去，也不知道有多长。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/tubo3" : 2,
]));
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"northsquare",
  "west" : __DIR__"northstreet6",
]));

	setup();
	replace_program(ROOM);
}
