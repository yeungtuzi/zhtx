//darkwood12.c
//by zephyr

#include "ansi.h"

inherit "/u/z/zephyr/sunflower/sfroom";

void create()
{
	set("short", "暗黑森林");
	set("long", BLK@LONG
你走在寂静的森林深处，刚才诡异的音乐声和令人窒息的空气
好像都消失了，正是休息的好所在。你不禁长长的出了一口气，四
处打量了一下，在一棵古树旁边有块白色的石头，刚好可以坐下来
休息（sit)一下。
LONG NOR);

		set("objects", ([
		__DIR__"npc/xiyangwushi4.c" : 1,
		__DIR__"npc/xiyangwushi5.c" : 1,
		__DIR__"npc/xiyangwushi6.c" : 1,


	]));


	set("exits", ([
		"west" : __DIR__"darkwood5",
		"southeast" : __DIR__"darkwood13",

	])); 

	
	setup();

}
