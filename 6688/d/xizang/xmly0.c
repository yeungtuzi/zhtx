// /d/xizang/xmly0.c

inherit ROOM;

void create()
{
        set("short", "喜马拉雅山北麓");
        set("long", @LONG
这里是喜马拉雅山北麓,近邻雅鲁藏布江,水草丰美,繁花盛开,气候温暖宜人.
LONG
        );
        set("exits", ([
          "westup" : __DIR__"xmly1",
	"eastdown" : __DIR__"s_bank",
]));
	set("objects", ([
		__DIR__"obj/flower" : random(5)+1,
	]));
	set("outdoors", "xizang");
        setup();
        replace_program(ROOM);
}
