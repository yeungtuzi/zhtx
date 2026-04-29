// Room: /city/beidajie1.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "北大街");
	set("long", @LONG
	你走在一条繁忙的街道上，看着操着南腔北调的人们行色匆匆，许多人
都往南边走去，那里有一个热闹的广场。西边是一家生意兴隆的客栈，来自各地
的人们进进出出，据说也是情人们的幽会地点。东边是一家酒楼，不时有阵阵笑
声传来。
LONG
	);
        set("outdoors", "city");

	set("exits", ([
		"east" : __DIR__"jiulou1",
		"south" : __DIR__"guangchang",
		"west" : __DIR__"kedian",
		"north" : __DIR__"beimen",
	]));
//	set("objects", ([
//		CLASS_D("mingjiao") + "/zhangwuji" : 1,
//	]));

	setup();
	replace_program(ROOM);
}

