// /d/xizang/class/budala/eat.c

inherit ROOM;

void create()
{
        set("short", "饭厅");
        set("long", @LONG
这里是布达拉宫的大饭厅,供应所有僧人香客的饭食.
LONG
        );
        set("exits", ([
   "west" : __DIR__"cook",
   "east" : __DIR__"fyard2",
  "south" : __DIR__"path1",
]));
        set("objects", ([
        __DIR__"obj/food" : random(5),
        ]));
        setup();
        replace_program(ROOM);
}

//int valid_leave
