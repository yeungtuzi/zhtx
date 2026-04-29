// nian.c 太极拳「粘」字诀

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object ob;
        string msg;
        int skill,ap,dp;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("粘连粘随只能带动战斗中的对手。\n");

//        if( me->query("family/family_name") != "武当派")
//                return notify_fail("你不是武当正宗弟子，不会使用武当绝技！\n");

        if( me->query("faith") < 1500 )
                return notify_fail("你的门忠不够，不能使用「粘」字诀。\n");

        if( me->query_temp("weapon") ) 
                return notify_fail("你只能在空手时使用「粘」字诀！\n");

        if( objectp(ob = me->query_temp("pfm/wudang_nian")) )
        {
                if( ob->is_fighting(me) )
                        return notify_fail("你已经在粘连粘随对手了。\n");
        }

        if( (string)target->query("race") != "人类" )
                return notify_fail("有这个必要么？\n");

        if( me->query("force") < 500)
                return notify_fail("你的内力不够！\n");
                
        if( (skill = (int)me->query_skill("cuff")) < 100 )
                return notify_fail("你的太极拳极不够娴熟，不会使用「粘」字诀。\n");

        if( (int)me->query_skill("taiji-shengong", 1) < 80 )
                return notify_fail("你的太极神功修为不够，不会使用「粘」字诀。\n");

        msg = HIY "\n$N左手带着$n的右手，转了一个大圈，一股极强的螺旋力带动$p左手，正是太极云手。\n";

        ap= skill*skill*skill;
        dp= target->query("combat_exp");
        if( target->query("id") == "buzhi huowu" ) ap = ap/10;
        if( target->query("id") == "long xiang" ) ap = ap/10;
        if( random(ap+dp) > dp )
        {
                //msg += "结果$p被$P粘连得跌跌撞撞，身不由主的立足不稳，犹如中酒昏迷。\n" NOR;
                msg += "这云手连绵不断，一圈过后，又是一圈，$n的双掌似乎全给$P粘住了。\n"NOR;

                me->set_temp("pfm/wudang_nian", target);
                target->start_busy( me->query_skill("taiji-quan",1)/30 + 5 );
                me->add("force", -300);                
                me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), skill/10);      
        }
        else
        {
                switch( random(3) )
                {
                        case 0: msg += "$p急忙使出“千斤坠”之力定住身形。\n" NOR; break;
                        case 1: msg += "$p不敢便接，斜身闪开。\n" NOR; break;
                        case 2: msg += "$n全身内力一震，$P双手按他不住，被$p跃出圈外！\n" NOR; break;
                }
                me->start_busy(2 + random(2));
                me->add("force", -100);
        }
        message_vision(msg, me, target);
        return 1;
}

void remove_effect(object me)
{
        if( objectp(me->query_temp("pfm/wudang_nian")) )
        {
                me->delete_temp("pfm/wudang_nian");
                if( me->is_fighting() )
                        message_vision("\n$N劲力一松，粘力卸去。\n", me);
        }
}

