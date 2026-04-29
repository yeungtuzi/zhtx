// /d/xizang/class/budala/wood.c

inherit ROOM;

void create()
{
        set("short", "木器作");
        set("long", @LONG
这里是布达拉宫的木器作坊,负责宫中一切木制器具的制造和修补.
LONG
        );
        set("exits", ([
          "north" : __DIR__"path2",
]));
        set("objects", ([
                __DIR__"npc/mujiang" : 1,
                ]));
        setup();
        replace_program(ROOM);
}
