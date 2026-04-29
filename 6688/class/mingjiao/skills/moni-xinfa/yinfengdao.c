#include <ansi.h>
 
inherit SSERVER;
 
int exert(object me, object target)
{
        object *ob;
        int i, skill, damage;
 
        if( !me->is_fighting() )
                return notify_fail("「阴风刀」只能在战斗中使用。\n");
 
        if( (int)me->query("force") < 100 )
                return notify_fail("你的内力不够。\n");
 
    // added sen check, Elon, Sat  10-07-95
    if( (int)me->query("sen") < 40 )
        return notify_fail("你的精神无法集中。\n");
 
        if( !target || target==me ) {
                target = offensive_target(me);
                if( !target) return notify_fail("你要对谁施展「阴风刀」？\n");
        }
 
        me->start_busy(2);
 
        skill = me->query_skill("force");
 
        me->add("force", -100);
        me->receive_damage("sen", 20);
 
        message_vision(
                HIB "$N发出一道虽然无形无质，却至阴至寒的阴风刀气，刺向$n丹田要穴！\n" NOR, me, target);
        
        if( random(target->query("combat_exp")) > ((int)me->query("combat_exp")+skill*skill/30*skill)/2 ) {
                message_vision(HIY"$N识破了$n的用意，不慌不忙地躲了开去。\n"NOR, target, me);
                return 1;
        }
 
        damage =  me->query("force")/15 + (int)me->query("force_factor") * 2 
                        -  target->query("force")/20 - target->query("force_factor");
        if( damage < 1 ) {
                message_vision(HIR"但是$n的真气被$N内力所逼，尽数回攻自身！\n"NOR, target, me);
                me->receive_wound("kee",(1-damage)*2,target);
                me->apply_condition("ninemoonpoison",20);
                return 1;
        }
 
        target->receive_damage("kee", damage, me);
        if( random(skill) > (int)target->query("cps") * 2 )
                target->receive_wound("kee", damage, me);
                target->apply_condition("ninemoonpoison",10);
        message_vision(HIB"结果阴风透体直入，$N哇的一声喷出一大口鲜血！\n"NOR, target, me);
        return 1;
}

