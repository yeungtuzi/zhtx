// /d/xizang/class/bad/house1.c

inherit ROOM;

void create()
{
	set("short", "小屋");
	set("long", @LONG
这里是一座简陋的石砌小屋,没什么陈设.
LONG
);
	set("exits", ([
		"south" : __DIR__"road1",
	]));
	set("objects", ([
		__DIR__"npc/llkkjj" : 1,
	]) );
	setup();
	replace_program(ROOM);
}
