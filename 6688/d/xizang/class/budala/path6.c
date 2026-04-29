// /d/xizang/class/budala/path6.c

inherit ROOM;

void create()
{
        set("short", "甬道");
        set("long", @LONG
这里是布达拉宫前院东边的甬道,南边是石匠作坊.
LONG
        );
        set("exits", ([
          "south" : __DIR__"stone",
           "east" : __DIR__"path7",
           "west" : __DIR__"path5",
]));
        set("outdoors", "xizang");
        setup();
        replace_program(ROOM);
}
