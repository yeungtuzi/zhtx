//bhcs.c 碧海潮生曲
//by masterall

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        object *ob;
        object ob2;
        int i, skill, damage, ap, dp;

        if( !me->is_fighting() )
                return notify_fail("『碧海潮声曲』只能在战斗中使用。\n");

        if( (int)me->query("force") < 1000)
                return notify_fail("你的内力不够。\n");

        if( (int)me->query_skill("taohua-force", 1) < 180)
                return notify_fail("你的桃花内功不够。\n");

        if( (int)me->query_skill("music", 1) < 150)
                return notify_fail("你的丝竹之技不够。\n");

        if (!objectp(ob2 = present("yu xiao",me) ) )
                return notify_fail("你身上没有玉箫，拿什么吹『碧海潮生曲』？！\n");  




        skill = me->query_skill("taohua-force",1) + me->query_skill("music", 1)/2;

        me->add("force", -500);

        me->start_busy(5);
        message_vision(HIY"$N闭目运气，心神归一，吹奏出一缕幽幽的箫声，"+HIG"\n犹似巫峡猿啼、子夜鬼哭，又好比昆岗凤鸣，深闺私语。一会极尽惨厉凄切，一会却又柔媚宛转。"+HIB"\n箫声忽高忽低，时而如龙吟狮吼，时而如狼嗥枭鸣，或若长风振林，或若微雨湿花，极尽千变万化之致。\n" NOR, me);

        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++) {
                if( !living(ob[i]) || ob[i]==me ) continue;

                // 防止采用这个pk,只对和自己战斗中的玩家有效 yeung
                if( userp(ob[i]) && !me->is_fighting(ob[i]) ) continue;

                ap = skill *  me->query("force");
                dp = ((int)ob[i]->query("cps") + ob[i]->query_skill("music", 1) )* ob[i]->query("force");
                
                if( random(ap) > dp){
                message_vision(HIC"\n$n渐感心旌摇动，伴随着箫声的旋律上下跳跃，前窜后蹦，模样甚是滑稽。\n$N玉箫一离唇边，$n狂乱之势登缓，$N箫声一急，$n便又如狂魔般乱舞了起来。\n" NOR, me,ob[i]);
                ob[i]->receive_wound("gin", me->query("max_gin")/2 +skill);
                ob[i]->receive_wound("sen", me->query("max_sen")/2 +skill);

                }else if ( random(ap + dp/2 ) > dp){
                message_vision(HIW"\n$N脸现惊惶之色，急忙撕裂衣襟，先在耳中紧紧塞住，\n再在头上密密层层的包了，只怕漏进一点声音入耳。\n怎奈悠扬的箫声直入心脉，$N只觉得全身气血翻涌，五脏六腑好像开了锅一般难受。\n" NOR, ob[i]);
                ob[i]->set_temp("apply/attack",1);
                ob[i]->set_temp("apply/defense",1);
                ob[i]->set_temp("apply/dodge",1);
                ob[i]->set_temp("apply/parry",1);
                ob[i]->set_temp("apply/armor",1);
                ob[i]->set_temp("apply/armor_vs_force",1);
                ob[i]->add("force", -1*ob[i]->query("force")/3);

                }else if ( random(ap + dp ) > dp) {
                message_vision(HIR"\n$N感到箫声每一音都和自己心跳相一致，箫声一起，$N的心立即一跳。\n箫声越快，自己心跳也逐渐加剧，只感胸口怦怦而动，极不舒畅。\n" NOR, ob[i]);
                ob[i]->receive_wound("kee", random(ob[i]->query("max_kee"))/4);
                ob[i]->add("force", -1*random(ob[i]->query("force"))/4);
                }
        
                else{
                message_vision(HIG"\n$N当下凝守心神，不为乐声所动，但这荡气回肠的乐律还是让$N有些乐不思蜀。\n" NOR, ob[i]);
                ob[i]->start_busy(3);
                }

                if( userp(ob[i]) ) ob[i]->fight_ob(me);
                else if( !ob[i]->is_killing(me) ) ob[i]->kill_ob(me);
        }

        return 1;
}

