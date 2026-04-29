// /d/xizang/class/budala/canchan.c

inherit ROOM;

void create()
{
        set("short", "参禅室");
        set("long", @LONG
这里是高僧打坐的房间,在这一片静谧中可以领悟高深的佛法.到这里来请保
持安静,切勿喧哗!
LONG
        );
        set("exits", ([
           "east" : __DIR__"sj1",
]));
	set("objects", ([
		__DIR__"npc/canchan" : 1+random(3),
	]));
        setup();
//        replace_program(ROOM);
}
//add lingwu here, for zang-buddhi only:ppp

void init()
{
//	add_action("do_lingwu", "lingwu");
}

int do_lingwu(string str)
{
	if (!str || str=="") str="zang-buddhi";
	if (str!="zang-buddhi") return notify_fail("这里只能领悟佛法.\n");
	this_player()->improve_skill("zang-buddhi",1+random(100));
	return 1;
}
