// /d/xizang/templeh1.c

inherit ROOM;

void create()
{
        set("short", "禅房");
        set("long", @LONG
这里是大招寺前院的一间禅房,北边是大招寺前院.
LONG
        );
        set("exits", ([
  "north" : __DIR__"templeyard",
]));
	set("objects", ([
		__DIR__"npc/lingbao" : 1,
	]));
        setup();
        replace_program(ROOM);
}

//int valid_leave
