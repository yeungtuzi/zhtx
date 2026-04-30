#include <ansi.h>
 
inherit SSERVER;
 
int exert(object me, object target)
{
        // 2026-04-30: unused variable commented out
        // object *ob;
        int i, skill,level, damage, ff;
 
        level = me->query_skill("moni-xinfa",1);
 
        if( !me->is_fighting() )
                return notify_fail("「透骨针」只能在战斗中使用。\n");
 
        if( (int)me->query("force") < 50 )
                return notify_fail("你的内力不够。\n");

        if( level < 250 )
                return notify_fail("你的「摩尼心法」等级太低了。\n");
 
    // added sen check, Elon, Sat  10-07-95
 
        if( !target || target==me ) {
                target = offensive_target(me);
                if( !target) return notify_fail("你要对谁施展「透骨针」？\n");
        }
 
//        if( !random(2) )
                me->start_busy(3);
 
        skill = me->query_skill("force");
 
        me->add("force", -500);
         
        message_vision(
                HIB "$N将纯阴内力聚为一线攻向$n！\n" NOR, me, target);
        
        if( random(target->query("combat_exp")+((int)me->query("combat_exp")+skill*skill/30*skill)*2/3) > ((int)me->query("combat_exp")+skill*skill/30*skill)*2/3 ) {
                message_vision(HIY"$N识破了$n的用意，不慌不忙地躲了开去。\n"NOR, target, me);
                return 1;
        }
 
        damage = me->query("max_force")/10 + me->query("force")/10 + (int)me->query("force_factor") *3;
      if( damage < 1 ) {    
                message_vision(HIY"但是$N体内真气鼓荡，将这股阴气尽数化解！\n"NOR, target, me);
                return 1;
        }
 
        ff = target->query("force");
        ff -= damage/3;
        if( ff < 0 ) ff = 0;
        target->set("force", ff);
        target->set("force_factor", 0);

        message_vision(HIB"结果这一股至阴真气在$N体内循经脉迅捷无伦地转了一个周天，最后归于丹田！\n$N只觉得真气涣散，再也提不起内劲来！\n"NOR, target, me);
        return 1;
}

