#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object master;

	if(!arg) return notify_fail("help challenge to know its usage.\n");

	if( sscanf(arg, "at %s", arg)==1 )
	{
	        if(!objectp(master = present(arg, environment(me))))
	                return notify_fail("你想向哪位师父代表的门派挑战？\n");
		if(!master->tiaozhan(me)) return notify_fail("这里没有能接受你挑战的人.\n");
		return 1;
	}
		

	if( sscanf(arg, "accept at %s", arg)==1 )
	{
	        if(!objectp(master = present(arg, environment(me))))
	                return notify_fail("你的门派师父在哪里？\n");
		if(!master->yingzhan(me)) return notify_fail("这里没有能接受你应战的人.\n");
		return 1;
	}
	if( sscanf(arg, "halt at %s", arg)==1 )
	{
	        if(!objectp(master = present(arg, environment(me))))
	                return notify_fail("找不到该门派的师父。\n");
		if(!master->surrender(me)) return notify_fail("你并没有参与挑战.\n");
		return 1;
	}

	return notify_fail("help challenge to know its usage.\n");
}

int help(object me)
{
	write(@HELP
指令格式：

challenge at <门派师父> ：        向该门派师父代表的门派挑战。
challenge accept at <门派师父> ： 在门派师父面前代表师门迎战。
challenge halt at <门派师父> ：   在挑战的战斗过程中halt。

这条指令用于门派挑战。

HELP
	);
	return 1;
}
