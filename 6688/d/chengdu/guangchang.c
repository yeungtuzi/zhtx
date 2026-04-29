// Room: /city/guangchang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "市中心");
	set("long", @LONG
	这里是成都的正中心，首先入目是数之不尽的花灯，有些挂在店铺居所
的宅门外，有些则拿在行人的手上，小孩联群结队的提灯嬉闹，款式应有尽有，
奇巧多姿，辉煌炫目。女孩都打扮得花枝招展，羌族少女的华衣丽服更充满异地
风情，娇笑玩乐声此起彼伏，溢满店铺林立的城门大道。
LONG
	);
        set("no_sleep_room",1);
        set("outdoors", "city");

	set("exits", ([
		"east" : __DIR__"dongdajie1",
		"south" : __DIR__"nandajie1",
		"west" : __DIR__"xidajie1",
		"north" : __DIR__"beidajie1",
	]));

	set("objects", ([
		__DIR__"npc/yeying":1,
	]));

//	set("objects", ([
//      这里放何不净 	__DIR__"obj/fake-zi" : 1,
//	]));

	setup();
}

