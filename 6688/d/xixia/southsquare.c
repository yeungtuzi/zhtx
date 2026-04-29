// Room: /d/xixia/southsquare.c

inherit ROOM;

void create()
{
	set("short", "南门广场");
	set("long", @LONG
这里是一个方圆近十余丈的广场，四面八方的街道汇聚于此，使得
这里车水马龙，好不热闹。广场的东北角围着一群人，都瞪圆着双眼，
侧着耳朵，仔细一瞧，原来是有个小姑娘在说书，吸引了大批听众。
LONG);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"southstreet4",
  "west" : __DIR__"southstreet7",
  "south" : __DIR__"southstreet1",
  "north" : __DIR__"southstreet2",
]));

	set("objects", ([
		"/obj/npc/lrio": 1,
	]));
	set("outdoors", "xixia");

	setup();
	replace_program(ROOM);
}
