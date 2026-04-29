// dodgeup.c 轻歌曼舞
#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int perform(object me, object target)
{
        int skill;

        if( target != me )
                return notify_fail("你只能对自己使用轻歌曼舞！\n");

        if ((int)me->query_skill("pixie-sword", 1) < 100)
                return notify_fail("你的辟邪剑法等级不够。\n");

        if( me->query_skill_mapped("force") != "kuihua-shengong")
                return notify_fail("你是太监，怎么可以用其他的内功，不怕走火入魔？！\n");

        if( (int)me->query("force") < 1000  )
                return notify_fail("你的内力不够。\n");

        if( (int)me->query_temp("dodgeup") )
                return notify_fail("你已经在运功中了。\n");

        skill = me->query_skill("pixie-sword",1);

        me->add("force", -200);
        me->receive_damage("kee", 0);
        message_vision(
        HIM "$N嫣然一笑，随风曼舞起来，似乎身旁的剧斗丝毫不放在心上！\n" NOR, me);
        me->add_temp("apply/parry", skill/3);
        me->add_temp("apply/dodge", skill/3);
        me->set_temp("dodgeup", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/3 :), skill);
        if( me->is_fighting() ) me->start_busy(3);
        return 1;
}
void remove_effect(object me, int amount)
{
        me->add_temp("apply/dodge", - amount);
        me->add_temp("apply/parry", - amount);
        me->delete_temp("dodgeup");
        tell_object(me, HIM"你弹了弹衣衫上的灰尘，停住了舞步！\n" NOR);
}
