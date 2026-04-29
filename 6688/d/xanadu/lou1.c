// 幽明山庄
// by yeung. All rights reserved.

#include <ansi.h>

inherit "/std/room/doom.c";

void create()
{
	set("short",CYN"接 天 楼"NOR);
	set("long", @TEXT
	这是接天楼的第一层，窗外松林蔽日，使得这里看起来十分的昏暗。
TEXT
	);

	set("exits", ([ /* sizeof() == 2 */
	  "up" : __DIR__"lou2",
	  "out": __DIR__"lou0",
	]));

	set("objects", ([
			__DIR__"npc/tanyingshou" : 1,
		])
	);

	set("blocks/up","tan yingshou");
	
/*
	set("item_desc", ([
		"book": (: look_book :),
	]) );
*/
	setup();
}                               

