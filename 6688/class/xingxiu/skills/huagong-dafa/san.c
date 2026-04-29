#include <ansi.h>

int exert(object me, object target)
{
	int sp, dp;

	if( !objectp(target) || target->query("id") == "mu ren" )
		return notify_fail("你要化谁的内力？\n");

	if ( me->query_temp("sucked") )
		return notify_fail("你刚刚化过内力！\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手才能施用化功大法化人内力！\n");

	if( (int)me->query_skill("huagong-dafa",1) < 60 )
		return notify_fail("你的化功大法功力不够，不能化掉对方的内力！�\n");

	if( (int)me->query("force",1) < 20 )
		return notify_fail("你的内力不够，不能使用化功大法。\n");

	if( (int)me->query("sen") < 30 )
		return notify_fail("你无法集中精神。\n");

	if( (int)target->query("max_force") <= 0 )
		return notify_fail( target->name() + "没有任何内力！\n");

        if( (int)target->query("force") < 60 )
		return notify_fail( target->name() +
			"已经内力涣散，你已经无法从他体内化掉任何内力了！\n");

	message_vision(HIR"$N施展化功大法，要化$n的内力！\n\n"NOR, me, target);

        if ( living(target) ){ 
		if( !target->is_killing(me) ) target->kill_ob(me); 
		me->fight_ob(target);
	}

        sp = me->query_skill("force") + me->query_skill("dodge");
        dp = target->query_skill("force") + target->query_skill("dodge");

	me->set_temp("sucked", 1);		

        if (( random(sp) > random(dp) ) || !living(target) )
	{
		tell_object(me, HIR"你觉得" + target->name() + "的内力自手掌源源不绝地流了出去。\n" NOR);
		tell_object(target, HIR"你觉得自己的内力自手掌源源不绝地飞泻而出。\n" NOR);

		target->add("force", -1*((int)me->query_skill("huagong-dafa", 1) + target->query("force_factor")) );
            if ( target->query("force") <1 ) target->set("force",0);
		if( me->query("force") > 2 * me->query("max_force") )
			me->set("force", 2 * me->query("max_force"));

		if( target->query("combat_exp") > me->query("combat_exp") ) {		
			if( (int)me->query("potential") - (int)me->query("learned_points") < 100 )
				me->add("potential", 1);
			me->add("combat_exp", 1);
		}

                me->start_busy(4);
		target->start_busy(random(4));
                me->add("force", -10);
		me->receive_damage("sen", 10);

		call_out("del_sucked", 2, me);
	}
	else
	{	
		message_vision(HIY "可是$p看破了$P的企图，机灵地闪了开去。\n" NOR, me, target);
		me->start_busy(4);
		call_out("del_sucked", 4, me);
	}

	return 1;
}

void del_sucked(object me)
{
	if ( me->query_temp("sucked") )
	me->delete_temp("sucked");
}
