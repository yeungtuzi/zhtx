
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "清溪");
	set("long", @LONG
	向南转过一个弯，眼前豁然开朗，一条山涧在面前流过，溪水哗哗流
过，不是溅起簇簇浪花，不远处有一个小小的亭子，亭中一人独自伫立。
LONG
	);
        set("outdoors", "city");

	set("exits", ([
			"southwest" : __DIR__"dongjiao2",
			"north" : __DIR__"lanting",
	]));

	setup();
	replace_program(ROOM);
}

