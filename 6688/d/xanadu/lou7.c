// 幽明山庄
// by yeung. All rights reserved.

#include <ansi.h>

inherit "/std/room/doom.c";

void create()
{
	set("short",CYN"接 天 楼"NOR);
	set("long", @TEXT
	这是接天楼的第七层，处于此处，真有伸手即可摘下星辰的感觉，你的灵觉
不住地扩大，直至象要和天地融为一体。
TEXT
	);

	set("exits", ([ /* sizeof() == 2 */
	  "up" : __DIR__"lou8",
	  "down": __DIR__"lou6",
	]));

	set("objects", ([
			__DIR__"npc/ganluo" : 1,
		])
	);

	set("blocks/up","gan luo");
	
/*
	set("item_desc", ([
		"book": (: look_book :),
	]) );
*/
	setup();
}                               

