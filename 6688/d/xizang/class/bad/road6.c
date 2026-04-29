// /d/xizang/class/bad/road6.c

inherit ROOM;

void create()
{
	set("short", "石板街");
	set("long", @LONG
这是一条青石板铺成的街道,北边不远是个转角,西边是街角那家酒铺的后院,东边
有座石砌小屋,南边高耸的大屋便是十大恶人聚会议事的唯我独尊堂
LONG
);
	set("exits", ([
		"north" : __DIR__"road5",
		"south" : __DIR__"hall",
		 "west" : __DIR__"shopback",
		 "east" : __DIR__"house5",
	]));
	set("outdoors", "xizang");
        setup();
	replace_program(ROOM);
}
