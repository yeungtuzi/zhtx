// /d/xizang/class/budala/path4.c

inherit ROOM;

void create()
{
        set("short", "甬道");
        set("long", @LONG
这里是布达拉宫前院东边的甬道,北边是茶室,南边是茶工作坊.
LONG
        );
        set("exits", ([
          "south" : __DIR__"teahouse",
          "north" : __DIR__"drink",
           "east" : __DIR__"path5",
           "west" : __DIR__"fyard1",
]));
        set("outdoors", "xizang");
        setup();
        replace_program(ROOM);
}
