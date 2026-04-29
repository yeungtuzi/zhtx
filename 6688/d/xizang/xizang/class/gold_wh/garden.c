// /d/xizang/class/gold_wh/garden.c

inherit ROOM;

void create()
{
        set("short", "菜园");
        set("long", @LONG
这里是是一大片菜园,种植着翠绿的蔬菜,西边是厨房,东边是札什伦布寺的后院.
LONG
        );
        set("exits", ([
		 "east" : __DIR__"cook",
		 "west" : __DIR__"backyard",
]));
	set("objects", ([
		OBJ_DIR"example/vegetable" : random(6),
	]));
	set("outdoors", "xizang");
        setup();
	replace_program(ROOM);
}
