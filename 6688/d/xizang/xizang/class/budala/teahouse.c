// /d/xizang/class/budala/teahouse.c

inherit ROOM;

void create()
{
        set("short", "茶工房");
        set("long", @LONG
这里是布达拉宫的茶工作坊,负责加工宫中饮用的酥油茶.
LONG
        );
        set("exits", ([
          "north" : __DIR__"path4",
]));
        set("objects", ([
                __DIR__"npc/chashi" : 1,
                ]));
        setup();
        replace_program(ROOM);
}
