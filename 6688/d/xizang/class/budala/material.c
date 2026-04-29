// /d/xizang/class/budala/material.c

inherit ROOM;

void create()
{
        set("short", "材料库");
        set("long", @LONG
这里是存放各种材料的库房,各种东西排列有秩,可以很方便地取放.
LONG
        );
        set("exits", ([
          "east" : __DIR__"path3",
]));
	set("objects", ([__DIR__"obj/junk" : 1+random(10),
	]));
        setup();
        replace_program(ROOM);
}
