// 幽明山庄
// by yeung. All rights reserved.

#include <ansi.h>

inherit "/std/room/doom.c";

void create()
{
	set("short",CYN"接 天 楼"NOR);
	set("long", @TEXT
	这是接天楼的极顶，在这最接近虚空的地方，一场最绚烂的决战正在进行！
一位是名震天下数十年的魔师，一位是已成为传奇的覆雨剑。他们的决战已经远远
超出了生死胜负，达到了另外一个层面。他们的身形似动实静，举手投足间莫不隐
隐蕴含着天地间的至法。
TEXT
	);

	set("exits", ([ /* sizeof() == 2 */
	  "down": __DIR__"lou8",
          "up": __DIR__"xukong",
	]));

	set("objects", ([
			__DIR__"npc/langfanyun" : 1,
			__DIR__"npc/pangban" : 1,
		])
	);
        set("blocks/up","pang ban");

	
/*
	set("item_desc", ([
		"book": (: look_book :),
	]) );
*/
	setup();
}                               

