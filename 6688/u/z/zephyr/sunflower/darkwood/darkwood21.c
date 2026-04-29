//darkwood21.c
//by zephyr

#include "ansi.h"

inherit "/u/z/zephyr/sunflower/sfroom";

void create()
{
	set("short", "暗黑森林");
	set("long", BLK@LONG
这里仿佛已经到了森林的尽头。再往前就找不到路了。这里已经完全见不到天空了。
四处全是黑压压的树木。这里非常非常昏暗，完全靠着从树木缝隙里折射下来的微弱光线，
你才能大致看到周围的状况。

LONG NOR);



		set("objects", ([
		__DIR__"npc/assassin4.c" : 1,
		__DIR__"npc/assassin5.c" : 1,
		__DIR__"npc/assassin6.c" : 1,


	]));


	set("exits", ([
		"southeast" : __DIR__"darkwood8",

	])); 

	
	setup();

}
