//生死符 

#include <ansi.h>

int update_condition(object me, int duration)
{		
	int i, j, k = 1;

        if( duration < 1 )	 duration = 81 * 60;	

	i = duration / 60; i = 81 - i; j = duration % 60;
	if( j == 0 ){
		tell_object(me, HIG "你体内的" HIR "生死符" HIG "发作了！\n" NOR );
        	message_vision(HIR"$N忽然痛苦地在地上打起滚来，惨叫连天。\n"NOR,me);  
		if( me->query_condition("relieve_sheng_si") )
			k = 2;
                me->receive_wound("kee", 20*i/k);
                me->receive_damage("kee", 40*i/k);
                me->receive_wound("gin",100);
                me->receive_wound("sen",100);
        	me->save();
	}
	me->apply_condition("sheng_si", duration - 1);
	return 1;
}
