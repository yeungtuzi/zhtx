// netherbolt.c

#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	string msg;
	int damage, ap, dp, mana_imp;
	object myweap;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	target->is_corpse()
	||	target==me)
		return notify_fail("你要对谁施展这个法术？\n");

// avoid PKing with necromancy.     yeung
	if( userp(target) && !me->is_fighting(target) )
		return notify_fail("只有战斗中才可以对玩家使用茅山道术。\n");

	if((int)me->query("mana") < 25 )
		return notify_fail("你的法力不够！\n");

	if((int)me->query("sen") < 10 )
		return notify_fail("你的精神没有办法有效集中！\n");

	me->add("mana", -25);
	me->receive_damage("sen", 10);

	msg = HIC "$N口中喃喃地念著咒文，左手一挥，手中聚起一团青光射向$n！\n\n" NOR;

	ap = me->query_skill("spells")+me->query_spi()-target->query_spi();
// 给茅山留个对拼的法术吧，呵呵
// 对方如果道行高深，则成功希望大减
//	dp = target->query_skill("spells")-me->query_spi()+target->query_spi();
//	ap -= dp;
	
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
//        if( ap < 0 || ap > 20000000 ) ap = 20000000;提高上限masterall
        if( ap < 0 || ap > 100000000 ) ap = 100000000;
	if(ap < 1) ap = 1;
	dp = target->query("combat_exp")*8/6;
//	message_vision(sprintf("ap = %d ,mana_imp= %d,dp = %d\n",ap,mana_imp,dp),me);
	if( random(ap + dp) > dp ) {
		//netherbolt随自己的法力成长而加强威力。
		damage = me->query("mana_factor")*4 + (int)me->query("max_mana") / 5 + (int)me->query("mana") / 10;
		//同样的，如果对方法力高强，就伤害轻微的多。
		damage -= ((int)target->query("max_mana") / 15 + (int)target->query("mana") / 30);
		//基数(没有增强之前)要小一些 大约260气左右
		damage /= 4;
		//道具可以增强效果
		if( mana_imp ) 	damage *= mana_imp;
		if( userp(target) ) damage /= 3;	

                //防魔法力的作用
                damage -= target->query_temp("apply/armor_vs_spells") * 4;
		if( damage > 0 ) {
			msg +=  HIR "结果「嗤」地一声，青光从$p身上透体而过，拖出一条长长的血箭直射到\n"
					"两三丈外的地下！\n" NOR;
			if( me->query("mana_factor")>20 )
				target->receive_wound("kee", damage, me);
			target->receive_damage("kee", damage/3, me);
			me->improve_skill("necromancy", 1, 1);
		} else
			msg += "结果「嗤」地一声，青光从$p身上透体而过，无声无息地钻入地下！\n";
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


