// /d/xizang/class/bad/b_shop.c

inherit ROOM;

void create()
{
	set("short", "黑店");
	set("long", @LONG
这里看起来象是个杂货店,不过既在恶人谷中,当然必是一家黑店了
LONG
);
	set("exits", ([
		"north" : __DIR__"road2",
	]));
	set("objects", ([
		__DIR__"npc/kouga" : 1,
	]) );
	setup();
	replace_program(ROOM);
}
