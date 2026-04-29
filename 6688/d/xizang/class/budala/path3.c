// /d/xizang/class/budala/path3.c

inherit ROOM;

void create()
{
        set("short", "甬道");
        set("long", @LONG
这里是布达拉宫前院西边的甬道,南边是金器作坊,西边是材料库房,北边
是工匠杂役的住所.
LONG
        );
        set("exits", ([
          "north" : __DIR__"misc1",
          "south" : __DIR__"gold",
           "east" : __DIR__"path2",
           "west" : __DIR__"material",
]));
        set("outdoors", "xizang");
        setup();
        replace_program(ROOM);
}
