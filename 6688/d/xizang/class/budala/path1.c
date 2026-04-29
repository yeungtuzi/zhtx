// /d/xizang/class/budala/path1.c

inherit ROOM;

void create()
{
        set("short", "甬道");
        set("long", @LONG
这里是布达拉宫前院西边的甬道,北边是高大的饭厅,南边是铁器作坊.
LONG
        );
        set("exits", ([
          "south" : __DIR__"iron",
          "north" : __DIR__"eat",
           "east" : __DIR__"fyard1",
           "west" : __DIR__"path2",
]));
        set("outdoors", "xizang");
        setup();
        replace_program(ROOM);
}
