// Room: /d/road/chengdu.c

inherit ROOM;

void create()
{
	set("short", "成都");
	set("long", @LONG
这里就是蜀中名城成都了。这里向东南可以过长江直达云贵，向西可以过金沙江通向
西藏，向东北则可以过剑门关通往关中,西北方向是通往青城山的路，向西南走可以到达
佛教圣地峨眉山.
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		"northeast" : __DIR__"rjmtocd2",
		"west" : __DIR__"rcdtojs0",
		"southeast" : __DIR__"rcdtodk0",
		"southwest" : __DIR__"rcdtoems0",
		"northwest" : "/d/qingcheng/qchyidao",
]));
	set("objects", ([

		"/class/gaibang/he-bj.c":1,
	]) );

	setup();
	replace_program(ROOM);
}
