//darkwood6.c
//by zephyr

#include "ansi.h"

inherit "/u/z/zephyr/sunflower/sfroom";

void create()
{
	set("short", "暗黑森林");
	set("long", BLK@LONG
你开始后悔冒失的闯进这片恐怖的森林了，周围仿佛
有无数双眼睛在盯着你。周围的树木诡异无比，树枝扭曲，
相互交缠，就像暗夜里的幽灵。

LONG NOR);
	set("objects", ([
		__DIR__"npc/wuji.c" : 1,

	]));



	set("exits", ([
		"north" : __DIR__"darkwood4",
		"southeast" : __DIR__"darkwood15",
		"southwest" : __DIR__"darkwood14",
	])); 

	
	setup();

}
