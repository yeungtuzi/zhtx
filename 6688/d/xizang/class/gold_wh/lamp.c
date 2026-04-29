// /d/xizang/class/gold_wh/lamp.c

inherit ROOM;

void create()
{
        set("short", "明灯室");
	set("long", @LONG
海灯长明,光照宇宙,弘扬佛法,普渡四方
LONG
        );
	set("exits", ([
		"north" : __DIR__"tyard",
]));
	set("objects", ([
                __DIR__"obj/lamp" : 1,
		]));
        setup();
        replace_program(ROOM);
}
