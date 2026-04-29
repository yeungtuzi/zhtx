// Room: /city/dongdajie1.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "东大街");
	set("long", @LONG
	这是一条宽阔的青石板街道，向东西两头延伸。
LONG
	);
        set("outdoors", "city");

	set("exits", ([
		"east" : __DIR__"dongdajie2",
		"west" : __DIR__"guangchang",
		"north" : __DIR__"jiulou1",
		"south" : __DIR__"qianzhuang",
	]));

	setup();
	replace_program(ROOM);
}

