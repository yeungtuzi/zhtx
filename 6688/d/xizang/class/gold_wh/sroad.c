// /d/xizang/class/gold_wh/sroad.c

inherit ROOM;

void create()
{
        set("short", "石板路");
        set("long", @LONG
这里是札什伦布寺中央广场南边的一条石板路,通往练武场.
LONG
        );
        set("exits", ([
		"north" : __DIR__"paths",
		"south" : __DIR__"sroad1",
]));
	set("outdoors", "xizang");
        setup();
	replace_program(ROOM);
}
