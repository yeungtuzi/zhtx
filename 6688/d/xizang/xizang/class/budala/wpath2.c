// /d/xizang/class/budala/wpath2.c

inherit ROOM;

void create()
{
        set("short", "甬道");
        set("long", @LONG
这里是布达拉宫断事司西边的甬道,通往明灯室.
LONG
        );
        set("exits", ([
           "east" : __DIR__"duan",
           "west" : __DIR__"lamp1",
]));
        setup();
        replace_program(ROOM);
}
