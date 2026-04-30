#include <ansi.h>

inherit SSERVER;

int judge(object me,object victim)
{
	    int level,mp,dp;
        level = me->query_skill("mysterrier",1); //200max
        mp = level*level/2*level; //400万
        dp = victim->query("combat_exp");//368万max
        if( random(mp+dp)>dp )
			return 1;
		else return 0;
}

int perform(object me, object target)
{
        // 2026-04-30: unused variable commented out
        // object soldier;
        string msg;
        int num;

	if( !objectp(target) ) target = me->select_opponent();
        if( !objectp(target) || !me->is_fighting() )
                return notify_fail("「七星追月」只能对战斗对手使用。\n");

	if( me->query_temp("mysterrier") )                 
		return notify_fail("你已经在运功中了。\n");
	
	if( me->query("betrayer") )
		return notify_fail("你不是步玄派正宗弟子，还没学会使用步玄七诀这一式。\n");
                
        if( me->query("force") < 100 ) return notify_fail("你的内力不够，无法使用「七星追月」！\n");
        
        msg = YEL "$N使出步玄七诀第四式「七星追月」，身形化做七道虚影射向$n！\n" NOR;
        me->add("force",-200);
            me->set_temp("pfm/scholar",1);
    	num = me->query_skill("mysterrier",1)/8;
	if(judge(me,target))
		{
            me->set_temp("mysterrier",1);
			num = me->query_skill("mysterrier",1)/10;
	    	target->add_temp("apply/defense",-num);
		    me->start_call_out( (: call_other, __FILE__, "remove_effect", me, target, num:), num*4);
	        msg += YEL"$n惊慌间方寸大乱，进退失度\n"NOR;
		}
		else
		{
		   msg += YEL"$n凝神定气，丝毫不为$N的幻象所迷惑。\n"NOR;
		}
        message_vision(msg, me, target);
    
		me->start_busy(2);
        return 1;
}

void remove_effect(object me,object target,int amount)
{
	if( objectp(me) )
	{
		me->delete_temp("mysterrier");
		tell_object(me,"你的「七星追月」效果消失了。\n");
		if( objectp(target) )
		{
			tell_object(target,me->query("name")+"的身影渐渐散去，你慢慢恢复了正常...\n");
			target->add_temp("apply/defense",amount);
		}
	}
	return;
}
