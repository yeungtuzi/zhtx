#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
	if( !target )	target = me;
	
	if( !target->query_condition("sheng_si") )
		return notify_fail("没有中生死符啊！\n");

	if( !me->query("skill_marks/sheng_si_fu" ) )
		return notify_fail("你不会解生死符。\n");

	if( target != me)
		if( target->query("family/family_name") != "灵鹫宫"
		&& target->query("family/family_name") != "逍遥派")
			return notify_fail("你难道忘了当初立下的重誓吗？！\n");

	if( me->is_fighting() || target->is_fighting())
		return notify_fail("战斗中无法驱除生死符！\n");

	if( (int)me->query("force") - (int)me->query("max_force") < 300 )
		return notify_fail("你的真气不够。\n");

	if( (int)target->query("eff_kee") < (int)target->query("max_kee") / 5 )
		return notify_fail( target->name() + "已经受伤过重，经受不起你的真气震荡！\n");
	message_vision(
		HIY "$N坐了下来运起内功，将手掌贴在$n背心，不断地运真气冲击$n的各处穴道....\n\n"
		"过了不久，$N额头上冒出豆大的汗珠，$n吐出一口瘀血，脸色看起来红润多了。\n" NOR,
		me, target );
	target->receive_curing("kee", 1 + random((int)me->query_skill("force")/3) );
		
	me->add("force", -300);
	target->clear_condition("sheng_si");

	return 1;
}
