// /d/xizang/class/budala/wpath1.c

inherit ROOM;

void create()
{
        set("short", "甬道");
        set("long", @LONG
这里是布达拉宫前殿西边的甬道,通往僧人诵经参禅的房间.在这里你就
可以听到低沉舒缓的诵经声.
LONG
        );
        set("exits", ([
           "east" : __DIR__"fhall",
           "west" : __DIR__"sj1",
]));
        setup();
        replace_program(ROOM);
}
