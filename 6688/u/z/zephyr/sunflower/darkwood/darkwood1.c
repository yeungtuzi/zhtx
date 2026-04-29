//darkwood1.c
//by zephyr

#include "ansi.h"

inherit "/u/z/zephyr/sunflower/sfroom";

void create()
{
	set("short", "暗黑森林");
	set("long", BLK@LONG
抬头看去，已经看不到天空了，唯有折射下来的光线让你能够勉强看清楚周
围的环境。你伸手摸去，地上全是厚厚的腐烂的树枝树叶。
LONG NOR);

	set("objects", ([
		__DIR__"npc/fanglaoda.c" : 1,

	]));



	set("exits", ([
		"east" : __DIR__"darkwood9",
		"south" : __DIR__"darkwood2",
		"northwest" : __DIR__"darkwood7",
	])); 

	setup();

}

