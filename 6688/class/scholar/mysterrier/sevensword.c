#include <ansi.h>
#include <combat.h>

inherit SSERVER;

int perform(object me, object target)
{
        object weapon,*victims;
        string msg;
        int num,sz,i;

	if( !me->is_fighting() )
                return notify_fail("「七诀剑气」只能在战斗中使用。\n");
	if( me->query("betrayer") )
		return notify_fail("你不是步玄派正宗弟子，还没学会使用步玄七诀这一式。\n");
                
        if( me->query("force") < (me->query("max_force")+600) ) return notify_fail("你的内力不够，无法使用「七诀剑气」！\n");
        if( !objectp( weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "sword" )
        	return notify_fail("「七诀剑气」只能配合剑法使用！\n");
        	
        msg = YEL "$N使出步玄七诀最后一式「七诀剑气」，身剑合一，全身真气贯注于手中"+weapon->query("name")+"，化做七道电光同时向对手射去！\n" NOR;
        message_vision(msg, me);
        
        //耗500内力
        	me->add("force",-500);
            me->set_temp("pfm/scholar",1);
                num = me->query_skill("mysterrier",1);
                me->add_temp("apply/attack",num/2);
                me->add_temp("apply/damage",num);
		me->clean_up_enemy();
	    	victims = me->query_enemy();
		sz = sizeof(victims);
		while(sz--)
		{
		message_vision(HIY"电光射向$N！\n"NOR,victims[sz]);
		i = (num-100)/50+1; //最多三次攻击
		if (i<0) i=0;
		while( i-- )
			{
				if(me->query("force")>200)
				{
					COMBAT_D->do_attack(me,victims[sz],weapon,TYPE_QUICK);
					me->add("force",-200);
				}
				else 
				{
					tell_object(me,"你的内力不够，无法用出「七诀剑气」\n");
				    break;
				}
			}
		}
                me->add_temp("apply/attack",-num/2);
                me->add_temp("apply/damage",-num);    
        	me->start_busy(5);	
        	return 1;
}
