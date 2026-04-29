#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        object soldier;
        string msg;
        int num;

        if( !me->is_fighting() )
                return notify_fail("「飘絮随风」只能在战斗中使用。\n");

	if( me->query("betrayer") )
		return notify_fail("你不是步玄派正宗弟子，还没学会使用步玄七诀这一式。\n");
                
        if( me->query("force") < 100 ) return notify_fail("你的内力不够，无法使用「飘絮随风」！\n");
	if( me->query_temp("mysterrier") ) return notify_fail("你现在还无法使用「飘絮随风」！\n");
        
        msg = YEL "$N使出步玄七诀第二式「飘絮随风」，身如风中柳絮，一触即退，随敌人招式飘忽不定！\n" NOR;
        message_vision(msg, me);
        me->add("force",-100);
        me->start_busy(1);
            me->set_temp("pfm/scholar",1);
		me->set_temp("mysterrier",1);
		num = me->query_skill("mysterrier",1)/8;
		me->add_temp("apply/defense",num);
		call_out("remove_effect",num,me,num);
	
        return 1;
}

void remove_effect(object me,int num)
{
	tell_object(me,"你全身真气由清转浊，身形渐渐迟缓下来\n");
	me->add_temp("apply/defense",-num);
	me->delete_temp("mysterrier");
}
