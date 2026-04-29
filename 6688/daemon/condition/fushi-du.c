// fushi-du.c

#include <ansi.h>

int update_condition(object me, int duration)
{       if ( duration < 0 ) return 0;
        me->receive_wound("sen",50+random(50));
        me->receive_wound("gin",50+random(50));
        me->receive_wound("kee",me->query("max_kee")/20);
	me->apply_condition("fushi-du", duration - 1);
        me->save();
	tell_object(me, HIB "你中的腐尸毒发作了！\n" NOR );
        message_vision(HIB"$N身子晃了两晃，脸色呈紫黑之色！\n"NOR,me);  
	me->start_busy(1);
	return 1;
}
