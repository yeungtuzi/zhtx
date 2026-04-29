// unpoison.c
// written by tang
// 1998.4.11

#include <ansi.h>

inherit F_CONDITION;

int exert(object me, object target)
{
	string *conditions=({}),*list,arg;
	int i;
	int has_poison;

        if( me->is_fighting() )
                return notify_fail("战斗中运功解毒？找死吗？\n");

        if ((int)me->query_skill("tangmen-xinfa", 1) < 80)
                return notify_fail("你的唐门心法修为还不够。\n");

        if( (int)me->query("force") < (int)me->query("max_force")+200 ) 
                return notify_fail("你的真气不够。\n");

        if( (int)me->query("eff_kee") < (int)me->query("max_kee") / 2 )
                return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");

        if( (int)target->query("eff_kee") < (int)target->query("max_kee") / 5 )
                return notify_fail( target->name() +
                        "已经受伤过重，经受不起你的真气震荡！\n");
	
          me->add("force", -200);
	if( target != me )
	        message_vision(
        	        HIG "$N坐了下来运起内功给$n解毒....\n"NOR,me, target );
	else
	        message_vision(
        	        HIG "$N坐了下来运起内功解毒...\n"NOR,me);

	list = get_dir("/daemon/condition/");
	
	i = sizeof(list);
	while( i-- )
	{
		arg = list[i];
		if( arg[strlen(arg)-8..strlen(arg)-3] == "poison" )
			conditions += ({arg[0..strlen(arg)-3]});
	}
	
	i = sizeof(conditions);
	has_poison=0;
	while(i--) 
	{
		if( target == me )
		{
		        if( (int)me->query("force") < 50 ) 
               			return notify_fail("你的真气不够。\n");
			if( me->query_condition(conditions[i]) > 0 )
			{
				me->apply_condition(conditions[i],0);
				message_vision(HIG"过了不久，$N额头上冒出豆大的汗珠，从手指尖滴出一缕黑血，黑血渐渐由黑转红...\n"NOR,me);

				if( wizardp(me) )
					message_vision("$N的"+conditions[i]+"被解啦。\n",me);
				me->add("force",-50);
				has_poison = 1;
			}
		}
		else
		{
		        if( (int)me->query("force") < 50 ) 
               			return notify_fail("你的真气不够。\n");

			if( target->query_condition(conditions[i]) > 0 )
			{
				target->apply_condition(conditions[i],0);
				message_vision(HIG"过了不久，$N额头上冒出豆大的汗珠，从手指尖滴出一缕黑血，黑血渐渐由黑转红...\n"NOR,me,target);
				if( wizardp(me) )
					message_vision("$n的"+conditions[i]+"被$N解啦。\n",me,target);
				me->add("force",-50);
				has_poison = 1;
			}
		}	
	}
	
	if(!has_poison) return notify_fail("毒素已排净！\n");

	write("Ok。\n");
	return 1;
}

 
