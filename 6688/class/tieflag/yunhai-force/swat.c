// 天罡战气

#include <ansi.h>

int exert(object me, object target, int amount)
{       
	int skill,force;  
	skill = me->query_skill("yunhai-force",1);  
	if(skill < 55) return notify_fail("你的云海心法等级不够！\n"); 
	if( target && target != me)
		return notify_fail("你只能对自己使用天罡战气。\n");
        if( (int)me->query("force") < 400 )
                return notify_fail("你的真气不够。\n");
        message_vision(
                HIY "$N运起天罡战气，全身骨节不绝地发出一阵阵噼啪轻响，四肢百骸顿时充满了力量！\n" NOR,me);
        force=me->query_skill("force")/2;
        me->set("force_factor",force+ (int)(force*force*force/30000));
	//最大情况下可以额外增加 force_factor 112
	me->add("force",-200);
        if( me->is_fighting() )
		me->start_busy(2);
        return 1;
}
