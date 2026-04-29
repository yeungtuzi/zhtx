// /d/xizang/class/dazhao/top.c

inherit ROOM;

void create()
{
        set("short", "灵骨塔内");
	set("long", @LONG
你钻进阴暗的灵骨塔,仿佛想从这里得到祖师的启迪.
LONG
        );
        set("exits", ([
		"down" : __DIR__"tower",
	]));
	setup();
//        replace_program(ROOM);
}
