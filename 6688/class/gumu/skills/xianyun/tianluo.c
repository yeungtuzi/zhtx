// tianluo.c 天罗地网式
#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int perform(object me, object target)
{
        int skill;

        if( target != me )
                return notify_fail("你只能对自己使用天罗地网式！\n");

        if ((int)me->query_skill("xianyun", 1) < 200)
                return notify_fail("你的纤云身法等级不够。\n");

        if( (int)me->query("force") < 1000  )
                return notify_fail("你的内力不够。\n");

        if( (int)me->query_temp("xianyun") )
                return notify_fail("你已经在运功中了。\n");

        if( !me->is_fighting() )
                return notify_fail("天罗地网式只能在战斗中使用。\n");

        skill = me->query_skill("xianyun",1);

        me->add("force", -200);
        me->receive_damage("kee", 0);
        message_vision(
        HIG "$N使出古墓派绝学『天罗地网式』，身法突然加快，招招俱是进手，攻得对方措手不及！\n" NOR, 

me);
        me->add_temp("apply/dodge", skill/3);
        me->add_temp("apply/attack", skill/3);
        me->set_temp("xianyun", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/3 :), skill);
    //    if( me->is_fighting() ) me->start_busy(3);
        return 1;
}
void remove_effect(object me, int amount)
{
        me->add_temp("apply/dodge", - amount);
        me->add_temp("apply/attack", - amount);
        me->delete_temp("xianyun");
        tell_object(me,  HIG"你略微喘了口气，脚下的步法慢了下来。\n"NOR);
}
