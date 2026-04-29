// Room: /d/snow/sroad1.c

inherit ROOM;

void create()
{
	set("short", "雪亭镇街口");
	set("long", @LONG
这里是雪亭镇的街口，往北是一个热闹的广场，南边是条小路通往
一座林子，东边则有一条小径沿著山腰通往山上，往西是一条比较窄的
街道，参差不齐的瓦屋之间传来几声犬吠。从这里向东南走就是进出关
的驿道了。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"sroad2",
  "north" : __DIR__"square",
  "southeast" : "/d/road/rshgtoft0",
  "south" : "/d/oldpine/npath1",
  "east" : __DIR__"eroad1",
]));
	set("outdoors", "snow");
	set("objects",([
		"/class/gaibang/li-sh.c":1,
	]));
	setup();
	replace_program(ROOM);
}
