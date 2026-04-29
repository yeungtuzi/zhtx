// /d/xizang/class/gold_wh/cjgup.c

inherit ROOM;

void create()
{
        set("short", "藏经阁二层");
        set("long", @LONG
这里是札什伦布寺的藏经阁,存放了很多佛教经典.
LONG
        );
        set("exits", ([
		"down" : __DIR__"cangjing",
]));
	setup();
	replace_program(ROOM);
}
