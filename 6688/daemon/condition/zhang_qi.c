// shang_qi.c

#include <ansi.h>

int update_condition(object me, int duration)
{
	me->receive_wound("kee", 7);
	me->receive_damage("sen", 10);
	me->apply_condition("zhang_qi", duration - 1);
        if( duration < 1 )
	tell_object(me, HIW "你中的" HIC "瘴气毒" HIW "终于清除了！\n" NOR );
	else
	tell_object(me, HIW "你中的" HIC "瘴气毒" HIW "发作了！\n" NOR );
	if( duration < 1 ) 
		return 0;
	return 1;
}
