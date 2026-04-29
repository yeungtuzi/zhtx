// unpoison.c
// written by tang
// 1998.4.11

// modified by yeung for jiuyang-shengong

#include <ansi.h>

inherit F_CONDITION;

int exert(object me, object target)
{
	string *conditions=({}),*list,arg;
	int i;

	if( !target )
		target = me;

	if( target != me)
		return notify_fail("九阳神功只可以化解自己体内的毒素。\n");

        if( me->is_fighting() )
                return notify_fail("战斗中运功解毒？找死吗？\n");

        if ((int)me->query_skill("jiuyang-shengong", 1) < 80)
                return notify_fail("你的九阳神功修为还不够。\n");

        if( (int)me->query("force") < 50 ) 
                return notify_fail("你的真气不够。\n");
	
        message_vision(HIG "$N坐了下来运起内功解毒...\n"NOR,me);

	list = get_dir("/daemon/condition/");
	
	i = sizeof(list);
	while( i-- )
	{
		arg = list[i];
		if( arg[strlen(arg)-8..strlen(arg)-3] == "poison" )
			conditions += ({arg[0..strlen(arg)-3]});
	}
	
	i = sizeof(conditions);
	while(i--) 
	{
		if( me->query_condition(conditions[i]) > 0 )
		{
                                me->apply_condition(conditions[i],0);
			message_vision(HIG"过了不久，$N额头上冒出豆大的汗珠，从手指尖滴出一缕黑血，黑血渐渐由黑转红...\n"NOR,me);
		}
	}
	me->add("force",-50);
	return 1;
}

 
