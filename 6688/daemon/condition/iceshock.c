// iceshock.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	me->receive_damage("gin", 2*duration);
	me->receive_wound("kee", 5*duration);
	me->receive_damage("sen", 2*duration);
        me->start_busy(random(2));

	me->apply_condition("iceshock", duration - 1);

	tell_object(me, HIB "你中的意寒掌毒发作了！\n" NOR );
	if( duration < 1 ) return 0;

	return CND_CONTINUE;
}
