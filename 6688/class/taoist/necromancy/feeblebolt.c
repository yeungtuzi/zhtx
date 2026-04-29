// feeblebolt.c                            
// modified by yeung 只有配合咒剑王符才可以发挥最大威力

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
	msg = HIW "$N口中喃喃地念著咒文，左手一挥，手中聚起一团白光射向$n！\n\n" NOR;

//        ap = me->query_skill("spells"); 加入灵性和神秘的作用
        ap = me->query_skill("spells")*me->query_msc()*me->query_spi()/800;
	ap -= target->query_skill("necromancy",1);//让对方的necromancy可以增加躲闪的机会
	if( ap < 1 ) ap = 1;

	//基数是对80万EXP大概52%命中
	ap = ( ap * ap * ap ) / 16 * (int)me->query("sen")/400;

	//专用的法术道具(咒剑等),可以放大这种效果                               

	if( objectp(myweap = me->query_temp("weapon")) )
		mana_imp = myweap->query_mana_imp();	

	if( !mana_imp ) 
		mana_imp = 1;
                           
	if( me->query_mana_imp() )
		mana_imp *= (int)me->query_mana_imp();

	if( mana_imp ) 	ap *= mana_imp;
//        if(ap < 0||ap>20000000) ap = 20000000;提高命中率上限
        if(ap < 0||ap>100000000) ap = 100000000;
	if( ap < 1 ) ap = 1;
	dp = target->query("combat_exp");
	if(dp < 1) dp = 1;
	if( random(ap + dp) > dp ) {
		damage = me->query("mana_factor")*8 + (int)me->query("max_mana") / 20 + random((int)me->query("eff_sen") / 10);
		damage -= (int)target->query("max_mana") / 30 + (int)me->query("eff_sen") / 15;

		//原来的杀伤力太强，降低对精通necromancy的人的杀伤力
		damage -= ((int)target->query_skill("necromancy",1))*2;
		
		//基数(没有增强之前)要小一些 大约 60神 左右
		damage /= 8;
		//道具可以增强效果
		if( mana_imp ) 	damage *= mana_imp;
		if( userp(target) ) damage /= 3;		
		//防魔法力的作用
		damage -= target->query_temp("apply/armor_vs_spells") * 2;

		if( damage > 0 ) {
			msg +=  HIR "结果「嗤」地一声，白光从$p身上透体而过，拖出一条长长的黑气直射到\n"
					"两三丈外的地下！\n" NOR;
//                        target->receive_damage("sen", damage*2/3, me);
//                        target->receive_wound("sen", damage/4, me);
                        target->receive_damage("sen", damage, me);
                        target->receive_wound("sen", damage*4/5, me);
			me->improve_skill("necromancy", 1, 1);
		} else
			msg += "结果「嗤」地一声，白光从$p身上透体而过，无声无息地钻入地下！\n";
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

	me->start_busy(2);
	return 1;
}


