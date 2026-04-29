// /d/xizang/class/budala/watch.c

inherit ROOM;

void create()
{
        set("short", "了望平台");
        set("long", @LONG
这里是布达拉宫前的了望楼.站在这里可以看出很远.
LONG
        );
        set("exits", ([
      "down" : __DIR__"ftower",
]));
        set("outdoors", "xizang");
        set("objects", ([
                __DIR__"npc/bguard" : 2,
                ]));
        setup();
        replace_program(ROOM);
}
