// /d/xizang/templeh3.c

inherit ROOM;

void create()
{
        set("short", "禅房");
        set("long", @LONG
这里是大招寺内的一间禅房.
LONG
        );
        set("exits", ([
  "north" : __DIR__"bigyard",
]));
	set("objects", ([
		__DIR__"npc/lingkong" : 1,
	]));
        setup();
        replace_program(ROOM);
}

//int valid_leave
