// wuxing.c  
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon, ob;
        string msg, string1;
        int extra;
        int count,ap,dp;
        if( !target ) target = offensive_target(me);

        if( !me->is_fighting() )
                return notify_fail("「五行连击」只能在战斗中使用。\n");
 
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "hammer")
                return notify_fail("「五行连击」用的兵器不是这个！\n");

        if( (int)me->query("force")<(int)me->query("max_force") )
                return notify_fail("你的真气不够！\n");
        if( (int)me->query_skill("wuxinglun",1) < 150 )
                return notify_fail("你的五行轮法不够！\n");
        extra = me->query_skill("wuxinglun",1)/2;
        ap = extra*2;
        dp = target->query_skill("dodge", 1)+target->query_skill("parry", 1);
        me->add("force", -1000);
        message_vision( HIY "$N纵跃退後，立时呜呜、嗡嗡、轰轰之声大作，金光闪闪，银光烁烁，五只轮子从五个不同方位飞袭出来！\n\n
                           看 金 轮 \n " NOR,me);
         if( random(ap+dp) > dp){
         message_vision( HIY"\n$n"+HIY"眼见霞光千丈，金光万道，顿时被闪得眼花缭乱，意乱神迷！！\n" NOR,me,target);
         target->receive_wound("gin", extra);
         target->receive_wound("sen", extra);
         }else{
         message_vision( HIW"\n$n"+HIW"志定心坚，任凭$N有千般变化，我自心中一份清明！！\n" NOR,me,target);
         }   
         me->add_temp("apply/attack",extra/3);     
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
         me->add_temp("apply/attack",-extra/3);

                if(!objectp(target) 
                   || target->is_ghost() 
                   || target->query("eff_kee") < 1
                   || (environment(me)!=environment(target))
                   || me->is_ghost())             
                {
                        message_vision(HIM"五行金轮盘旋了数周，化作五彩极光消失在天际。\n"NOR,me);
                        return 1;
                } 


         message_vision( HIG  "\n                           看 木 轮！\n " NOR,me);
         if( random(ap+dp) > dp){
         message_vision( HIG"\n$n"+HIG"顿觉眼前盘根错节，纷乱不清，好似有千万股力道将自己逐渐拖入一个无边的沼泽！！\n" NOR,me,target);
         target->add("force", -extra*2);
         }else{
         message_vision( HIW"\n$n"+HIW"志定心坚，任凭$N有千般变化，我自心中一份清明！！\n" NOR,me,target);
         }   
         me->add_temp("apply/attack",extra/3);     
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
         me->add_temp("apply/attack",-extra/3);

                if(!objectp(target) 
                   || target->is_ghost() 
                   || target->query("eff_kee") < 1
                   || (environment(me)!=environment(target))
                   || me->is_ghost())             
                {
                        message_vision(HIM"五行金轮盘旋了数周，化作五彩极光消失在天际。\n"NOR,me);
                        return 1;
                } 


         message_vision( HIC  "\n                           看 水 轮！\n " NOR,me);
         if( random(ap+dp) > dp){
         message_vision( HIC"\n$n"+HIC"感到一阵阵寒意袭来，冰冷彻骨，辗转腾挪之间动作已经不大灵光！！\n" NOR,me,target);
         target->start_busy(2);
         }else{
         message_vision( HIW"\n$n"+HIW"志定心坚，任凭$N有千般变化，我自心中一份清明！！\n" NOR,me,target);
         }   
         me->add_temp("apply/attack",extra/3);     
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
         me->add_temp("apply/attack",-extra/3);

                if(!objectp(target) 
                   || target->is_ghost() 
                   || target->query("eff_kee") < 1
                   || (environment(me)!=environment(target))
                   || me->is_ghost())             
                {
                        message_vision(HIM"五行金轮盘旋了数周，化作五彩极光消失在天际。\n"NOR,me);
                        return 1;
                } 

         message_vision( HIR  "\n                           看 火 轮！\n " NOR,me);
         if( random(ap+dp) > dp){
         message_vision( HIR"\n$n"+HIR"感觉澎湃的热流一浪高过一浪，激发起体内的真气不断乱窜，好像被数万只蚂蚁撕咬般苦楚！！\n" NOR,me,target);
         target->receive_wound("kee", extra*2);
         }else{
         message_vision( HIW"\n$n"+HIW"志定心坚，任凭$N有千般变化，我自心中一份清明！！\n" NOR,me,target);
         }   
         me->add_temp("apply/attack",extra/3);     
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
         me->add_temp("apply/attack",-extra/3);

                if(!objectp(target) 
                   || target->is_ghost() 
                   || target->query("eff_kee") < 1
                   || (environment(me)!=environment(target))
                   || me->is_ghost())             
                {
                        message_vision(HIM"五行金轮盘旋了数周，化作五彩极光消失在天际。\n"NOR,me);
                        return 1;
                } 

         message_vision( YEL  "\n                           看 土 轮！\n " NOR,me);
         if( random(ap+dp) > dp){
         message_vision( YEL"\n$n"+YEL"感觉脚下的大地突然间塌陷了一般，而整个身体正在不断的下降，下降，逐渐陷入万劫不复的深渊！！\n" NOR,me,target);
         target->add_temp("apply/attack",-extra/2); 
         target->add_temp("apply/defense",-extra/2);      
         }else{
         message_vision( HIW"\n$n"+HIW"志定心坚，任凭$N有千般变化，我自心中一份清明！！\n" NOR,me,target);
         }   
         me->add_temp("apply/attack",extra/3);     
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
         me->add_temp("apply/attack",-extra/3);

                if(!objectp(target) 
                   || target->is_ghost() 
                   || target->query("eff_kee") < 1
                   || (environment(me)!=environment(target))
                   || me->is_ghost())             
                {
                        message_vision(HIM"五行金轮盘旋了数周，化作五彩极光消失在天际。\n"NOR,me);
                        return 1; 
                } 

        me->start_busy(3);
        return 1;
}


