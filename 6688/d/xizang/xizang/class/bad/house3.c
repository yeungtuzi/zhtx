// /d/xizang/class/bad/house3.c

inherit ROOM;

void create()
{
	set("short", "小屋");
	set("long", @LONG
这里是一座简陋的石砌小屋,没什么陈设.
LONG
);
	set("exits", ([
		"south" : __DIR__"road4",
	]));
	set("objects", ([
		__DIR__"npc/ddang" : 1,
	]) );
	setup();
	replace_program(ROOM);
}
