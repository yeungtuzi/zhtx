// /d/xizang/class/gold_wh/grass.c

inherit ROOM;

void create()
{
        set("short", "草坪");
        set("long", @LONG
这里是札什伦布寺后山坡的草坪.南边是大练武场,在这里就可以听见金轮派
弟子们练武时发出的雄壮吼声.
LONG
        );
        set("exits", ([
		   "east" : __DIR__"flat",
	      "southdown" : __DIR__"grass",
]));
	set("outdoors", "xizang");
        setup();
	replace_program(ROOM);
}
