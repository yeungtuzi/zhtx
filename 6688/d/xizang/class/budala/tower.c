// /d/xizang/class/budala/tower.c

#include <obj.h>

inherit ROOM;

void create()
{
        set("short", "塔林");
	set("long", @LONG
这里是布达拉宫后院的塔林,储放着历代达赖喇嘛的灵骨.
LONG
	);
        set("exits", ([
		"up" : __DIR__"top",
	      "east" : __DIR__"byard1",
]));
        set("no_fight", 1);
        set("no_magic", 1);
	set("outdoors", "xizang");
        setup();
        replace_program(ROOM);
}
