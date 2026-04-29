// swamp1.c
// by meteoric
#include "ansi.h"
inherit "/ldg/std/dyna_room.c";
void create()
{
	set("short", "坑边");
	set("long", @LONG
你来到一片稍为干燥的草地，前方是一个大坑，你好奇之下走近坑边，
只见峭壁千丈，下面是一道深不见底的绝壑。
LONG );
	
	setup();
}

int valid_leave(object me,string dir)
{
	int dodge_level;
	dodge_level=me->query_skill("dodge");
	if(me->is_fighting()||dodge_level<(60+random(40)))
		{
		me->move(__DIR__"trap/cliff");
		return notify_fail(RED+me->query("name")+"一脚踏空，一阵天旋地转，身子直往下跌，慌乱之中双手乱舞。\n"NOR);
		}
	return 1;
}
