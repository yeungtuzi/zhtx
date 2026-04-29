// double.c 阴劲加倍

#include <ansi.h>

int exert(object me, object target)
{
        int skill;

        if( target != me )
                return notify_fail("你只能用『阴功』来打通全身的脉络。\n");

        if ((int)me->query_skill("yin-gong", 1) < 200)
                return notify_fail("你的阴功等级不够，无法打通全身的脉络。\n");

        if( (int)me->query("force") < 1000  )
                return notify_fail("你的内力不够。\n");

        if( (int)me->query("kee")>=(int)me->query("max_kee")*2 )
                return notify_fail("你已经将气血加倍了，再费那个力气干什么？\n");

        if( (int)me->query("kee")<(int)me->query("max_kee"))
                return notify_fail("你现在的气不够，还想靠这个翻本？\n");


        if( (int)me->query("eff_kee") < (int)me->query("max_kee"))
                return notify_fail("你已经受了内伤了，不能再用阴劲了。\n");

        skill = me->query_skill("force");

        me->add("force", -500);
        me->receive_damage("kee", 0);
        message_vision(
        HIB "$N将一股阴劲运气于丹田，将全身的潜力激发出来，\n只觉得畅快淋漓，一种说不出的快感走遍全身！\n" NOR, me);
        me->set("kee", (int)me->query("max_kee")*2);
        if( me->is_fighting() ) me->start_busy(3);
        return 1;
}


