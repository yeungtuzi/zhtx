// 幽明山庄
// by yeung. All rights reserved.

#include <ansi.h>

inherit "/std/room/doom.c";

void create()
{
	set("short",CYN"接 天 楼"NOR);
	set("long", @TEXT
	这是接天楼的第二层，楼的内壁上全是精美的壁画，可你现在肯定没有
功夫欣赏。。
TEXT
	);

	set("exits", ([ /* sizeof() == 2 */
	  "up" : __DIR__"lou3",
	  "down": __DIR__"lou1",
	]));

	set("objects", ([
			__DIR__"npc/moyixian" : 1,
		])
	);

	set("blocks/up","mo yixian");
	
/*
	set("item_desc", ([
		"book": (: look_book :),
	]) );
*/
	setup();
}                               

