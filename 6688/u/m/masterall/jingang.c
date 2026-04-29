// jingang.c 大金刚神通


inherit F_CLEAN_UP

void remove_effect(object me, int amount)

int perform(object me, object target)
{
        int skill

        if( target != me )
                return notify_fail(你只能对自己使用大金刚神通！\n)

        if ((int)me->query_skill(jingang-quan, 1) < 200)
                return notify_fail(你的大金刚拳等级不够，无法使用大金刚神通。\n)

        if( (int)me->query(force) < 1000  )
                return notify_fail(你的内力不够。\n)

        if( (int)me->query_temp(jingang) )
                return notify_fail(你已经在运功\中了。\n)


        me->add(force, -400)
        me->receive_damage(kee, 0)
        message_vision(
        HIY $N长啸一声，运用出少林无上绝技“大金刚神通”，你只觉得浑身充满了力量！\n NOR, me)
        me->add_temp(apply/strength, skill/3)
        me->add_temp(apply/attack, skill/3)
        me->add_temp(apply/damage, skill/3)
        me->set_temp(jingang, 1)
        me->start_call_out( (: call_other, __FILE__, remove_effect, me, skill/3 :), skill)
        if( me->is_fighting() ) me->start_busy(3)
        return 1
}
void remove_effect(object me, int amount)
{
        me->add_temp(apply/strength, - amount)
        me->add_temp(apply/attack, - amount)
        me->add_temp(apply/damage, - amount)
        me->delete_temp(jingang)
        tell_object(me, HIY你运用大金刚神通时间过长，恐过于消耗真元，急忙气归丹田，收回膨胀在体内

的真气。\n NOR)
}
