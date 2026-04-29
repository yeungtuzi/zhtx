// /d/xizang/class/gold_wh/cangjing.c

inherit ROOM;

void create()
{
        set("short", "藏经阁");
        set("long", @LONG
这里是札什伦布寺的藏经阁,存放了很多佛教经典.
LONG
        );
        set("exits", ([
		"east" : __DIR__"backw",
		  "up" : __DIR__"cjgup",
]));
	set("objects", ([
		__DIR__"obj/fojing" : random(6),
	]));
	setup();
	replace_program(ROOM);
}
