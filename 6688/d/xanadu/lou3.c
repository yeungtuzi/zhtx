// 幽明山庄
// by yeung. All rights reserved.

#include <ansi.h>

inherit "/std/room/doom.c";

void create()
{
	set("short",CYN"接 天 楼"NOR);
	set("long", @TEXT
	这是接天楼的第三层，渐行渐高，窗外的风景不住变幻。
TEXT
	);

	set("exits", ([ /* sizeof() == 2 */
	  "up" : __DIR__"lou4",
	  "down": __DIR__"lou2",
	]));

	set("objects", ([
			__DIR__"npc/fanliangji" : 1,
		])
	);

	set("blocks/up","fan liangji");
	
/*
	set("item_desc", ([
		"book": (: look_book :),
	]) );
*/
	setup();
}                               

