// life curse                            

#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	string msg;
	int damage, ap, dp, mana_imp;//mana_imp是法术道具的威力放大系数.
	object myweap;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	target->is_corpse()
	||	target==me)
		return notify_fail("你要对谁施展这个法术？\n");

	if((int)me->query("mana") < 25 )
		return notify_fail("你的法力不够！\n");

	if((int)me->query("sen") < 10 )
		return notify_fail("你的精神没有办法有效集中！\n");

// avoid PKing with necromancy.     yeung
	if( userp(target) && !me->is_fighting(target) )
		return notify_fail("只有战斗中才可以对玩家使用茅山道术。\n");

	me->add("mana", -25);
	me->receive_damage("sen", 10);

	if( random(me->query("max_mana")) < 50 ) {
		write("你失败了。\n");
		return 1;
	}
	msg = HIW "$N口中喃喃地念著咒文，左手一挥，隐约中,一个巨大的黑色烟雾扑向$n！\n\n" NOR;

	ap = me->query_skill("spells");
	ap -= target->query_skill("necromancy",1);//让对方的necromancy可以增加躲闪的机会
	if( ap < 1 ) ap = 1;

	//基数是对80万EXP大概52%命中
	ap = ( ap * ap * ap ) / 16 * (int)me->query("sen")/400;
	//专用的法术道具(咒剑等),可以放大这种效果                               
	if( objectp(myweap = me->query_temp("weapon")) )
		mana_imp = myweap->query_mana_imp();	
	else 
		mana_imp = 0;                           
	if( mana_imp ) 	ap *= mana_imp;
	if(ap < 1) ap = 1;
		
	dp = target->query("combat_exp");
	if(dp < 1) dp = 1;
        if( random(ap + dp) > (dp /2)) {
			msg += "$n心头一阵迷惘,似乎少了些什么重要的东西.\n";
			target->set("max_kee",target->query("max_kee")/2);
	} else
		msg += "但是被$n躲开了。\n";

	message_vision(msg, me, target);
	if( damage > 0 ) COMBAT_D->report_status(me,target,1);

	if( !target->is_fighting(me) ) {
		if( living(target) ) {
			if( userp(target) ) target->fight_ob(me);
			else 				target->kill_ob(me);
		}
		me->kill_ob(target);
	}

	me->start_busy(3);
	return 1;
}


