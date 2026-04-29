//darkwoodedge2.c
//by zephyr

#include "ansi.h"

inherit "/u/z/zephyr/sunflower/sfroom";

void create()
{
	set("short", "暗黑森林边缘");
	set("long", BLK@LONG
踏进森林，天色忽然暗了下来，你不禁握住了腰间的剑柄。
你抬头望去，只能看见一小块天空，周围全都是参天大树。四周
忽然什么声音都没有了，刚才听到的鸟叫声也消失了，是不是有
什么东西知道你来了，正在里面等着你呢？
LONG NOR);

	set("exits", ([
		"south" : __DIR__"darkwoodedge1",
		"north" : __DIR__"darkwoodedge3",
	])); 

	
	setup();

}
