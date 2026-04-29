// /d/xizang/class/dazhao/heaven.c

inherit ROOM;

void create()
{
	set("short","极乐世界");
	set("long",@LONG
这里一片黑暗,你什么也看不到,但是莫名其妙地感觉十分舒服,以至于无论如何
不想再离开了.
LONG
        );
	set("objects", ([
		__DIR__"npc/gelun" : 1,
	]));
        setup();
        replace_program(ROOM);
}
