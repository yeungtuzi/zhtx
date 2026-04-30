#include <ansi.h>
#include <combat.h>
inherit F_DBASE;
inherit SSERVER;    

int judge(object me,object victim)
{
        int level,mp,dp;
        level = me->query_skill("sword"); 
        mp = level*level*level/2; 
        dp = victim->query("combat_exp");
        if( !userp(victim) )
        dp /= 2; // 对npc赚一点

        if( random(mp+dp)>dp )
                        return 1;
                else return 0;
}


int perform(object me, object target)
{
        // 2026-04-30: unused variable commented out
        // string msg;
        int count,skill_level; 
        object weapon,ob;
        skill_level = me->query_skill("pixie-sword",1);

        if( !target ) target = offensive_target(me);

        if( !me->is_fighting() )
                return notify_fail("「刺目」只能在战斗中使用。\n");

        if( !me->visible(target) ) 
                return notify_fail("你要对谁使用「刺目」？\n");

        if( !objectp(weapon = me->query_temp("weapon")) || weapon->query("id") != "xiuhua zhen" || !weapon->query("equipped"))
                return notify_fail("手中没有绣花针，如何使用「刺目」？\n");

        if( me->query_skill_mapped("force") != "kuihua-shengong")
                return notify_fail("你是太监，怎么可以用其他的内功，不怕走火入魔？！\n");

        if( (int)me->query("force") < 1000 ) 
                return notify_fail("你的内力不够！\n");

        if( skill_level < 200 )                              
                return notify_fail("你辟邪剑法的修为太浅！\n");

        
                message_vision(HIM "突然之间，$n只觉眼前有一团粉红色的物事一闪，似乎$N的身子动了一动，\n一枚极细的绣花针向$n疾刺而到！\n" NOR, me, target);
        
        if(judge(me,target)) {

               if(target->query("con")> random(skill_level/2)){//对方体质比较好，不至于一下给刺挂了。
               message_vision(HIW"\n$n觉得左颊微微一痛，随即强运真气抵御，\n"+HIY"好在$N这一针出手太急，没刺中$n的人中要穴，\n"+HIR"但疮口处已然迸射出一道血线，滴滴答答溅了一地。\n" NOR, me, target);
               target->set_temp("last_damage_from",me);
               target->receive_damage("kee",me->query("force_factor")*2+random(300));
               target->receive_wound("kee",me->query("force_factor")*2+random(300));
               COMBAT_D->report_status(me,target,1); 

               }else if (target->query("bln") > random(skill_level/3))  {//对方平衡的能力如何
               message_vision(HIR"\n但见红影闪处，似有一物向$n左目戳来！\n"+HIY"此刻$n已不及挡架，又不及闪避，只好侧头一让，但觉眉心一阵钻心的剧痛，\n"+HIB"幸好$N并未贯注全部真力，但被刺之苦楚已非蜂蛰蛇咬所能比了。\n" NOR, me, target);
               target->set_temp("last_damage_from",me);
               target->receive_wound("kee",me->query("force_factor")*4+random(500));
               target->receive_wound("gin",me->query("force_factor")*2+random(250));
               target->receive_wound("sen",me->query("force_factor")*2+random(250));
               COMBAT_D->report_status(me,target,1); 
 
               }else{ //这下可是结结实实给干上了。
               message_vision(HIG"\n猛听得$n大叫一声，兵刃落地，一个筋斗翻开了出去，"+HIW"\n双手按住右目，满地翻滚，连声惨嚎，这只眼睛已被$N刺瞎！！\n" NOR, me, target);
               target->set_temp("last_damage_from",me);
               target->receive_wound("kee",target->query("max_kee")*skill_level/1000+400+random(800));
               target->set("force_factor", 0);
               COMBAT_D->report_status(me,target,1); 
               target->start_busy(5);
                      if(target->query_temp("weapon"))
                      {
                      ob = target->query_temp("weapon");
                      ob->unequip();
                      ob->move(environment(target));
                      }
               }         
               me->start_busy(1);
        } else {
               if( random(target->query_skill("force")) > me->query_skill("sword")){ //内功强的兵器就飞了。
               message_vision(HIY"\n$n体内的真气遇激而发，一股强大的气旋在$n周身四处膨胀开来，顿时将$N的绣花针震的无影无踪。\n" NOR, me, target);
               weapon->unequip();
               weapon->move(environment(me));               
                      me->start_busy(4);
               }else{
               message_vision(HIC"\n$n屏息凝气，侧耳倾听，$N的绣花针虽无破空之声，\n但$n还是用直觉感到其方位所在，施展腾挪之术，险险避开了$N电闪雷鸣般的一击！！\n" NOR, me, target);
               me->start_busy(3);
               }

        }
        me->add("force",-300);
        return 1;
}

