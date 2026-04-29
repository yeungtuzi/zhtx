// /d/xizang/class/gold_wh/keeper.c

inherit ROOM;

void create()
{
        set("short", "守塔人屋");
        set("long", @LONG
这是守塔人居住的房子,以青石砌成,除床榻外别无它物.
LONG
        );
        set("exits", ([
		"south" : __DIR__"tyard",
]));
	set("objects", ([
		__DIR__"npc/keeper" : 1,
	]));
        setup();
	replace_program(ROOM);
}
