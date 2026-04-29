// double.c 阴劲加倍

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);


int exert(object me, object target)
{
        int skill;

        if( target != me )
                return notify_fail("你只能用『阴功』来打通全身的脉络。\n");

        if ((int)me->query_skill("yin-gong", 1) < 250)
                return notify_fail("你的阴功等级不够，无法打通全身的脉络。\n");

        if( (int)me->query("force") < 1000  )
                return notify_fail("你的内力不够。\n");

        if( (int)me->query_temp("have_double") )
                return notify_fail("你已经将气血加倍了，还想继续翻番啊？没门！\n");

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
        me->set("max_kee", (int)me->query("max_kee")*2);
        me->set("eff_kee", (int)me->query("max_kee"));
        me->set_temp("have_double",1);
        if( me->is_fighting() ) me->start_busy(3);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/3 :), skill);
        return 1;
}

void remove_effect(object me, int amount)
{
        me->set("kee", (int)me->query("max_kee")/2);
        me->set("max_kee", (int)me->query("max_kee")/2);
        me->set("eff_kee", (int)me->query("max_kee"));
        me->delete_temp("have_double");
        tell_object(me, HIG"你体内的真气有些运转不足，随即喘了口气，活动了一下筋骨。\n" NOR);
}


