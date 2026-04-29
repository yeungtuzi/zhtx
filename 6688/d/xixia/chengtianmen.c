// Room: /d/xixia/chengtianmen.c

inherit ROOM;

void create()
{
	set("short", "承天门");
	set("long", @LONG
这里气势磅礴，庄严端重，是通向宫内的正门，门前点缀着汉白
玉石桥和华表。皇帝“登基”和“册立”皇后等盛大庆典，就在这里
举行隆重的“颁诏”仪式。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/shiwei2" : 4,
]));
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"esquare",
  "north" : __DIR__"eroad7",
]));

	setup();
	replace_program(ROOM);
}
