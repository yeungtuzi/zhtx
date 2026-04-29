//dianxue.c 点穴诀
//by masterall
//2003.6.20

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        object weapon,ob;            
        int ap,dp,level,imax;
 
        imax=(int)me->query("max_force");

        if( !target ) target = offensive_target(me);

                                                                              

        if( !me->is_fighting() )
                return notify_fail("「点穴诀」只能对战斗中的对手使用。\n");

        if( !me->visible(target) )
                return notify_fail("你要对谁使用「点穴诀」？\n");
                                                                                              
   //     if (objectp(weapon = me->query_temp("weapon")))
   //             return notify_fail("只有空手才能够使用「点穴诀」。\n");


        if( !me->is_fighting() )
                return notify_fail("「点穴诀」只能对战斗中的对手使用。\n");


        if( me->query_skill_mapped("force") != "beiming-shengong")
                return notify_fail("你必须使用北冥神功才能使出「点穴诀」！\n");
 

//        if( (int)me->query_temp("dianxue") )               
//                return notify_fail(target->name() + "穴道已经被封了，放胆进攻吧。\n");

        if( (int)me->query_skill("liumai-shenjian", 1)< 150 )
                return notify_fail("你的六脉神剑不够娴熟，不会使用「点穴诀」。\n");

        if(  (int)me->query_skill("force",1) < 200 )
                return notify_fail("你的内功等级不够，无法使用「点穴诀」。\n");

        if( (int)me->query("kee") < 100 ) return notify_fail("你的气不够！\n");

        if( (int)me->query("max_force") < 3000 ) return notify_fail("你的内力不够！\n");
        if( (int)me->query("force") - (int)me->query("max_force") < 300 )
                return notify_fail("你的真气不够！\n");

        me->add("force",-1000);

        msg = HIG "$N潜用内力激发起六脉神剑的剑气，直逼向$n周身各大穴道！\n" NOR;

        me->start_busy(1);

        ap = me->query_skill("liumai-shenjian",1);
        ap = ap*ap*ap/3;
        dp = me->query("betrayer");
        //对叛师的惩罚
        while(dp--)
                ap /= 4;        
        ap += me->query("combat_exp")*2; 
                        
        dp = target->query_skill("liumai-shenjian",1) + target->query_int() + target->query_spi() + target->query_cps(); 
        dp = dp*dp*dp; 
        dp += target->query("combat_exp")*2; // 1440万                          
        if( !userp(target) )
                dp /= 2; // 对npc赚一点
        
                
        if( random(ap+dp) > dp ) {

                
                if( (int)me->query("force_factor") < 51 )
                  {    
                msg += HIW"\n结果$P的少泽剑气正中$p的“足三里”穴，$p只觉得手脚一阵发木，展转腾挪有些不大灵光！\n" NOR;
                level=me->query_skill("liumai-shenjian",1)/6;
                me->set_temp("dianxue",1);
                target->add_temp("apply/attack",-level);
                target->add_temp("apply/dodge",-level);
                me->start_call_out( (: call_other, __FILE__, "remove_effect", me, target, level:), level*6);
                  }

                if( (int)me->query("force_factor") > 50 
                &&  (int)me->query("force_factor") < 101)
                  {
                msg += HIM"\n结果$P的少冲剑气正中$p的极泉穴，$p只觉得全身一阵酸麻，半晌不能动弹！\n" NOR;
                target->start_busy( (int)me->query_skill("liumai-shenjian",1) / 20 + 1 );
                  }

                if( (int)me->query("force_factor") > 100
                &&  (int)me->query("force_factor") < 151)
                  {
                msg += HIG"\n结果$P的关冲剑气正中$p的“手少阴心经”穴，$p立即觉得真气在$P剑气的牵引下飞泻而出！\n" NOR;
               target->set_temp("last_damage_from",me);
                target->add("force",-imax/3);
                me->add("force",imax/3);
                target->start_busy(2);
                  }

                if( (int)me->query("force_factor") > 150 
                &&  (int)me->query("force_factor") < 201)
                  {
                if(!objectp(ob=target->query_temp("weapon")) )
                return notify_fail(HIY"对方手中都没兵刃了，点他作甚？\n"NOR);
                ob = target->query_temp("weapon");
                msg += HIY"\n结果$P的中冲剑气正中$p的“手太阴肺经”穴，$p只觉得手腕一阵酸麻，" NOR + ob->name() + HIY "再也拿捏不住，脱手飞出！\n" NOR;
                ob->unequip();
                ob->move(environment(target));
                target->start_busy(2);
                  }
                    

                if( (int)me->query("force_factor") > 200 
                &&  (int)me->query("force_factor") < 251)
                  {
                msg += HIC"\n结果$P的商阳剑气正中$p的大锥穴，$p只觉得周身各大穴道有无数只蚂蚁在乱窜，顿时精力涣散！\n" NOR;
               target->set_temp("last_damage_from",me);
                target->receive_wound("kee",(int)me->query("max_kee")/4);
                target->receive_wound("gin",(int)me->query("max_gin")/4);
                target->receive_wound("sen",(int)me->query("max_sen")/4);
                target->start_busy(2);
                  }

                if( (int)me->query("force_factor") > 250)
                  {
                msg += HIR"\n结果$P的少商剑气正中$p的膻中穴，$p只觉得全身气血翻涌，\n真气难以抑制，“哇”的一声吐出一口鲜血！\n" NOR;
               target->set_temp("last_damage_from",me);
                target->start_busy(2);
                target->receive_wound("kee",(int)me->query("max_kee")/2);
                target->set("force_factor",0);
                  }


        } else {
                msg += HIY"可是$p纵跃闪躲，避开了$P凌厉的剑气。\n" NOR;       
                me->start_busy(4);
        }
        message_vision(msg, me, target);
              COMBAT_D->report_status(me,target,1); 

        return 1;

}

void remove_effect(object me,object target,int amount)
{

                me->delete_temp("dianxue");
                tell_object(me, target->name() +HIW"潜用内力撞开了被封的穴道，顿时行动恢复正常...\n" NOR);
               target->set_temp("last_damage_from",me);

                target->add_temp("apply/dodge",amount);
                target->add_temp("apply/attack",amount);
                target->add("force",-400);
}

