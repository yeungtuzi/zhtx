//darkwood14.c
//by zephyr

#include "ansi.h"

inherit "/u/z/zephyr/sunflower/sfroom";

void create()
{
	set("short", "暗黑森林");
	set("long", BLK@LONG
你越行越深，已经看不到来时的路了。周围的树木越来越茂密，枝干也
横行交错，有些枝干甚至斜向地面，与地上的灌木、草丛相互盘错交织，越
来越难于行走了。
LONG NOR);

	set("objects", ([
		__DIR__"npc/xiyangwushi.c" : 1,
		__DIR__"npc/xiyangwushi2.c" : 1,
		__DIR__"npc/xiyangwushi3.c" : 1,


	]));



	set("exits", ([
		"west" : __DIR__"darkwood16",
		"northeast" : __DIR__"darkwood6",

	])); 

	
	setup();

}
