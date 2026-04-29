// /d/xizang/class/gold_wh/wroad.c

inherit ROOM;

void create()
{
        set("short", "石板路");
        set("long", @LONG
这里是札什伦布寺中央广场西边的一条石板路,通往高塔.南北各有一座带阁楼
的殿堂.
LONG
        );
        set("exits", ([
		"westup" : __DIR__"tyard",
		  "east" : __DIR__"pathw",
		 "north" : __DIR__"north",
		 "south" : __DIR__"south",
]));
	set("outdoors", "xizang");
        setup();
	replace_program(ROOM);
}
