// /d/xizang/class/budala/clothes.c

inherit ROOM;

void create()
{
        set("short", "衣袍作");
        set("long", @LONG
这里是布达拉宫的衣袍作坊,负责供应宫中一应人等的服装穿着.
LONG
        );
        set("exits", ([
          "north" : __DIR__"path7",
]));
        set("objects", ([
                __DIR__"npc/tailor" : 1,
                ]));
        setup();
        replace_program(ROOM);
}
