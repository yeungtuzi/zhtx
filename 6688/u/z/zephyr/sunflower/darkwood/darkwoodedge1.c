//darkwoodedge1.c
//by zephyr

#include "ansi.h"

inherit "/u/z/zephyr/sunflower/sfroom";

void create()
{
	set("short", "暗黑森林边缘");
	set("long", BLK@LONG

你站在一片奇异的森林边上。森林里乌压压的什么都看不清楚。
偶尔一两声凄厉的鸟叫声从森林深处传出来，你不禁浑身发冷：到
底进不进去呢？但是森林仿佛有魔力一般让你无法拔脚离去，森林
深处隐隐约约闪着的白光，仿佛在吸引你走进去。

LONG NOR);

	set("exits", ([
		"north" : __DIR__"darkwoodedge2",
	])); 

	
	setup();

}
