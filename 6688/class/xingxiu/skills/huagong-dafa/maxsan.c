#include <ansi.h>

int exert(object me, object target)
{
	int sp, dp;
	int my_max, tg_max;

        if( !me->is_fighting() )
                return notify_fail("化工大法只能在战斗中使用。\n");
 
        if( (int)me->query("force") < 50 )
                return notify_fail("你的内力不够。\n");
  
        if( !target || target==me )
                target = me->select_opponent();
	if( !target )
		return notify_fail("你要化谁的内力？\n");

if( !me->is_killing(target))
return notify_fail("大家只是比武较技,何必下杀手");

        my_max = me->query("max_force");
        tg_max = target->query("max_force");

	if ( me->query_temp("sucked") )
		return notify_fail("你刚刚使用过化功大法！\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手才能施用化功大法化人内力！\n");

	if( (int)me->query_skill("huagong-dafa",1) < 90 )
		return notify_fail("你的化功大法功力不够，不能吸取化别人的内力！\n");

	if( (int)me->query("force",1) < 20 )
		return notify_fail("你的内力不够，不能使用化功大法。\n");

	if( (int)me->query("sen") < 30 )
		return notify_fail("你无法集中精神。\n");

	if( (int)target->query("max_force") < 100 )
		return notify_fail( target->name() +
			"内力涣散，你无法从他体内化去任何东西！\n");

	message_vision(HIR"$N运起化功大法，要化去$n的内力！\n\n" NOR,
		me, target );

        if ( living(target) ){ 
		if( !target->is_killing(me) ) target->kill_ob(me);
	 }

        sp = me->query_skill("force") + me->query_skill("dodge");
        dp = target->query_skill("force") + target->query_skill("dodge");

	me->set_temp("sucked", 1);		

//        if (( random(sp) > random(dp) ) || !living(target) )
//让无崖子厉害点,提高点命中率,by masterall
        if (( random(sp) > random(dp)/10 ) || !living(target) )
	{
		tell_object(me, HIG "你觉得" + target->name() + "的内力自手掌源源流了出去。\n" NOR);
		tell_object(target, HIR "你觉得自己的内力自手掌源源不绝地飞泄而出。\n" NOR);

                target->add("max_force",  -1*(1+(me->query_skill("huagong-dafa", 1)-90)/5) );
                if ( target->query("max_force") <1) target->set("max_force",0);

		if( (int)me->query("potential") - (int)me->query("learned_points") < 90 )
			me->add("potential",  2);
                me->add("combat_exp", 10);

                me->start_busy(1);
                target->start_busy(random(7));
                me->add("force", -10);
		me->receive_damage("sen", 20);

		call_out("del_sucked", 10, me);
	}
	else
	{	
		message_vision(HIY "可是$p看破了$P的企图，机灵地溜了开去。\n" NOR, me, target);
                me->start_busy(1);
		call_out("del_sucked", 20, me);
	}

	return 1;
}

void del_sucked(object me)
{
	if ( me->query_temp("sucked") )
	me->delete_temp("sucked");
}
