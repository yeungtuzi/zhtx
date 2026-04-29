//darkwood2.c
//by zephyr

#include "ansi.h"

inherit "/u/z/zephyr/sunflower/sfroom";

void create()
{
	set("short", "暗黑森林");
	set("long", BLK@LONG
周围开始变得越来越潮湿，越来越闷热。周围的树木仿佛把
空气凝固了，你开始觉得呼吸困难。你发现有些大树身上爬满了
一种奇怪的藤蔓植物，而且被这种植物环绕的大树好像不如其他
的树木那么茂盛，有些树干甚至都有枯萎的迹象了。
周围的空气太黏着了，你觉得越来越不舒服，还是赶快离开
吧！
LONG NOR);

	set("objects", ([
		__DIR__"npc/zhangyuxian.c" : 1,

	]));



	set("exits", ([
		"north" : __DIR__"darkwood1",
		"southeast" : __DIR__"darkwood3",
		"southwest" : __DIR__"darkwood4",

	])); 

	
	setup();

}
