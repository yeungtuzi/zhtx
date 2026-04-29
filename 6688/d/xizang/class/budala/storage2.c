// /d/xizang/class/budala/storage2.c

inherit ROOM;

void create()
{
        set("short", "藏经室");
        set("long", @LONG
这里保存着布达拉宫收藏的各种佛经,到这里来请保持安静,切勿喧哗!
LONG
        );
        set("exits", ([
          "south" : __DIR__"storage1",
	   "west" : __DIR__"copyroom",
]));
        set("objects", ([
                __DIR__"obj/a_book" : random(5),
		]));
        setup();
        replace_program(ROOM);
}
