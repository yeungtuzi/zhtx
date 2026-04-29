// /d/xizang/class/bad/road2.c

inherit ROOM;

void create()
{
	set("short", "石板街");
	set("long", @LONG
这是一条青石板铺成的街道,北边有块凸起的山岩(rock),南边似乎是家店铺,街
道往东西两边延伸.四外远处群山环抱,连绵不绝.
LONG
);
	set("item_desc", ([
		"rock" : "这块巨石又高又大,恐怕有几十万斤之重\n",
	]));
	set("exits", ([
		"south" : __DIR__"b_shop",
		 "west" : __DIR__"road1",
		 "east" : __DIR__"road3",
	]));
	set("outdoors", "xizang");
        setup();
	replace_program(ROOM);
}
