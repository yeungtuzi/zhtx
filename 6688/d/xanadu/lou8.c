// 幽明山庄
// by yeung. All rights reserved.

#include <ansi.h>

inherit "/std/room/doom.c";

void create()
{
	set("short",CYN"接 天 楼"NOR);
	set("long", @TEXT
	这是接天楼的第八层，来到了这里，就已经脱离了凡俗尘世，来吧，醉心于这
天地之间最完美无暇的交接吧，让尘世的一切烦恼远离而去吧。此刻，你就如同天地之间
一只沙鸥，心灵自由地盘旋飞翔。
TEXT
	);

	set("exits", ([ /* sizeof() == 2 */
	  "up" : __DIR__"lou9",
	  "down": __DIR__"lou7",
	]));

	set("objects", ([
			__DIR__"npc/liruohai" : 1,
                        "/u/m/masterall/fangyeyu" : 1,
		])
	);                                       
	
        set("blocks/up","fang yeyu");

	
/*
	set("item_desc", ([
		"book": (: look_book :),
	]) );
*/
	setup();
}                               

