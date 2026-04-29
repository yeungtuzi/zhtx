// /d/xizang/class/budala/cook.c

inherit ROOM;

void create()
{
        set("short", "厨房");
        set("long", @LONG
这里是布达拉宫的厨房,供应所有僧人香客的饭食,东边是大饭厅.
LONG
        );
        set("exits", ([
   "east" : __DIR__"eat",
]));
        set("objects", ([
        __DIR__"obj/food" : random(5),
        __DIR__"npc/cooker" : 1,
        ]));
        setup();
        replace_program(ROOM);
}

//int valid_leave
