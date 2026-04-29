// billow.c 「怒海狂涛」
// written by masterall 2002

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        int skill,num,damage,i;
        object weapon;

        if( !target ) target = offensive_target(me);

        if( !me->is_fighting() )
                return notify_fail("「怒海狂涛」只能在战斗中使用。\n");
        
        if( me->query("faith") < 1500 )
                return notify_fail("你的门忠不够，不能使用「怒海狂涛」。\n");

        if( (int)me->query("force") < 3000)
                return notify_fail("你的内力不够。\n");

        if( (int)me->query("force") <  (int)me->query("max_force"))
                return notify_fail("你的真气不够。\n");
        
        if( !objectp( weapon = me->query_temp("weapon")) || weapon->query("skill_type")!="sword" )
                return notify_fail("「怒海狂涛」必须手中有剑。\n");
        
        if( me->query_skill_mapped("sword") != "xuantie-sword" )
                return notify_fail("只有玄铁剑法才可以使用「怒海狂涛」。\n");

        if( me->query_skill_mapped("parry") != "xuantie-sword" )
                return notify_fail("只有玄铁剑法才可以使用「怒海狂涛」。\n");

        if( me->query_skill("xuantie-sword", 1) < 220 )
                return notify_fail("你的玄铁剑法等级太低了，使不出「怒海狂涛」。\n");

        if( me->is_busy() )
                return notify_fail("你正忙着呢。\n");

        skill = me->query_skill("xuantie-sword", 1);

        me->add("force", -300);

        num = me->query("cor")/20 + me->query("force") / target->query("force") + 1;
        if(num > 5) num = 5;

        damage = 150 * me->query_skill("force") / target->query_skill("force") +50;
        if(damage > 250 ) damage = 250;

        message_vision(HIB"\n$n只听得耳边的潮声愈来愈响，轰轰发发，便如千万只马蹄同时敲打地面一般，\n"+HIW"但见一条白线向着$n急冲而来，这一股声势，比之雷震电轰更是厉害。\n"+HIR"$n见$N竟有如此天地之神威，脸上不禁变色！\n"NOR,me, target);

//        me->add_temp("apply/damage", damage);  


                if(target)
                for(i=0;i<num;i++)
                {
                        if(target)
                        {
                                message_vision(HIC"\n滔天骇浪带着澎湃的劲气向$n卷去！"NOR,me,target);
        me->add_temp("apply/damage", damage/2);  
                                COMBAT_D->do_attack(me,target, me->query_temp("weapon"),0);
        me->add_temp("apply/damage", -damage/2);      
                                me->add("force", -100);
                                target->add("force", -10);
                        }
                }


        me->start_busy(3);
//        me->add_temp("apply/damage", -damage);      
        return 1;
}


