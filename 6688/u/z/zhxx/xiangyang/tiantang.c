// Room: /d/xiangyang/hutong11.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
    set("short", "天堂");
    set("long", @LONG
这里是天堂。
LONG );
        set("outdoors", "xiangyang");

    set("exits", ([
//        "east" : __DIR__"jiekou1",
    ]));
    set("objects", ([
        "/u/z/zhxx/xiangyang/b.c" : 1,
    ]));
    setup();
    replace_program(ROOM);
}

