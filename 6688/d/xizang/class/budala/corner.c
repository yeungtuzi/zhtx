// /d/xizang/class/budala/corner.c

inherit ROOM;

void create()
{
        set("short", "转角路");
        set("long", @LONG
这是宫前街的拐弯,西边是拉萨驿,北边山上就是布达拉宫辉煌的建筑群.
LONG
        );
        set("exits", ([
        "east" : __DIR__"uproad1",
        "west" : __DIR__"station",
       "north" : __DIR__"stonerd",
]));
	set("objects", ([
		__DIR__"npc/xiangke" : 1+random(3),
	]));
        set("outdoors", "xizang");
        setup();
        replace_program(ROOM);
}
