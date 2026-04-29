// /d/xizang/class/gold_wh/flat.c

inherit ROOM;

void create()
{
        set("short", "后山小平台");
        set("long", @LONG
这里是札什伦布寺南阁后的一个小平台.西边是一大片草坪.南边是演武厅高
大的房顶.
LONG
        );
        set("exits", ([
		"east" : __DIR__"south1",
	      	"west" : __DIR__"grass",
]));
	set("outdoors", "xizang");
        setup();
	replace_program(ROOM);
}
