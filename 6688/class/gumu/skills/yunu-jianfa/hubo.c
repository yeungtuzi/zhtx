#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int perform(object me, object target)
{
        int skill,eff;
        object weapon;

        if(!me->query("zuoyou-hubo"))
                return notify_fail("你所使用的外功中没有这项功能");                        
        if( !me->is_fighting() )
                return notify_fail("双剑互搏只能在战斗中使用。\n");

        if( (int)me->query("int") < 30 )
                return notify_fail("你的悟性还不够高，用不了「双剑互搏」。 \n");

        if( (int)me->query("fav") < 10||(int)me->query("fav") >20 )
                return notify_fail("你的偏好不适合运用「双剑互搏」。 \n");

 //           if( me->query_skill_mapped("force") != "xiantian-gong")
 //               return notify_fail("你必须使用先天功才能使出双剑互搏！\n");

        if( (int)me->query("force") < 1000)     return notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("skill_mark/hubo") ) return notify_fail("你已经在运功\中了。\n");
        if( !objectp( weapon = me->query_temp("weapon")) || weapon->query("skill_type")!="sword" )
                return notify_fail("你手中无剑，如何使用双剑互搏？\n");
        if( me->query_skill_mapped("sword") != "yunu-jianfa" )
                return notify_fail("你的剑法无法使用双剑互搏。\n");

        skill = me->query_skill("sword");
        if( me->query("betrayer") ) skill /= 2;
        me->add("force", -500);
        me->receive_damage("kee", 0);
        me->set_temp("skill_mark/hubo",1);
        message_vision(
                HIC "$N招式一变，身法骤然加快，手中的一柄剑好似变成了两柄剑，\n左右手使出截然不用的剑法来！\n" NOR, me);

        me->add_temp("apply/attack", skill/5);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/5 :), skill);


        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/attack", - amount);
        me->delete_temp("skill_mark/hubo");
        tell_object(me, "你的双剑互搏运用完毕，将内力收回丹田。\n");
}

