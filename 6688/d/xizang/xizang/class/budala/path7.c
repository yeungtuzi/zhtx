// /d/xizang/class/budala/path7.c

inherit ROOM;

void create()
{
        set("short", "甬道");
        set("long", @LONG
这里是布达拉宫前院东边的甬道,南边是衣袍作坊,北边是工匠杂役的住
处,东边是香料库房.
LONG
        );
        set("exits", ([
          "north" : __DIR__"misc2",
          "south" : __DIR__"clothes",
           "east" : __DIR__"spice",
           "west" : __DIR__"path6",
]));
        set("outdoors", "xizang");
        setup();
        replace_program(ROOM);
}
