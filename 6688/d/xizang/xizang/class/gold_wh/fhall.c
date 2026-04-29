// /d/xizang/class/gold_wh/fhall.c

inherit ROOM;

void create()
{
        set("short", "前门殿");
        set("long", @LONG
这里是札什伦布寺的前门殿,它是一系列宫殿建筑的入口.
LONG
        );
        set("exits", ([
		"east" : __DIR__"fyard",
		"west" : __DIR__"path",
]));
        setup();
	replace_program(ROOM);
}
