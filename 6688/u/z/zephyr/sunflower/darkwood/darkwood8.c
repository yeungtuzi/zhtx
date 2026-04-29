//darkwood8.c
//by zephyr

#include "ansi.h"

inherit "/u/z/zephyr/sunflower/sfroom";

void create()
{
	set("short", "暗黑森林");
	set("long", BLK@LONG
你走在寂静的森林深处，刚才诡异的音乐声和令人窒息的空气
好像都消失了，正是休息的好所在。你不禁长长的出了一口气。可是
…………现在该往哪个方向走呢？你心里一阵迷茫
LONG NOR);

	set("objects", ([
		__DIR__"npc/wangzhongwu.c" : 1,

	]));



	set("exits", ([
		"east" : __DIR__"darkwood22",
		"south" : __DIR__"darkwood7",
		"northwest" : __DIR__"darkwood21",
	])); 

	
	setup();

}
