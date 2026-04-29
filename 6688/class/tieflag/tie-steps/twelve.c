//twelve.c 铁血十二式

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

string *seduce_msg = ({
        HIG"\n$N身形飘忽，一招"+HIR"「穿云势」"+HIG"拔地而起，却瞬间从九霄直击而下，$n只觉得头顶发亮，耳边风声烈响！\n",
        HIG"\n$N身随意转，一式"+HIR"「破雾势」"+HIG"，全身化作无数虚影弥漫在丈许空间，$n只觉得处处都是$N的身影！\n",
        HIG"\n$N身形往上一拔，一招"+HIR"「开天势」"+HIG"，腾空而起，却悬于半空，好似天神般注视着$n！\n",
        HIG"\n$N气聚丹田，一招"+HIR"「劈地势」"+HIG"，身形急缩，四周顿时空空如也，只留下$n一个人独自纳闷。\n",
        HIG"\n$N身形往上一拔，一招"+HIR"「推山势」"+HIG"，气吞山河之势顿向$n直逼了过来。\n",
        HIG"\n$N身形晃动，一招"+HIR"「搅海势」"+HIG"，全身化作无数虚影，在$n的周身四处荡起了无数的漩涡。\n",
        HIG"\n$N真气荡漾，如雷霆般大喝一声，一招"+HIR"「雷针势」"+HIG"，身形竟然极速向$n撞了过来！\n",
        HIG"\n$N使出"+HIR"「电箭势」"+HIG"，身形如电般地四处游走，带起的一道道寒芒直刺$n的双目！\n",
        HIG"\n$N身影展动，一招"+HIR"「龙腾势」"+HIG"，身形凌空飞起，如苍龙般长啸一声，刹那间雷鸣电闪！\n",
        HIG"\n$N腾空一跃，双脚向前一踢，一招"+HIR"「虎扑势」"+HIG"，如猛虎下山、饿虎扑食般向$n冲了过来！\n",
        HIG"\n只见$N身影一晃，一式"+HIR"「豹跃势」"+HIG"，那瞬时的加速度以及爆发力已非常人所能想象！\n",
        HIG"\n$N使一招"+HIR"「鹰飞势」"+HIG"，身子轻轻飘了开去，正待临空搏击，无论方位还是角度，都将是$n想象不到的！\n",
});

string *response_succeed = ({
        HIW"$n被眼前的情景惊得目瞪口呆，一时间也不知道是该攻击还是防御，竟然傻呆呆的怔在那里！\n"NOR,
        HIW"$n发现$N空门大开，处处都是破绽，兴奋之余，却忘记自己身上的破绽早已不计其数！\n"NOR,
        HIW"$n一心想告诉自己眼前的只是幻象，无奈神已破，精已散，何去何从已由不得自己控制！\n"NOR,
});

string *response_fail = ({
        HIY"$n守着灵台一丝清明，丝毫不为眼前的幻想所迷惑。\n"NOR,
        HIY"$n志定心坚，一切皆为过眼云烟，紧守周身各处要穴，不断的从$N身上找寻破绽。\n"NOR,
        HIY"$n潜运玄功，稳若磐石，无论$N飘逸到哪个方位，好像都和自己浑无关系。\n"NOR,
});  


int perform(object me, object target)
{
        string msg;
        int skill,ap,dp;

        if( !target ) target = offensive_target(me);
                                                                              
        if( !me->visible(target) )
                return notify_fail("你要对谁使用「铁血十二式」？\n");
                                                                                              
        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("牵制攻击只能对战斗中的对手使用。\n");

        if( target->is_busy() )
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧。\n");

        if( (int)me->query_skill("tie-steps", 1)  < 100 )
                return notify_fail("你的铁血十二式不够娴熟，不会使用「铁血十二式」。\n");

        if(  (int)me->query_skill("force") < 200 )
                return notify_fail("你的内功等级不够，无法使用「铁血十二式」。\n");

        if( (int)me->query("kee") < 100 ) return notify_fail("你的气不够！\n");
        if( (int)me->query("force") - (int)me->query("max_force") < 300 )
                return notify_fail("你的真气不够！\n");

        me->add("force",-300);

        msg = seduce_msg[random(12)];

        ap = me->query_skill("dodge")+ me->query_int() + me->query_cps() + me->query_cor() - me->query("bln");
        ap = (ap/10)*ap*ap; 
                        
        dp = target->query_skill("dodge") + target->query_int() + target->query_spi() + target->query_cps(); 
        dp = (dp/10)*dp*dp; 
        if ( target->query("id") == "long xiang") ap = ap/4;
        if ( target->query("id") == "buzhi huowu") ap = ap/4;
                       
        if( !userp(target) )
                dp = dp/2; // 对npc赚一点
        
                
        if( random(ap+dp) > dp ) 
        {
                msg += response_succeed[random(3)];
                target->start_busy( (int)me->query_skill("tie-steps",1) / 30 + 1 );
                message_vision(msg,me,target);   
                me->start_busy(1);
                return 1;
        }
        else    //fail
        {                
                msg += response_fail[random(3)];
                message_vision(msg,me,target);                                                              
                me->start_busy(4);

                return 1;
        }
}

