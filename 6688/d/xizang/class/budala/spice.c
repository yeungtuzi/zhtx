// /d/xizang/class/budala/spice.c

inherit ROOM;

void create()
{
        set("short", "香料库");
        set("long", @LONG
这里是存放各种香料的库房,各种东西排列有秩,可以很方便地取放.
LONG
        );
        set("exits", ([
          "west" : __DIR__"path7",
]));
	set("objects", ([
		__DIR__"obj/junk" : 1+random(10)
	]));
        setup();
        replace_program(ROOM);
}
