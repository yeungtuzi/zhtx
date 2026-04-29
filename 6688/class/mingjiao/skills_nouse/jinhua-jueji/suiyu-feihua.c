// counterattack.c

#include <ansi.h>

inherit SSERVER;

int have_jinhua(object me);

int perform(object me, object target)
{
	string msg;
	int    s;

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("[31m碎玉飞花[37m只能对战斗中的对手使用。\n");
	s = (int) me->query_skill("jinhua-jueji",1);
	if( s <= 100)
		return notify_fail("你的金花绝技还不够精纯，不能发出金花伤人。\n");

        if(!have_jinhua(me))
		return notify_fail("这门绝技只有配合纯金梅花才能伤人。\n");

	message_vision(HIG"$N双手轻挥，一篷花雨罩向$n全身。\n"NOR,me,target);
	me->start_busy(random(2));
// 	just for mudos under win95.
// 	under unix,should be /50 and /2
//	yeung
	if( random(me->query("combat_exp")*s/5000) > (int)target->query("combat_exp")/200 ) {
		msg = HIR"结果$p慌乱之中中了数朵金花，顿时气血凝滞！\n" NOR;
		target->start_busy( s / 30 + 2);
		target->receive_wound("kee",s,me);
	} else {
		msg = HIG"可是$p轻轻闪开了。\n" NOR;
	}
	message_vision(msg, me, target);
	return 1;
}

int have_jinhua(object me)
{
	int i;
	object *inv;
	
	inv = all_inventory(me);
	if( !sizeof(inv) )
			return 0;
        for(i=0; i<sizeof(inv); i++)
		if( (inv[i]->query("name")) == HIY"纯金梅花"NOR ) return 1;
	return 0;
}