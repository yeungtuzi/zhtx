// /daemon/class/legend/sevencolor/max_gin_heal.c

#include <ansi.h>

int exert(object me, object target)
{
        if( me->is_fighting() )
                return notify_fail("拜托,先打完这架再说!\n");
        if ((int)me->query_skill("force", 1) < 50)
                return notify_fail("你的内功心法修为还不够。\n");
	if ((int)me->query_skill("sevencolor", 1) <50)
		return notify_fail("你的七彩玲珑心法修为还不够。\n");
	if (!target || target == me) {
        if( (int)me->query("force") < 50 ) 
                return notify_fail("你的真气不够。\n");
        if( (int)me->query("eff_gin") >= (int)me->query("max_gin"))
                return notify_fail("你现在并没有受伤,不需要运功治疗.\n");
        if( (int)me->query("eff_gin") < (int)me->query("max_gin") / 2 )
                return 
                notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");
        write( HIW "你全身放松，坐下来开始运功疗伤。\n" NOR);
        message("vision",
                HIW + me->name() + "打了一会儿坐, 神色看起来好多了。\n" NOR,
                environment(me), me);
        me->receive_curing("gin", 10 + (int)me->query_skill("force")/7 );
        me->add("force", -50);
        me->set("force_factor", 0);
        return 1;
	}
        if( (int)me->query("force") < 150 ) 
                return notify_fail("你的真气不够。\n");
	if( (int)target->query("eff_gin") >= (int)target->query("max_gin"))
		return notify_fail(target->name()
			+"现在并没有受伤,不需要运功治疗.\n");
	if( (int)target->query("eff_gin") < (int)target->query("max_gin")/5)
                return notify_fail( target->name() +
                        "已经受伤过重，经受不起你的真气震荡！\n");
message_vision(HIY 
"$N坐了下来运起内功，将手掌贴在$n背心，缓缓地将真气输入$n体内....\n\n"
"过了不久，$N额头上冒出豆大的汗珠，$n吐出一口瘀血，神色看起来好多了。\n" 
NOR, me, target );
        target->receive_curing("gin", 10 + (int)me->query_skill("force")/3 );
        target->add("gin", 10 + (int)me->query_skill("force")/3 );
        if( (int)target->query("gin")>(int)target->query("eff_gin")) 
		target->set("gin", (int)target->query("eff_gin"));
        me->add("force", -150);
        me->set("force_factor", 0);
        me->start_busy(2);
        target->start_busy(2);
        return 1;
}
