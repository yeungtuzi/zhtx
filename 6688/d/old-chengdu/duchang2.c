
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", HIR"泥巴拱猪场"NOR);
	set("long", @LONG
	这里有四条走廊通向不同的房间。
--------------------说明----------------------
	现在大概是好了，谢谢disc 的帮助

	         欢迎来测试!

		    yeung
----------------------------------------------
LONG
	);

	set("exits", ([
                "east" : __DIR__"eproom",
                "west" : __DIR__"wproom",
                "south" : __DIR__"sproom",
//                "north" : __DIR__"nproom",
                "down" : __DIR__"duchang",
	]));

	setup();
	replace_program(ROOM);
}

