#include <ansi.h>
#include <combat.h>
//inherit SSERVER;

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

int exert(object me, object target)
{
        string msg;
        int count,skill_level; 
        object weapon,enemy;

        if( !me->is_fighting() )
                return notify_fail("「一气贯日月」只能在战斗中使用。\n");

        if( (int)me->query("force") < 1000 ) return notify_fail("你的内力不够！\n");
        
        enemy = offensive_target(me);
	

        skill_level = me->query_skill("xuehe-shengong",1);
        
        if( skill_level < 200 )                              
                return notify_fail("你的修为太浅！\n");
        
        msg = WHT"\n$N"+WHT"大喝一声，吐出了一口白练般的真气，正是血河派登峰造极之神功「一气贯日月」！\n\n" NOR;
	
	if( random(me->query("combat_exp")) > (int)enemy->query("combat_exp")/2 ) {
		msg += HIY"这股真气铺天盖地的卷向$n、"+HIY"令$n"+HIY"躲无可躲,\n";
		msg += "只听砰一声巨响，一道匹练般的真气正中$n"+HIY+"胸口！\n" NOR;
              	enemy->receive_damage("kee",me->query("force_factor")*2);
              	enemy->receive_wound("kee",me->query("force_factor"));
              	me->start_busy(1);
	} else {
		msg += HIY"只见$p"+HIY"七八个翻身，落在五丈之外。\n" NOR;
		me->start_busy(3);
	}
	message_vision(msg, me, enemy);
        me->add("force",-500);
        return 1;
}

