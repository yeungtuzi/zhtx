// /d/xizang/storage.c

inherit ROOM;

void create()
{
        set("short", "货物仓库");
        set("long", @LONG
这里是鹰记商号的货仓,里面堆满了商家交托运送的货物.
LONG
        );
        set("exits", ([
                "east" : __DIR__"shop2",
        ]));
	set("objects", ([
		OBJ_DIR"toy/goods" :random(9),
]));
        setup();
        replace_program(ROOM);
}
