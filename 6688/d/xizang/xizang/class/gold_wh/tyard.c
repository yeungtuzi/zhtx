// /d/xizang/class/gold_wh/tyard.c

inherit ROOM;

void create()
{
        set("short", "塔院");
        set("long", @LONG
这里是札什伦布寺西边的院落,新筑成的高塔就在这里.东边是一条通往中央广
场的石板路,南边是明灯室,北边是守塔人居住的房子.
LONG
        );
        set("exits", ([
		"enter" : __DIR__"tower",
		 "east" : __DIR__"wroad",
		"north" : __DIR__"keeper",
		"south" : __DIR__"lamp",
]));
	set("outdoors", "xizang");
        setup();
	replace_program(ROOM);
}
