// /d/xizang/class/budala/paint.c

inherit ROOM;

void create()
{
        set("short", "漆工房");
        set("long", @LONG
这里是布达拉宫的漆工作坊,负责为宫中的各种器物上漆涂色,以及绘
制精美的佛像,壁画.
LONG
        );
        set("exits", ([
          "north" : __DIR__"path5",
]));
        set("objects", ([
                __DIR__"npc/painter" : 1,
                ]));
        setup();
        replace_program(ROOM);
}
