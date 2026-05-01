// dodgeup.c 秋风起兮
#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int perform(object me, object target)
{
        int skill;

        if( target != me )
                return notify_fail("你只能对自己使用秋风步法！\n");

        if ((int)me->query_skill("fall-steps", 1) < 180)
                return notify_fail("你的秋风步法等级不够。\n");

        if( (int)me->query("force") < 1000  )
                return notify_fail("你的内力不够。\n");

        if( (int)me->query_temp("dodgeup") )
                return notify_fail("你已经在运功中了。\n");

        skill = me->query_skill("dodge");

        me->add("force", -200);
        me->receive_damage("kee", 0);
        message_vision(
        HIG "$N身随意转，身法骤然加快，好一式「秋风起兮」！\n" NOR, me);
        me->add_temp("apply/dodge", skill/5);
        me->add_temp("apply/attack", skill/5);
        me->set_temp("dodgeup", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/5 :), skill);
        if( me->is_fighting() ) me->start_busy(3);
        return 1;
}
void remove_effect(object me, int amount)
{
        me->add_temp("apply/dodge", - amount);
        me->add_temp("apply/attack", - amount);
        me->delete_temp("dodgeup");
        tell_object(me, HIG"你在空中一个盘旋，轻飘飘落下，姿势优美之极！\n" NOR);
}

