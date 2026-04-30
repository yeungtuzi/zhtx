// 还是给七伤拳用更加合适??:P
// yeung
// 1998.7.19

#include <ansi.h>
#include <combat.h>
                               
inherit SSERVER;

string *cuff_msg = ({
        HIW "$N喝道：五行之气调阴阳！一股刚猛劲气罩住$n全身。" NOR,
        HIR "$N诡秘一笑，右拳带着一股阴柔之气轻飘飘地指向$n。" NOR,
        HIY "$N吟道：损心伤肺摧肝肠！一拳击出，刚中带柔，直扑$n的小腹。" NOR,
        HIG "$N双手轻挥，变拳为爪，柔中带刚地抓向$n下阴。" NOR,
        HIC "$N大吼一声，左拳横出，右拳直进！。" NOR,
        HIB "$N口中低吟：藏离精失意恍忽！面上神色诡异，突然双拳齐出！" NOR,
        HIM "“三焦齐逆兮魂魄飞扬”！宛如半空一声霹雳，$N双拳挟雷霆之威全力击出，再无虚招变化！" 

NOR,
});                  

string *hurt_msg = ({
        HIR "$n一皱眉，似乎是心脉伤了。\n" NOR,
        HIR "$n一皱眉，似乎是肺脉伤了。\n" NOR,
        HIR "$n一皱眉，似乎是肾脉伤了。\n" NOR,        
        HIR "$n一皱眉，似乎是脾脉伤了。\n" NOR,  
        HIR "$n一皱眉，似乎是肝脉伤了。\n" NOR,                        
        HIR "$n一皱眉，似乎是带脉伤了。\n" NOR,
        HIR "$n面色大变，哇地吐出一口鲜血，看来任脉伤势不轻！\n" NOR,
});                                                                  

int perform(object me, object target)
{
        string msg,name;
        int extra,i,lmt;
        // 2026-04-30: unused variable commented out
        // object weapon,tgt;
           
        extra = me->query_skill("cuff");
        if ( me->query_skill("qishang-quan",1) < 200) return notify_fail("你的七伤拳还不够纯熟！\n");
        if ( me->query("force") < 4000) return notify_fail("你的内力不够！\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［伤己伤人］只能对战斗中的对手使用。\n");
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("空手才可以使用［伤己伤人］。\n");
        msg = HIY  "$N须眉尽赤，狂吼一声，七重拳劲如惊涛骇浪向$n不停袭来！" NOR;
        message_vision(msg,me,target);
        me->add("force",-1000);
//      lmt = random(extra/50)+3;
        for(i=1;i<=7;i++)
        {
   

                msg = HIR "第"+chinese_number(i)+"重" NOR;                
                message_vision("\n\n"+cuff_msg[i-1],me,target); 
        me->add_temp("apply/attack",extra/5);
        me->add_temp("apply/damage",extra/5);       
                COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/attack",-extra/5);
        me->add_temp("apply/damage",-extra/5);

                if(!objectp(target) 
                   || target->is_ghost() 
                   || target->query("eff_kee") < 1
                   || (environment(me)!=environment(target))
                   || me->is_ghost())             
                {
                        message_vision(HIG"$N背负双手，冷冷一笑。\n"NOR,me);
                        break;
                } 
                message_vision(hurt_msg[i-1],me,target);  
     
                switch(random(3)){
                        case 0: target->receive_wound("kee",extra/4);write("kee");break;
                        case 1: target->receive_wound("gin",extra/4);write("gin");break;
                        case 2: target->receive_wound("sen",extra/4);write("sen");break;            

                        
                };
                
        }
        me->receive_wound("kee",random(me->query("kee"))/2);               
        me->receive_damage("gin",random(me->query("gin"))/2);               
        me->receive_damage("sen",random(me->query("sen"))/2);                      
        me->start_busy(3);
        message_vision(HIG"\n\n$N使完七伤拳后，元气大伤，看来需要好好休息了！\n"NOR,me);
        COMBAT_D->report_status(me,me,1);
        return 1;
}
