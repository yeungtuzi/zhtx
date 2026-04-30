// swamp1.c
// by meteoric
#include "ansi.h"
inherit "/ldg/std/doom.c";

void create()
{
	set("short", "悬崖");
	set("long", @LONG
你定定神，仔细看去，只见自己正骑在一条突出的石笋之上，这石笋横生在峭壁
之间，粗如巨碗，长不过三尺，在石笋的周围，生满了一片青苔。
　　这真是上不见天，下不着地，前无古人，后无来者的一处险恶之地。
LONG );
	set("no_clean_up", 0);
	setup();
}

void init()
{
	object me;
	me=this_player();
	add_action("do_climb","climb");
	message_vision(YEL"忽然间，觉出向下冲落的身子一顿，双脚之上似是受了重重一击，\n",me);
	message_vision("$N不自主两腿一分，似是骑在了一块冰冷的石笋之上。\n"NOR,me);
	::init();
}

int do_climb(string arg)
{
	// 2026-04-30: unused variable commented out
	// int i,j;
	object obj,ob;
	ob = this_player();
	if( !arg || arg=="" ) return 1;
	switch (arg)
	{
		case "down":
			message_vision("$N慢慢往下爬，终于到达崖底。\n",ob);
			ob->move(__DIR__"trap1");
			break;
		default:
			message_vision("你要干嘛?\n", ob);
	}
	return 1;
}