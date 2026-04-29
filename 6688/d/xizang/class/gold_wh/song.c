// /d/xizang/class/gold_wh/song.c

inherit ROOM;

void create()
{
        set("short", "诵经室");
        set("long", @LONG
这里是札什伦布寺的诵经室,几个弟子在这里高声诵读佛经,但是似乎都不怎
么认真,不时有人溜走出去.
LONG
        );
        set("exits", ([
		"north" : __DIR__"pathw",
		 "east" : __DIR__"paths",
]));
	set("objects", ([
		__DIR__"npc/sdizi" : random(3),
	]));
        setup();
	replace_program(ROOM);
}
