// Room: /d/xixia/southstreet4.c

inherit ROOM;

void create()
{
	set("short", "南大街");
	set("long", @LONG
你看到一条白石板铺成的街道笔直地向东西方向延伸了开去，也
不知道有多长。西面是南门广场，北边你看到了一个小客栈，门口挂
着的灯笼上写着“高升客栈”四个字。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/traveler" : 1,
]));
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"southstreet5",
  "north" : __DIR__"hotel",
  "west" : __DIR__"southsquare",
]));

	setup();
	replace_program(ROOM);
}
