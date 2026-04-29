// 移魂大法
// yihun.c
// by masterall

#include <ansi.h>

inherit F_SSERVER;
int exert(object me, object target)
{
        int sp, dp;


        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「移魂大法」只能对战斗中的对手使用。\n");

        if( target->is_busy() )
                return notify_fail(target->name() + "已经自顾不暇了，放胆进攻吧。\n");

        if( (int)me->query_skill("jiuyin-shengong",1) < 50 )
        return notify_fail("你的九阴神功功力不够，不能使用移魂大法！\n");

        if( (int)me->query("force") < 500 )
                return notify_fail("你的内力不够，不能使用移魂大法。\n");

message_vision
(HIW"$N按九阴真经中所载止观法门，运起移魂大法。\n
$N由「制心止」而至「体真止」，宁神归一，竟无半点杂念，眼光呆呆的瞪著$n！！\n\n" NOR, me,target );

        if( living(target))
//                if( !target->is_killing(me) )
//                        target->kill_ob(me);

        sp = me->query_skill("force") + me->query_cps();
        dp = target->query_skill("force")+target->query_cps();
        
        if ( random(sp+dp) > dp  || !living(target) )
        {
message_vision
(HIW "$n忽然觉得脑中一片空白，呆呆一愣，随即$N做什么，$n也都依样模仿！！\n
$N脸上微微一笑，$n也跟著$N作态一笑，旁观众人无不毛骨悚然！！\n"NOR, me,target );

                target->receive_wound("gin", 100 + 
                        random((int)me->query_skill("jiuyin-shengong", 1)) );
                target->start_busy((int)me->query_skill("jiuyin-shengong", 1)/20+1);
                me->add("force", -300);
        }
        else
        {       
message_vision(HIY "可是$p不为$P怪异表情所动，定力果然不同凡响！\n"NOR,me,target);
                me->start_busy(4);
        }
        return 1;
}

