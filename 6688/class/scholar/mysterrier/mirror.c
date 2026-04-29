#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        object soldier,env;
        string msg;
        int num,my_num;

        if( !me->is_fighting() )
                return notify_fail("「分身化影」只能在战斗中使用。\n");

        if( me->query("family/family_name") != "步玄派")
                return notify_fail("你不是步玄派正宗弟子，还没学会使用步玄七诀这一式。\n");
                                
        if( me->query("force") < me->query("max_force")+700 ) return notify_fail("你的内力不够，无法使用「分身化影」！\n");
        num = me->query_skill("mysterrier",1)/33+1;

        if( num < 4 ) return notify_fail("你的步玄七诀等级太低。\n");
        if( num > 9 ) num = 9;

        if( me->query_temp("mystshadow") >= num ) return notify_fail("你现在无法支持更多的化身了！\n");

        if( !target ) target = offensive_target(me);

//        if( !me->is_killing(target->query("id")) )
//                return notify_fail("双方只是比武较技，何必下杀手？不要仗着人多势众就欺负人！\n");

        
        num -= me->query_temp("mystshadow");
        msg = YEL "$N使出步玄七诀第三式「分身化影」，身形滴溜溜地急速了几个圈子，而后$N突然幻化出数道身影！\n" NOR;
        message_vision(msg, me);
        my_num = random(num);
// 加入判定，如果用mirror必须和对方性命相搏
/*
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else                            target->kill_ob(me);
                }
                me->kill_ob(target);
        }
*/

                
        
          me->set_temp("pfm/scholar",1);
        seteuid(getuid());      

        while( num-- )
        {
                soldier = new("/obj/npc/shadow");

                soldier->move(environment(me));
                soldier->invocation(me);
                //原来me总是最后一个,敌人总是可以charge xxx 最后一个
                //现在要随机化
                if( num == my_num )
                {
                        env = environment(me);
                        me->move("/obj/misc/void",1);
                        me->move(env,1);
                }
                me->add("force",-100);
        }
        me->start_busy(num);
        return 1;
}

