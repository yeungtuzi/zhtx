// /d/xizang/class/budala/stone.c

inherit ROOM;

void create()
{
        set("short", "石匠房");
        set("long", @LONG
这里是布达拉宫的石匠作坊,负责打造宫中的所需的石像雕刻.
LONG
        );
        set("exits", ([
          "north" : __DIR__"path6",
]));
        set("objects", ([
                __DIR__"npc/shijiang" : 1,
                ]));
        setup();
        replace_program(ROOM);
}
