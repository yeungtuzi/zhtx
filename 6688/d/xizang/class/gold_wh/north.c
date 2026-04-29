// /d/xizang/class/gold_wh/north.c

inherit ROOM;

void create()
{
        set("short", "北殿");
        set("long", @LONG
这里是札什伦布寺的北殿,顶上有一个阁楼,南边是通往高塔的石板路.
LONG
        );
        set("exits", ([
		"south" : __DIR__"wroad",
	      	   "up" : __DIR__"north1",
]));
        setup();
	replace_program(ROOM);
}
