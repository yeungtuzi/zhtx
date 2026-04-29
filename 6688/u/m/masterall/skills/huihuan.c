//剑镖回环
//by masterall
#include <ansi.h>
#include <weapon.h>
inherit F_DBASE;
inherit SSERVER;           
#include <combat.h>


int perform(object me, object target)
{
        int skill1,skill2,i,per_power,per_lev,victim_exp,num;
        object ob;

        if( !me->is_fighting() )
                return notify_fail("「剑镖回环」只能在战斗中施用。\n");                              
        if( me->is_busy())

                return notify_fail("你正忙着呢，来不及用「剑镖回环」。\n");

        if (!objectp(ob = me->query_temp("weapon"))
        || (string)ob->query("skill_type") != "sword")
                return notify_fail("你手中无剑，如何使用「剑镖回环」？\n");    

        if (!objectp(ob = present("huihuan biao",me) ) )
                return notify_fail("你身上没带着回环镖，如何使用「剑镖回环」？\n");  
        
        if( userp(me) && (int)me->query("force") < 2000 ) return notify_fail("你的内力不够。\n");

        if( (int)me->query_temp("skill_mark/huihuan"))
                return notify_fail("你现在正在使用剑镖回环！\n");
         
        if( !target || target == me ) target = offensive_target(me);

        skill1 = me->query_skill("mantian-huayu",1);
        skill2 = me->query_skill("tangshi-jian",1);

        num=skill1+skill2;

        if(userp(me))
                  {
          
                if( skill1 < 180 ) 
          return notify_fail("你的「满天花雨」招式不够娴熟，使不出「剑镖回环」。\n"); 

                if( skill2 < 180 ) 
          return notify_fail("你的「唐诗剑法」招式不够娴熟，使不出「剑镖回环」。\n"); 

        }    
        me->add("force",-300);
        message_vision(HIG"$N身形一动，一道乌光带着逼人的寒气向$n激射而出！\n之后紧随着的便是$N的一柄长剑，去势更急，来势更猛，有似流星赶月，又如天女散花！！\n"NOR,me,target);
        if( target->query_skill("dodge")+target->query_skill("parry") < random((me->query_skill("sword") + me->query_skill("throwing"))*4/3))
        {
        me->set_temp("skill_mark/huihuan");
        me->add_temp("apply/attack",num/20);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),0);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),0);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),0);
        me->add_temp("apply/attack",-num/20);
        me->add("force",-300);
        message_vision(HIR"$n疲于应对$N的迎头三剑，那一点乌光却从$n的$l对穿而出，一阵阵的麻痒让$n痛苦不迭！！\n"NOR,me,target);
        target->apply_condition("tm_poison",10);     
        target->update_condition();  
        target->receive_wound("kee",num*2);
        target->start_busy(3+random(3));
                if(random(num)+100>200 )
                {
                remove_call_out("pfm2");
                call_out("pfm2", 3, me, target);
                }
                else
                {
                me->delete_temp("skill_mark/huihuan");
                }
                me->start_busy(2+random(2));
        }

        else if( ( random( target->query_skill("dodge") ) >  me->query_skill("sword")*2/3) && random(3) == 1 )
        {  
        message_vision(HIC"$n漫不经心的朝$N看了一眼，身体如陀螺般飞旋了起来，\n刹那间已到了$N的身后，乘其去势未消，随手便是一击！\n"NOR,me,target);    
        me->start_busy(2+random(2));
        me->delete_temp("skill_mark/huihuan");
        COMBAT_D->do_attack(target, me, target->query_temp("weapon"));
        }else

        {
        message_vision( HIY"$n高接低挡，闪转腾挪，堪堪化解了$N这疾风骤雨般的攻势，\n虽说毫发未伤，但其态甚是狼狈，$n已略感真气有所不畅。\n\n" NOR,me,target);
        target->add("force",-num);  
        me->start_busy(2+random(2));
        me->delete_temp("skill_mark/huihuan");
        }
        me->start_busy( 1+random(2) );
        return 1;
}

