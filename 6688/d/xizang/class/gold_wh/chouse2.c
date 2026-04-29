// /d/xizang/class/gold_wh/chouse2.c

inherit ROOM;

void create()
{
        set("short", "禅房");
        set("long", @LONG
这里是札什伦布寺的后殿东边的禅房.
LONG
        );
        set("exits", ([
		"south" : __DIR__"backe",
]));
	setup();
	replace_program(ROOM);
}
