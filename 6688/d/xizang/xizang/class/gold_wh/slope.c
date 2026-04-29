// /d/xizang/class/gold_wh/slope.c

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "山坡");
        set("long", @LONG
这里是一个长满野草的小山坡,虽然圈在寺院的范围内,但实际上是块荒地.东边是札
什伦布寺的后院,西边是个黑乎乎的洞口,下着铁栅栏门.不知道里面关着什么.
LONG
        );
        set("exits", ([
		 "east" : __DIR__"backyard",
		 "west" : __DIR__"hole",
]));
	set("outdoors", "xizang");
	create_door("west", "铁栅栏门", "east", DOOR_CLOSED);
        setup();
	replace_program(ROOM);
}