int pfm2(object me, object target)
{
        int num;
        num=(int)me->query_skill("tangshi-jian",1)/5+(int)me->query_skill("mantian-huayu",1)/5;
        if (!me)
        {
        me->delete_temp("skill_mark/huihuan");
        return 1;
        }
        if (!(objectp(present(target->query("id"), environment(me)))))
        {
        me->delete_temp("skill_mark/huihuan");
        return 1;
        }
        if(!living(target))
        {
        me->delete_temp("skill_mark/huihuan");
        return 1;
        }
        if( me->query_temp("weapon") )
        {
        me->delete_temp("skill_mark/huihuan");
        return 1;
        }
        if( me->query("force")< 1000 )
        {
        me->delete_temp("skill_mark/huihuan");
        return 1;
        }
        message_vision(HIB"未等$n喘息待定，只觉得脑后恶风不善，$N发出的"+HIM"回环镖"+HIB"居然在空中打了个回旋，\n其速度有增无减，带着烈烈风声呼啸而至！！\n"NOR,me,target);
        if( target->query_skill("dodge")+target->query_skill("parry") < random((me->query_skill("sword") + me->query_skill("throwing"))*4/3))
        {
        message_vision(HIR"$n前后难以相顾，被暗器打了个正着，体内积聚的毒素又如洪水般涌来！！\n"NOR,me,target);
        target->apply_condition("tm_poison",10);     
        target->update_condition();
        target->receive_wound("kee",num*10);
        }else if(  random( target->query_skill("dodge") ) >  me->query_skill("sword")  )
        {  
        message_vision(HIY"$n眼看情势危机，也顾不得颜面，一招“狗吃屎”扒在了地上！！\n"NOR,me,target);    
        target->start_busy(2+random(2));
        }
        me->add_temp("apply/damage", num);
        me->add_temp("apply/attack", num);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        me->add_temp("apply/damage", -num);
        me->add_temp("apply/attack", -num);
        me->add("force", -200);
                if(random(num)+100>200 )
                {
                remove_call_out("pfm3");
                call_out("pfm3", 3, me, target);
        message_vision(HIC"寒光一闪，"+HIM"回旋镖"+HIC"飞回$N的掌中，$N蓄势待发，酝酿着下一波的攻击。\n"NOR,me,target);

                }
                else
                {
        message_vision(HIM"回旋镖"+HIG"来势太急，$N一时手忙脚乱，竟然也没能接住，任由它飞了出去！\n"NOR,me,target);
                me->delete_temp("skill_mark/huihuan");
                }
        return 1;

}

int pfm3(object me, object target)
{
        int num;
        num=(int)me->query_skill("tangshi-jian",1)/5+(int)me->query_skill("mantian-huayu",1)/5;
        if (!me)
        {
        me->delete_temp("skill_mark/huihuan");
        return 1;
        }
        if (!(objectp(present(target->query("id"), environment(me)))))
        {
        me->delete_temp("skill_mark/huihuan");
        return 1;
        }
        if(!living(target))
        {
        me->delete_temp("skill_mark/huihuan");
        return 1;
        }
        if( me->query_temp("weapon") )
        {
        me->delete_temp("skill_mark/huihuan");
        return 1;
        }
        if( me->query("force")< 1000 )
        {
        me->delete_temp("skill_mark/huihuan");
        return 1;
        }
        message_vision(HIG"$N凝神而立，持镖在手，当$n全神贯注于$N的暗器之时，\n一把长剑却如毒蛇般悄无声息地袭来，且等$n有所察觉，一道寒光又飞向$n的面门！！\n"NOR,me,target);
        if( target->query_skill("dodge")+target->query_skill("parry") < random((me->query_skill("sword") + me->query_skill("throwing"))*4/3))
        {
        message_vision(HIR"$n此时已心力交困，再无能力躲避，纵横江湖数十年，终于体会到了“人为刀俎，我为鱼肉”的感觉！！\n然而此刻已不容其多想，疼痛正在逐渐的消失，取而代之的是更为钻心的苦楚！！\n"NOR,me,target);
        target->apply_condition("tm_poison",10);     
        target->update_condition();
        target->receive_wound("kee",num*10);
        }else if(  random( target->query_skill("dodge") ) >  me->query_skill("sword")  )
        {  
        message_vision(HIY"$n疾往上纵，但体内的真气已渐渐不纯，只跃起八尺多高，\n好在$N旨在攻其下盘，这才险险避开！\n"NOR,me,target);    
        target->start_busy(2+random(2));
        }
        me->add_temp("apply/damage", num);
        me->add_temp("apply/attack", num);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        me->add_temp("apply/damage", -num);
        me->add_temp("apply/attack", -num);
        me->add("force", -200);
                if(random(num)+100>200 )
                {
                remove_call_out("pfm3");
                call_out("pfm3", 3, me, target);
        message_vision(HIM"回旋镖"+HIC"在空中划了一道美丽的弧线，仍然盘旋在$n的四周。\n"NOR,me,target);

                }
                else
                {
        message_vision(HIM"回旋镖"+HIG"好像摆脱了$n的控制，如脱缰的野马飞射了出去！\n"NOR,me,target);
                me->delete_temp("skill_mark/huihuan");
                }
        return 1;

}

