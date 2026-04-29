// /d/xizang/class/budala/storage1.c

inherit ROOM;

void create()
{
        set("short", "藏经室");
        set("long", @LONG
这里保存着布达拉宫收藏的各种佛经,到这里来请保持安静,切勿喧哗!
LONG
        );
        set("exits", ([
          "north" : __DIR__"storage2",
	   "west" : __DIR__"sj2",
]));
        set("objects", ([
                __DIR__"obj/book" : random(5),
		]));
        setup();
        replace_program(ROOM);
}
