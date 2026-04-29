// /d/xizang/class/budala/epath3.c

inherit ROOM;

void create()
{
        set("short", "甬道");
        set("long", @LONG
这里是布达拉宫讲经房东边连接两座侧殿的甬道.
LONG
        );
        set("exits", ([
           "east" : __DIR__"east2",
           "west" : __DIR__"east1",
]));
        setup();
        replace_program(ROOM);
}
