// /d/xizang/class/budala/wpath3.c

inherit ROOM;

void create()
{
        set("short", "甬道");
        set("long", @LONG
这里是布达拉宫讲经房西边连接两座侧殿的甬道.
LONG
        );
        set("exits", ([
           "east" : __DIR__"west1",
           "west" : __DIR__"west2",
]));
        setup();
        replace_program(ROOM);
}
