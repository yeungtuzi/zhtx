#include <ansi.h>

inherit F_CLEAN_UP;
inherit F_SSERVER;

void remove_effect(object me, int amount);

int perform(object me, object target)
{
        int skill,eff;
        object weapon;

        if( !target ) target = offensive_target(me);
                     
        if( !me->is_fighting() )
                return notify_fail("刀剑合击只能在战斗中使用。\n");

        if( (int)me->query_skill("fuliu-jian", 1) < 200 )
                return notify_fail("你的回风拂柳剑还不够高，用不了「刀剑合击」。 \n");

        if( (int)me->query_skill("yanxing-dao", 1) < 200 )
                return notify_fail("你的雁行刀还不够高，用不了「刀剑合击」。 \n");

        if( (int)me->query("force") < 1000)   
                return notify_fail("你的内力不够。\n");

        if( (int)me->query_temp("skill_mark/heji") ) 
                return notify_fail("你已经在运功中了。\n");

        if( !objectp( weapon = me->query_temp("weapon")) || weapon->query("skill_type")!="sword" )
                return notify_fail("你手中无剑，如何使用刀剑合击？\n");

        if( me->query_skill_mapped("sword") != "fuliu-jian" )
                return notify_fail("你的剑法无法使用刀剑合击。\n");

        if( me->query_skill_mapped("blade") != "yanxing-dao" )
                return notify_fail("你的刀法无法使用刀剑合击。\n");

        skill = me->query_skill("sword")/2 + me->query_skill("blade")/2;

        if( me->query("betrayer") ) skill /= 2;
        me->add("force", -500);
        me->receive_damage("kee", 0);
        me->set_temp("skill_mark/heji",1);
        message_vision(
                HIG"$N轻啸一声，化剑为刀，刹那间"+HIC"刀光剑影"+HIG"已化作"+HIW"漫天雪幕"+HIG"向$n排山倒海般袭来！\n" NOR, me, target);

        me->add_temp("apply/attack", skill/5);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/5 :), skill);


        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/attack", - amount);
        me->delete_temp("skill_mark/heji");
        tell_object(me, HIR"你的剑招恢复平常，将内力收回丹田。\n"NOR);
}


