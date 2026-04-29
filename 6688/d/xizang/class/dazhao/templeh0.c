// /d/xizang/templeh0.c

inherit ROOM;

void create()
{
        set("short", "厨房");
        set("long", @LONG
这里是大招寺的厨房,供应本寺弟子和客人的膳食.
LONG
        );
        set("exits", ([
   "south" : __DIR__"templeyard",
]));
        set("objects", ([
        __DIR__"obj/food" : random(5),
        ]));
        setup();
        replace_program(ROOM);
}

//int valid_leave
