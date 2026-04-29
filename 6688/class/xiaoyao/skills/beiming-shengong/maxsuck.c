#include <ansi.h>

int exert(object me, object target)
{
	int sp, dp;
	int my_max, tg_max;

	if( !objectp(target) || target->query("id") == "mu ren" )
		return notify_fail("你要吸取谁的内力？\n");

        my_max = me->query("max_force");
        tg_max = target->query("max_force");

	if ( me->query_temp("sucked") )
		return notify_fail("你刚刚吸取过内力！\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手才能施用北冥神功吸人内力！\n");

	if( (int)me->query_skill("beiming-shengong",1) < 90 )
		return notify_fail("你的北冥神功功力不够，不能吸取对方的内力！\n");

	if( (int)me->query("force",1) < 50 )
		return notify_fail("你的内力不够，不能使用北冥神功。\n");

	if( (int)me->query("sen") < 30 )
		return notify_fail("你无法集中精神。\n");

        if( me->query("max_force")>50*me->query_skill("beiming-shengong",1)/2 
        || me->query("max_force") > 9999)
		return notify_fail("你的北冥神功修为不够，再吸小心走火入魔。\n");

	if( (int)target->query("max_force") < 100 )
		return notify_fail( target->name() +
			"内力涣散，你无法从他体内吸取任何东西！\n");

        if( (int)target->query("max_force") < (int)me->query("max_force")+10 )
		return notify_fail( target->name() +
			"的内功修为远不如你，你无法从他体内吸取内力！\n");

	message_vision(HIR"$N运起北冥神功，要吸$n的内力！\n\n" NOR,
		me, target );

        if ( living(target) ){ 
		if( !target->is_killing(me) ) target->kill_ob(me);
	 }

        sp = me->query_skill("force") + me->query_skill("dodge");
        dp = target->query_skill("force") + target->query_skill("dodge");

	me->set_temp("sucked", 1);		

        if (( random(sp) > random(dp) ) || !living(target) )
	{
		tell_object(me, HIG "你觉得" + target->name() + "的内力自手掌源源不绝地流了进来。\n" NOR);
		tell_object(target, HIR "你觉得自己的内力自手掌源源不绝地飞泄而出。\n" NOR);

                target->add("max_force",  -1*(1+(me->query_skill("beiming-shengong", 1)-90)/5) );
                me->add("max_force",       1*(1+(me->query_skill("beiming-shengong", 1)-90)/5) );
                if(me->query("max_force") > 10000) me->set("max_force", 10000);
                if ( target->query("max_force") <1) target->set("max_force",0);

		if( (int)me->query("potential") - (int)me->query("learned_points") < 90 )
			me->add("potential",  2);
		me->add("combat_exp", 10);

                me->start_busy(7);
                target->start_busy(random(7));
                me->add("force", -50);
		me->receive_damage("sen", 20);

		call_out("del_sucked", 10, me);
	}
	else
	{	
		message_vision(HIY "可是$p看破了$P的企图，机灵地溜了开去。\n" NOR, me, target);
                me->start_busy(7);
		call_out("del_sucked", 20, me);
	}

	return 1;
}

void del_sucked(object me)
{
	if ( me->query_temp("sucked") )
	me->delete_temp("sucked");
}
