// /d/xizang/class/bad/road3.c

inherit ROOM;

void create()
{
	set("short", "石板街");
	set("long", @LONG
这是一条青石板铺成的街道,南北两边各有一家店铺,街道往东延伸出很远,西
边是个转角.四外远处群山环抱,连绵不绝.
LONG
);
	set("exits", ([
		"north" : __DIR__"m_shop",
		"south" : __DIR__"w_shop",
		 "west" : __DIR__"road2",
		 "east" : __DIR__"road4",
	]));
	set("outdoors", "xizang");
        setup();
	replace_program(ROOM);
}
