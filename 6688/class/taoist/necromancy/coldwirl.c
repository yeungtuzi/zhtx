// cold wirl                            

#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	string msg;
	int damage, ap, dp, mana_imp;//mana_imp是法术道具的威力放大系数.
	object myweap;

        object *inv,dress;
        int i;

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
	msg = HIW "$N口中喃喃地念著咒文，左手一挥，一股阴寒极冻之气缓缓从 $n身周升起！\n\n" NOR;

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
        if( random(ap + dp) > (dp/2) ) 
	{
			msg += "冰寒之气将$n的装备变得冰凉刺骨,$n不及防备之下,几乎冻僵,无奈下将全身装备脱了下来.\n\n";
        		inv = all_inventory(target);
			i = sizeof(inv);
        		if( inv && i )
				while(i--)
				{
				  dress=inv[i];
        			  if( (string)dress->query("equipped")=="worn" )
        			  {
					dress->unequip(); 
					dress->set("no_wear","这件衣服冰寒彻骨,没法穿.\n");
				  }
			        }
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


