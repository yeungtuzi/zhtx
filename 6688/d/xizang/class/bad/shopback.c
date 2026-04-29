// /d/xizang/class/bad/shopback.c

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
		"north" : __DIR__"w_shop",
		 "east" : __DIR__"road6",
	]));
	set("objects", ([
//                __DIR__"npc/poi" : 1,
	]) );
	setup();
	replace_program(ROOM);
}
