// /daemon/class/legend/floodspeak/flood.c

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        // 2026-04-30: unused variable commented out
        // string msg;
        int ap, dp, damage;
        object ob;

        if( !me->is_fighting() )
                return notify_fail("「噪音攻击」只能在战斗中使用。\n");
        if( (int)me->query("kee") < 140 ) return notify_fail("你的气不够！\n");
        if( (int)me->query("force") - (int)me->query("max_force") < 140 )
                return notify_fail("你的真气不够！\n");
        me->clean_up_enemy();
        ob = me->select_opponent();
        if( !ob || (environment(ob) != environment(me))) break;
        else {
                damage = 30 + random(me->query_skill("floodspeak", 1))*2;
                ap = me->query_skill("literate")*2 + damage;
                dp = ob->query_skill("parry", 1);
                if( dp < 1 )
                        dp = 1;
                if( random(ap) > dp )
                {
                        if(userp(me)) {
                                me->add("force", -140);
                                me->add("kee", -140);
                        }
                message_vision(CYN 
"$N口沫横飞,不知嚷嚷些什么,$n听得头昏脑胀...\n" NOR, me, ob);
                ob->receive_damage("gin", damage);
		ob->receive_damage("sen", damage);
                ob->start_busy(1+random(5));
                }
                else {
                        if(userp(me)) {
                                me->add("force", -140);
                                me->add("kee", -140);
                        }
                message_vision(CYN
"$N口沫横飞,不知嚷嚷些什么,$n充耳不闻,不予理睬\n" NOR, me, ob);
                me->start_busy(3);
                }
        }
        return 1;
}

