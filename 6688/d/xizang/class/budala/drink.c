// /d/xizang/class/budala/drink.c

inherit ROOM;

void create()
{
        set("short", "茶室");
        set("long", @LONG
这里是布达拉宫的茶室,供应所有僧人香客的酥油茶.
LONG
        );
        set("exits", ([
   "west" : __DIR__"fyard2",
  "south" : __DIR__"path4",
]));
        set("objects", ([
        __DIR__"obj/tea" : random(5),
        ]));
        setup();
        replace_program(ROOM);
}

//int valid_leave
