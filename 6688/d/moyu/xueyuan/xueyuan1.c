// 雪原
// by meteoric

#include <combat.h>
#include <ansi.h>

inherit "/ldg/std/dyna_room.c";

void create()
{
	set("short", "雪原");
	set("long",@LONG
	这里是一片无垠的雪地，天地之间一片苍茫，两行足迹远远地
延伸出去，似乎永无尽头。此时狂风大作，风中隐隐传来厉啸和“咯咯”
的笑声。
LONG 
	);
	set("exits", ([
	//  "south" : "/d/moyu/entrance",
	]));    
	setup();
}