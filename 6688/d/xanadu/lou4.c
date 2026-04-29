// 幽明山庄
// by yeung. All rights reserved.

#include <ansi.h>

inherit "/std/room/doom.c";

void create()
{
	set("short",CYN"接 天 楼"NOR);
	set("long", @TEXT
	这是接天楼的第四层，窗外夜幕低垂，星光点点，在这大雪後的纯美世界上
舞跃闪烁，像在为俯仰着道诸般一切的接天楼上正在发生的盛事，奏起了寂静伟大的
乐章。
TEXT
	);

	set("exits", ([ /* sizeof() == 2 */
	  "up" : __DIR__"lou5",
	  "down": __DIR__"lou3",
	]));

	set("objects", ([
			__DIR__"npc/liezhenbei" : 1,
		])
	);

	set("blocks/up","lie zhenbei");
	
/*
	set("item_desc", ([
		"book": (: look_book :),
	]) );
*/
	setup();
}                               

