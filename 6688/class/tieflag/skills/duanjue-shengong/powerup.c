/**************************************************************************/
// 纵横天下-I 
// ZHSCHOOL Contributed Source: From ES2 
// $Id: powerup.c,v 1.2 2000/12/14 15:21:43 cmy Exp $
/**************************************************************************/
// powerup.c

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;

        if( target != me ) return notify_fail("你只能用断绝神功\提升自己的战斗力。\n");

        if( (int)me->query("force") < 300 )     return notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("powerup") ) return notify_fail("你已经在运功\中了。\n");

        skill = me->query_skill("force");

        me->add("force", -100);
        me->receive_damage("kee", 10);

        message_vision(
                HIW "$N微一凝神，运起断绝神功，忽的庄严许多！\n" NOR, me);

        me->add_temp("apply/dodge", skill/2);
        me->set_temp("powerup", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/2 :), skill);

        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/dodge", - amount);
        me->delete_temp("powerup");
        tell_object(me, "你的断绝神功\运行完毕，将内力收回丹田。\n");
}

