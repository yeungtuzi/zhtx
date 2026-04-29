// /d/xizang/class/budala/lamp2.c

inherit ROOM;

void create()
{
        set("short", "明灯室");
	set("long", @LONG
海灯长明,光照宇宙,弘扬佛法,普渡四方
LONG
        );
	set("exits", ([
		"north" : __DIR__"easthall",
		 "east" : __DIR__"epath2",
]));
	set("objects", ([
                __DIR__"obj/lamp" : 1,
		__DIR__"npc/lguard" : 1
	]));
        setup();
        replace_program(ROOM);
}
