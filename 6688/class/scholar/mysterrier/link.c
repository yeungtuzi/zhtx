#include <ansi.h>

inherit SSERVER;
int judge(object me,object victim)
{
            int level,mp,dp;
        level = me->query_skill("dodge"); //200max
        mp = level*level*level; //400万
        dp = victim->query("combat_exp");//368万max
        if ( victim->query("id") == "long xiang") mp = mp/3;
        if ( victim->query("id") == "buzhi huowu") mp = mp/3;
        if ( victim->query_skill("dagou-bang", 1) > 200) mp = 0;
        mp = mp/100;
        dp = dp/100;
        if( random(mp+dp)>dp )
                        return 1;
                else return 0;
}
int perform(object me, object target)
{
        // 2026-04-30: unused variable commented out
        // object soldier;
        string msg;
        int num;

        if( !objectp(target) ) target = me->select_opponent();
        if( !objectp(target) )
                return notify_fail("「四式连环」只能对战斗对手使用。\n");
        
        if( me->query("betrayer") )
                return notify_fail("你不是步玄派正宗弟子，还没学会使用步玄七诀「四式连环」。\n");

        if( !me->query("got_ling") )
                return notify_fail("你还没有得到赏善罚恶令，未将步玄派发扬光大，不配使用这惊世绝学。\n");
        if( !me->query("can_link") )
                return notify_fail("这是步玄派不传之秘，你现在还不会使用。\n");

        if( me->query_temp("mysterrier") )                 
                return notify_fail("你已经在运功中了。\n");

        if( me->query("force") < 1000 ) return notify_fail("你的内力不够，无法使用「四式连环」！\n");

        if( me->query_skill("mysterrier",1) <250 ) return notify_fail("你的步玄七诀等级太低。\n");

        
        msg = HIY "$N身形飘渺不定，如风中柳絮，在$n身周忽进忽退，随即化做七道虚影射向$n！！\n\n"+HIG"这便是步玄派失传已久的『四式连环』！！\n\n  "+HIW"第二式「飘絮随风」！\n\n    "+HIB"第四式「七星追月」！\n\n      "+HIM"第五式「春梦无痕」！\n\n        "+HIC"第六式「凤舞九天」！\n\n" NOR;
        
        me->add("force",-500);
        num = me->query_skill("mysterrier",1)/15;
        
                if(judge(me,target))
                {
                me->set_temp("mysterrier",1);
                msg += YEL"        $n被扰得眼花缭乱，应接不暇！！\n\n    $n一时竟无法发动攻击！！！！！！！\n\n$n惊慌间方寸大乱，进退失度！！！！！！\n"NOR;
                target->add_temp("apply/attack",-num);
                target->add_temp("apply/defense",-num);
                me->add_temp("apply/defense",num);
                target->start_busy(me->query_skill("mysterrier",1)/30+1);

                if( userp(target) )
                      target->add_temp("apply/composure",-num);
                else
                      target->add("cps",-num);

               me->start_call_out( (: call_other, __FILE__, "remove_effect", me, target, num:), num*2);
               me->start_busy(1); 
                }
                else
                {
                   msg += HIR"$n凝神定气，丝毫不为$N的幻象所迷惑。\n"NOR;
                   me->start_busy(3);
                }
        message_vision(msg, me, target);
        return 1;
}

void remove_effect(object me,object target,int amount)
{
        if( objectp(me) )
        {
                me->delete_temp("mysterrier");
                me->add_temp("apply/defense", -amount);
                tell_object(me,HIC"你的「四式连环」效果消失了。\n"NOR);
                if( objectp(target) )
                {
                tell_object(target,me->query("name")+"的身影渐渐散去，你慢慢恢复了正常...\n");
                target->add_temp("apply/attack",amount);
                target->add_temp("apply/defense",amount);

                if( userp(target) )
                       target->add_temp("apply/composure",amount);
                else
                       target->add("cps",amount);

                }
        }
        return;
}

