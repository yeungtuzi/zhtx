// /d/xizang/class/budala/path2.c

inherit ROOM;

void create()
{
        set("short", "甬道");
        set("long", @LONG
这里是布达拉宫前院西边的甬道,南边是木器作坊.
LONG
        );
        set("exits", ([
          "south" : __DIR__"wood",
           "east" : __DIR__"path1",
           "west" : __DIR__"path3",
]));
        set("outdoors", "xizang");
        setup();
        replace_program(ROOM);
}
