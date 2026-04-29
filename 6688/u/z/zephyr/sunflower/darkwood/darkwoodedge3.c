//darkwoodedge3.c
//by zephyr

#include "ansi.h"

inherit "/u/z/zephyr/sunflower/sfroom";

void create()
{
	set("short", "暗黑森林边缘");
	set("long", BLK@LONG
你越行越深，回头已经看不到来路，既然已经进来了，索性就
闯他一闯。想到这里，你心里豪情顿生。似乎忘了前面的危险。
天色越来越暗了。
   前面一片灌木挡住了去路，你不得不转个弯继续向前行进了。

LONG NOR);

	set("exits", ([
		"south" : __DIR__"darkwoodedge2",
		"northeast" : __DIR__"darkwoodedge4",

	])); 

	
	setup();

}
