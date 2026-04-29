// powerup.c

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int perform(object me, object target)
{
        int skill,eff;
        object weapon;

        if( !me->is_fighting() )
                return notify_fail("狂风快剑只能在战斗中使用。\n");
        if( (int)me->query("force") < 1000)     return notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("skill_mark/wind-sword") ) return notify_fail("你已经在运功\中了。\n");
        if( !objectp( weapon = me->query_temp("weapon")) || weapon->query("skill_type")!="sword" )
                return notify_fail("你手中无剑，如何使用快剑？\n");
        if( me->query_skill_mapped("sword") != "wind-sword" )
                return notify_fail("你的剑法无法使用狂风快剑。\n");
//        if( me->query("family/family_name") != "华山派剑宗")
//                return notify_fail("你不是华山派剑宗正宗弟子，还没学会使用狂风快剑。\n");               
        eff = 2500;
        if( me->query_skill_mapped("dodge") == "yan-shuangfei" )
        eff = 5000;
        if( me->query("faith") < 1000+eff*me->query("betrayer") )
                return notify_fail("你的门忠不够，不能使用。\n");

        skill = me->query_skill("sword");
        if( me->query("betrayer") ) skill /= 2;
        if( me->query("family/family_name") != "华山派剑宗" ) skill /= 2;
        me->add("force", -500);
        me->receive_damage("kee", 0);
        me->set_temp("skill_mark/wind-sword",1);
        message_vision(
                HIC "$N一声长啸，不再保留，手中狂风快剑全力展开！\n" NOR, me);

        me->add_temp("apply/attack", skill/5);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/5 :), skill);


        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/attack", - amount);
        me->delete_temp("skill_mark/wind-sword");
        tell_object(me, "你的狂风快剑运用完毕，将内力收回丹田。\n");
}

