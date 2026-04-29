// /d/xizang/class/gold_wh/lecture.c

inherit ROOM;

void create()
{
        set("short", "讲经房");
        set("long", @LONG
这里是札什伦布寺的讲经房,法王不喜讲经,通常都是委托一名弟子在那里代为
宣讲.大多数讲经弟子的解说并不精彩,所以通常也没几个听众.
LONG
        );
        set("exits", ([
		"north" : __DIR__"path",
		 "west" : __DIR__"paths",
]));
	set("objects", ([
		__DIR__"npc/ldizi" : 1,
		__DIR__"npc/xiangke" : random(3),
	]));
        setup();
	replace_program(ROOM);
}
