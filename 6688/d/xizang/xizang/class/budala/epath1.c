// /d/xizang/class/budala/epath1.c

inherit ROOM;

void create()
{
        set("short", "甬道");
        set("long", @LONG
这里是布达拉宫前殿东边的甬道,通往僧人诵经参禅的房间.在这里你就
可以听到低沉舒缓的诵经声.
LONG
        );
        set("exits", ([
           "west" : __DIR__"fhall",
	   "east" : __DIR__"sj2",
]));
        setup();
        replace_program(ROOM);
}
