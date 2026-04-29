// 幽明山庄
// by yeung. All rights reserved.

#include <ansi.h>

inherit "/std/room/doom.c";

void create()
{
	set("short",CYN"接 天 楼"NOR);
	set("long", @TEXT
	这是接天楼的第六层，夜风袭人，在这琼楼玉宇之上，便是内功深厚之人，
也不免有些高处不胜寒之感。
TEXT
	);

	set("exits", ([ /* sizeof() == 2 */
	  "up" : __DIR__"lou7",
	  "down": __DIR__"lou5",
	]));

	set("objects", ([
			__DIR__"npc/fenghan" : 1,
		])
	);

	set("blocks/up","feng han");
	
/*
	set("item_desc", ([
		"book": (: look_book :),
	]) );
*/
	setup();
}                               

