// /d/xizang/class/bad/w_shop.c

inherit ROOM;

void create()
{
	set("short", "酒铺");
	set("long", @LONG
这里是一家酒铺,除了卖酒菜以外,后院也可供住宿,不过敢住在这里的人也实在
没有几个.
LONG
);
	set("exits", ([
		"north" : __DIR__"road3",
		"south" : __DIR__"shopback",
		 "east" : __DIR__"road5",
	]));
	set("objects", ([
		__DIR__"npc/yak" : 1,
	]) );
	setup();
	replace_program(ROOM);
}
