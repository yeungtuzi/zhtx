// /d/xizang/class/gold_wh/watch.c

inherit ROOM;

void create()
{
        set("short", "平台");
        set("long", @LONG
这里是札什伦布寺后殿东边的平台,站在这里,可以看出很远.
LONG
        );
        set("exits", ([
		"west" : __DIR__"backe",
]));
	set("outdoors", "xizang");
        setup();
	replace_program(ROOM);
}
