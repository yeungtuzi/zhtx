// /d/xizang/class/budala/iron.c

inherit ROOM;

void create()
{
        set("short", "铁器作");
        set("long", @LONG
这里是布达拉宫的铁器作坊,负责宫中一切铁制器具的制造和修补.每天
从早到晚打铁的声音叮叮当当响个不停,火光照耀四周.
LONG
        );
        set("exits", ([
          "north" : __DIR__"path1",
]));
        set("objects", ([
                __DIR__"npc/smith" : 1,
                ]));
        setup();
        replace_program(ROOM);
}
