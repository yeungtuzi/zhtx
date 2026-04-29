// /d/xizang/class/budala/path5.c

inherit ROOM;

void create()
{
        set("short", "甬道");
        set("long", @LONG
这里是布达拉宫前院东边的甬道,南边是漆工作坊.
LONG
        );
        set("exits", ([
          "south" : __DIR__"paint",
           "east" : __DIR__"path6",
           "west" : __DIR__"path4",
]));
        set("outdoors", "xizang");
        setup();
        replace_program(ROOM);
}
