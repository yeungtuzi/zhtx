// sheng_si_fu.c

#include <ansi.h>

inherit SSERVER;
#include <combat.h>

int start_hehe(object me, object target);

int perform(object me, object target)
{
        string msg,*limbs;
        int ap, dp;
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me
        ||      !me->is_fighting(target) )
                return notify_fail("此招只能对战斗中的对手使用。\n");
        if( !objectp(present(target->query("id"), environment(me)))&&!target->query_temp("mask_cloth") )
                return notify_fail("你的对手并不在这儿啊！\n");

        if( (int)me->query_skill("liuyang-zhang",1) < 120)
                return notify_fail("你还不会这个手法。\n");
        if( !me->query("skill_mark/sheng_si_fu") )
                return notify_fail("你还不会这个手法。\n");
        if( me->is_busy() )
                return notify_fail("你正忙着了。\n");
        if( me->query_temp("weapon") )
               return notify_fail("种生死符必须空手。\n");
        if( (int)me->query("force") < 100 )
                return notify_fail("你的内力不够。\n");
        if( (int)me->query("kee") <30)
                return notify_fail("你的精神没法集中。\n");
        if( !me->is_killing(target->query("id")) )
                return notify_fail("双方只是比武较技，何必下杀手？\n");
        if(userp(target))
                return notify_fail("这么阴毒的功夫你还是别用了，省得缺德到家会被骂得很惨。\n");
        if(target->query_condition("sheng_si"))
                return notify_fail("对方体内已经有生死符了，不要这么残忍吧？！\n");
//      if( environment(me)->query("no_fight"))
//              return notify_fail("这儿不准杀人。\n");

        me->add("force", -300);
        me->receive_damage("kee", 20);

        
        tell_object(me, HIB"你左掌掌心暗运内功，逆转真气。\n"NOR);
        me->start_busy( (: start_hehe, me, target :) );
        me->set_temp("zhong_sheng_si_fu", 3);
        me->set_temp("my_kee", me->query("kee"));
        me->add_temp("apply/defense", 50);
        return 1;
}

int start_hehe(object me, object target)
{
        int ap, dp,skill;
        skill= me->query_skill("liuyang-zhang",1);

        me->add_temp("zhong_sheng_si_fu", -1);
        if( me->query_temp("zhong_sheng_si_fu") )       return 1;
        if( me->query("kee") < me->query_temp("my_kee")){
                me->delete_temp("my_kee");
                return 0;
        }
        if( !me->visible(target) && !me->query_skill("perception") ) return 0;
        if( !living(me) )       return 0;

        me->delete_temp("zhong_sheng_si_fu");
        me->add_temp("apply/defense", -50);
        tell_object(me,HIB"不多时你已将空中的水气凝成几片薄薄的冰片。\n"NOR);
        message_vision(HIR"\n\n$N对着$n轻飘飘地隔空挥出一掌，招式中夹着一股阴寒无比的劲风！\n"NOR, me, target);

        ap = me->query_skill("strike") + me->query_skill("force");
        dp = target->query_skill("dodge") + target->query_skill("force");
        if( !me->visible(target) )
                dp = dp * target->query_skill("perception") / 150;
        if( random(ap + dp) > dp ){
                
                if(skill>120)
                {
                message_vision(HIY"\n$N猛地里肩间"+HIG"“缺盆穴”"+HIY"上微微一寒，便如碰上了一片雪花。\n"NOR, target);
                target->apply_condition("sheng_si", 81*60); 
                target->update_condition("sheng_si");
                COMBAT_D->report_status(me,target,1);  
                }
                if(skill>150 && random(me->query("force") + target->query("force"))>target->query("force") )
                {
                message_vision(HIB"\n$N跟着小腹"+HIG"“天枢穴”"+HIB"也是一阵冰冷，似是吞了口冰块下去，那不是凉爽的惬意，而是刺骨的极寒！\n"NOR, target);
                target->apply_condition("sheng_si", 81*60);  
                target->update_condition("sheng_si");
                target->add("force",-1*me->query("force")/4);
                COMBAT_D->report_status(me,target,1);  
                }
                if(skill>199 && random(me->query("force") + target->query("force"))>target->query("force"))
                {
                message_vision(HIC"$N大腿"+HIG"“伏兔穴”"+HIC"上一阵阵寒意袭来，动作顿时有些不大灵光，好似被冻僵了一般麻木。\n"NOR, target);
                target->apply_condition("sheng_si", 81*60);  
                target->update_condition("sheng_si");
                target->start_busy(5);
                COMBAT_D->report_status(me,target,1);  
                }
                if(skill>220 && random(me->query("force") + target->query("force"))>target->query("force"))
                {
                message_vision(BLK"$N上臂"+HIG"“天泉穴”"+BLK"好像被什么东西斫了一下，顿时半个膀子耷拉下来，变得绵软无力，贯注不得办点真力！！\n"NOR, target);
                target->apply_condition("sheng_si", 81*60);  
                target->update_condition("sheng_si");
                target->set("force_factor",target->query("force_factor")/2);
                COMBAT_D->report_status(me,target,1);  
                }
                if(skill>250 && random(me->query("force") + target->query("force"))>target->query("force"))
                {
                message_vision(HIM"$N觉得后颈"+HIG"“天柱穴”"+HIM"微微一凉，还不断在纳闷，“今天好像没下雨啊！”\n"NOR, target);
                target->apply_condition("sheng_si", 81*60);  
                target->update_condition("sheng_si");
                target->receive_wound("gin",random(target->query("gin"))/4);          
                COMBAT_D->report_status(me,target,1);  
                }
                if(skill>279 && random(me->query("force") + target->query("force"))>target->query("force"))
                {
                message_vision(HIR"$N背心"+HIG"“神道穴”"+HIR"好像被什么人踢了一脚，身子竟朝前跌到，好在$N急定身形，这才稳住脚下的步法。\n"NOR, target);
                target->apply_condition("sheng_si", 81*60);  
                target->update_condition("sheng_si");
                target->receive_wound("sen",random(target->query("sen"))/4);  
                COMBAT_D->report_status(me,target,1);  
                }
                if(skill>300 && random(me->query("force") + target->query("force"))>target->query("force"))
                {
                message_vision(HIW"$N后腰"+HIG"“志室穴”"+HIW"觉得麻痒难当，直如千千万万只蚂蚁同时在咬啮一般！\n"NOR, target);
                target->apply_condition("sheng_si", 81*60); 
                target->receive_wound("kee",random(target->query("kee"))/2);   
                target->update_condition("sheng_si");
                target->update_condition("sheng_si");
                target->update_condition("sheng_si");
                COMBAT_D->report_status(me,target,1);  
                }
        }       
        else{
                message_vision(HIY"$N察觉形势不妙，危急中奋力往旁边一跃，避开了$n的掌风！\n"NOR, target, me);
                me->start_busy(3);
                return 0;

        }
        return 0;
}

