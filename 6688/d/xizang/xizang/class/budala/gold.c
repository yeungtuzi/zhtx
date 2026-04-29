// /d/xizang/class/budala/gold.c

inherit ROOM;

void create()
{
        set("short", "金器作");
        set("long", @LONG
这里是布达拉宫的金器作坊,负责宫中一切金制器具的制造和修补,以及给
各种器具包金或者镀金.
LONG
        );
        set("exits", ([
          "north" : __DIR__"path3",
]));
        set("objects", ([
                __DIR__"npc/jinjiang" : 1,
                ]));
        setup();
        replace_program(ROOM);
}
