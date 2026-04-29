// /d/xizang/class/budala/epath2.c

inherit ROOM;

void create()
{
        set("short", "甬道");
        set("long", @LONG
这里是布达拉宫断事司东边的甬道,通往明灯室.
LONG
        );
        set("exits", ([
           "west" : __DIR__"duan",
           "east" : __DIR__"lamp2",
]));
        setup();
        replace_program(ROOM);
}
