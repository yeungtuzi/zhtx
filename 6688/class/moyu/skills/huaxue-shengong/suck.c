// lifeheal.c

#include <ansi.h>

object offensive_target(object me)
{
        int sz;
        object *enemy;

        enemy = me->query_enemy();
        if( !enemy || !arrayp(enemy) ) return 0;

        sz = sizeof(enemy);
        if( sz > 4 ) sz = 4;

        if( sz > 0 ) return enemy[random(sz)];
        else return 0;
}

int exert(object me, object target,int amount)
{
	string msg;
	object enemy;
	
	if( !me->is_fighting() )
                return notify_fail("「吸血大法」只能在战斗中使用。\n");
	
	if( (int)me->query("force") < 250 )
		return notify_fail("你的真气不够。\n");

	enemy = offensive_target(me);
	
	msg = RED"$N"+RED"如野兽急喘起来，化成一幢血雾，涌向$n，\n";

	me->start_busy(1);
	if( random(me->query("combat_exp")) > (int)enemy->query("combat_exp")/2 ) {
		msg += RED"这血雾奇劲无处落，连挡、闪、避、退都不可能,\n";
		msg += "突然"+"$P"+RED"一口咬住$p"+RED"的脖子,嗞的一声吸出一股鲜血！\n" NOR;
              	enemy->receive_damage("kee",enemy->query("kee")/2);
              	enemy->receive_wound("kee",enemy->query("kee")/4);
              	me->add("force",enemy->query("kee")/4);
	} else {
		msg += RED"只见$p"+RED"将头一偏，反手一招，一肘把$P"+RED"撞了出去。\n" NOR;
		me->start_busy(3);
	}
	message_vision(msg, me,enemy);
	
	me->add("force", -250);
	return 1;
}
