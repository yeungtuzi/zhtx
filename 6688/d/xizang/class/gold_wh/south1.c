// /d/xizang/class/gold_wh/south1.c

inherit ROOM;

void create()
{
        set("short", "南阁");
        set("long", @LONG
这里是札什伦布寺南殿顶上的阁楼,西边有一个小平台.
LONG
        );
        set("exits", ([
		"east" : __DIR__"flat",
	      	"down" : __DIR__"south",
]));
        setup();
	replace_program(ROOM);
}
