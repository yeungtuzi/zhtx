// enable.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	// 2026-04-30: unused variable commented out
	// mapping map;
	string *types, *skill,  ski;
	// 2026-04-30: unused variable commented out
	// int i, modify;

	seteuid(getuid());

	if( !arg ) {
			return notify_fail("散功不是闹着玩的!。\n");
	}

	if( sscanf(arg, "%s", ski)!=1 )
		return notify_fail("指令格式：sangong [<技能种类>]\n");

	if( ski!="force" ) {
		return notify_fail("你要散去什么功力？");
	}
	if ( me->query("max_force") > 10 ) {

		return notify_fail("你的功力已经相当深厚，如果散功会元气大伤！\n");
	}

	me->set("max_force",0);
	me->set("force_type",0);
	write("你决定放弃现在的内功。\n");
	return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : sangong [<技能种类>]

散去全身功力。这个命令只有在功力不深厚时才能使用。
如sangong force 当你的内力值小于10时将把你的所有内力放弃掉。
这样你可以重新学习另一类型的内功。
 
HELP
        );
        return 1;
}
