// /d/xizang/class/gold_wh/north1.c

inherit ROOM;

void create()
{
        set("short", "北阁");
        set("long", @LONG
这里是札什伦布寺北殿顶上的阁楼.
LONG
        );
        set("exits", ([
	      	"down" : __DIR__"south",
]));
	set("objects", ([
		__DIR__"npc/huodu" :1 
	]));
        setup();
	replace_program(ROOM);
}
