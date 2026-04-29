//禁锢之网 

#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	string msg;
	int damage, ap, dp;
        int bet,i;
	if( !target ) target = offensive_target(me);
        bet=(int)me->query("betrayer");

	if( !target
	||	!target->is_character()
	||	target->is_corpse()
	||	target==me)
		return notify_fail("你要对谁施展这个法术？\n");

	if((int)me->query("mana") < 25 )
		return notify_fail("你的法力不够！\n");

	if((int)me->query("sen") < 20 )
		return notify_fail("你的精神没有办法有效集中！\n");
	
// avoid PKing with necromancy.     yeung
	if( userp(target) && !me->is_fighting(target) )
		return notify_fail("只有战斗中才可以对玩家使用茅山道术。\n");

	me->add("mana", -100);
	me->receive_damage("sen", 50);

	msg = HIM "$N口中喃喃地念著咒文，左手一挥，一团灰色的烟雾开始在$n身边聚积！\n\n" NOR;

	ap = me->query_skill("spells")+me->query_spi();
	ap = ( ap * ap * ap / 4 ) /100* (int)me->query("sen");
	ap /= 4;
	dp = target->query_skill("spells");
	dp = dp*dp/8*dp;
	dp += target->query("combat_exp");
	if( random(ap + dp) > dp ) {
			msg += "但是,$n却似乎没有受到任何的伤害!\n";
			target->apply_condition("blockweb",10);
	} else
		msg += "但是被$n躲开了。\n";

	message_vision(msg, me, target);

	if( !target->is_fighting(me) ) {
		if( living(target) ) {
			if( userp(target) ) target->fight_ob(me);
			else 				target->kill_ob(me);
		}
		me->kill_ob(target);
	}

        me->start_busy(1);
	return 1;
}

