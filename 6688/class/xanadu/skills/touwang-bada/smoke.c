
#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	string weapon;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("牵制攻击只能对战斗中的对手使用。\n");


        if( (int)me->query("kee") < 100 ) return notify_fail("你的气不够！\n");
        if( (int)me->query("force") < 100 )
                return notify_fail("你的真气不够！\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");

	msg = CYN "$N突然张口一吹，一道烟箭迎面向$n刺来，";

	me->start_busy(1);
	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
		msg += "结果$p刹那间什麽也看不见，脸面剧痛！\n" NOR;
              target->start_busy( (int)me->query_skill("touwang-bada",1) / 40 + 2);
	} else {
		msg += "可是被$p躲开了。\n" NOR;
		me->start_busy(3);
	}
	me->add("force", -50);
	message_vision(msg, me, target);

	return 1;
}
