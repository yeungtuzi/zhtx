// /d/xizang/class/gold_wh/south.c

inherit ROOM;

void create()
{
        set("short", "南殿");
        set("long", @LONG
这里是札什伦布寺的南殿,顶上有一个阁楼,北边是通往高塔的石板路.
LONG
        );
        set("exits", ([
		"north" : __DIR__"wroad",
	      	   "up" : __DIR__"south1",
]));
        setup();
	replace_program(ROOM);
}
