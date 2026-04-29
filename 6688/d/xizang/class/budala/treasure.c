// /d/xizang/class/budala/treasure.c

inherit ROOM;

void create()
{
        set("short", "藏宝殿");
	set("long", @LONG
这里是布达拉宫藏宝殿,保存着藏边府多年来收集到的奇珍异宝(trasures).
LONG
        );
	set("item_desc", ([
	"treasures" : "这些宝物闪闪发光,让你看得眼花缭乱,不忍离去.\n"
]));
        set("exits", ([
         "south" : __DIR__"west2",
]));
	set("objects", ([
		__DIR__"obj/bottle" : 1,
	]));
        setup();
        replace_program(ROOM);
}
