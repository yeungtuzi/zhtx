// Room: /d/xixia/southstreet8.c

inherit ROOM;

void create()
{
	set("short", "南大街");
	set("long", @LONG
你的脚下是一条宽阔的街道，清一色的白石板铺成，笔直地
向着前方延伸开去，也不知道有多长。
LONG
	);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/oldbeggar" : 1,
  __DIR__"npc/beggar" : 1,
]));
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"southstreet7",
  "west" : __DIR__"southstreet9",
]));

	setup();
	replace_program(ROOM);
}
