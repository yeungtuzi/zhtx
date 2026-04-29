// /d/xizang/class/bad/road1.c

inherit ROOM;

void create()
{
	set("short", "石板街");
	set("long", @LONG
这是一条青石板铺成的街道,两旁是整齐的石砌小屋,东边街道一直延伸出
很远,西边是繁花盛开的谷中平地.四外远处群山环抱,连绵不绝.
LONG
);
	set("exits", ([
		"north" : __DIR__"house1",
		"south" : __DIR__"house2",
		 "west" : __DIR__"enter",
		 "east" : __DIR__"road2",
	]));
	set("outdoors", "xizang");
        setup();
	replace_program(ROOM);
}
