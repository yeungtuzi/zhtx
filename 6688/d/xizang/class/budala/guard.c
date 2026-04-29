// /d/xizang/class/budala/guard.c

inherit ROOM;

void create()
{
        set("short","守卫室");
        set("long", @LONG
这里是布达拉宫的守卫室,西边是暂时羁押擅闯宫门者的牢房.东边是大门.
LONG
        );
        set("exits", ([
           "east" : __DIR__"foregate",
           "west" : __DIR__"prison",
]));
	set("objects", ([
		__DIR__"npc/tiger" : 1,
	]));
        setup();
        replace_program(ROOM);
}
