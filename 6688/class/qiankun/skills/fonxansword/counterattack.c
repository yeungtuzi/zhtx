// counterattack.c

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        string msg;
        string weapon;


        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("牵制攻击只能对战斗中的对手使用。\n");

         weapon = me->query_temp("weapon");
         if(!weapon || weapon->query("skill_type")!="sword") return notify_fail("你必须装备一把剑！\n");

//        if( me->query_skill_mapped("sword") != "fonxansword")
//                return notify_fail("你必须首先enable封山剑法!\n");

         if( (int)me->query("kee") < 100 ) return notify_fail("你的气不够！\n");
         if( (int)me->query("force") - (int)me->query("max_force") < 50 )
                 return notify_fail("你的真气不够！\n");


        if( target->is_busy() )
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");

        msg = CYN "$N使出封山剑法「封」字诀，连递数个虚招企图扰乱$n的攻势，";

        me->start_busy(1);
        if( random(me->query("combat_exp")+target->query("combat_exp")/2) > (int)target->query("combat_exp")/2 ) {
                msg += "结果$p被$P攻了个措手不及！\n" NOR;
               target->start_busy( (int)me->query_skill("fonxansword",1) / 20 + 2);
        } else {
                msg += "可是$p看破了$P的企图，并没有上当。\n" NOR;
                me->start_busy(3);
        }
        me->add("force", -300);
        message_vision(msg, me, target);

        return 1;
}
