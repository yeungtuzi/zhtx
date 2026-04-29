//独孤九剑破气式
//by Emote 5/20/2000
#include <ansi.h>
#include "dugu.h"
inherit F_DBASE;
inherit SSERVER;

int do_prepare(object me,object target);
int interrupt_prepare(object me,object who,string reason);

void create() { seteuid(getuid()); set("name","江湖传说");set("id","rumord");}

int perform(object me, object target)
{
        int skill,tbusy;
        object ob;
        seteuid(ROOT_UID);
        if( !me->is_fighting() )
                return notify_fail("「破气式」只能在战斗中施用。\n");                                
        if( me->is_busy())
                return notify_fail("你正忙着呢，来不及用独孤九剑。\n");
        if( me->query("force") < 2000)
                return notify_fail("你的内力不够，用不了独孤九剑。\n");
        
        if (!objectp(ob = me->query_temp("weapon"))
        || (string)ob->query("skill_type") != "sword")
                return notify_fail("你手中无剑，如何使用独孤九剑的「破剑式」。\n");     
        
        if( userp(me) && (int)me->query("force") < 1600 ) return notify_fail("你的内力不够。\n");
         
        if( !target || target == me ) target = offensive_target(me);

        skill = me->query_skill("dugu-jiujian",1);
        tbusy = skill/70 + random(3);
        
        if(userp(me))
                  {
/*        
                if( skill < 220 ) 
                          return notify_fail("你的「独孤九剑」招式不够娴熟，使不出「破气式」。\n");                                   
        
                if( me->query("max_force")<3000 ) 
                                  return notify_fail("你的内力修为不够，无法施用「破气式」。\n");
        
                     if( !me->query("skill_mark/dugu-jiujian"))
              return notify_fail("你还没有领悟到独孤九剑的奥秘，怎么能用呢？\n");

                     if( me->query("family/master_name")!="风清扬")
                 return notify_fail("你不是风清扬的弟子，不能使用「破气式」。\n");

                     if( me->query("betrayer"))
                   return notify_fail("你回想起以前在师门中所曾经受过的好处，再也无法使出独孤九剑来了。\n");
*/
        }    
        
        message_vision(HIY"$N使出独孤九剑「破气式」，静气凝神，仔细观察$n的一举一动，试图找出$n的破绽.\n" NOR, me,target);
        target->kill_ob(me);
        me->add_temp("apply/defense",100);
        me->set_temp("prepare_dugu",5);  
        target->apply_condition("vspo",1);      
                me->start_busy(
                bind((: call_other, __FILE__, "do_prepare", me, target :), me),
                bind((: call_other, __FILE__, "interrupt_prepare" :), me) );

        if( random(me->query("combat_exp") + target->query("combat_exp")/2)> target->query("combat_exp")/2){
        
               if(tbusy > 5){
                   message_vision(HIG"\n$n对于闻名天下的"+HIR"独孤九剑"+HIG"早有耳闻，今见$N猛地使将出来，不由得有些胆战心惊。\n" NOR, me,target);
                   target->start_busy(tbusy);
               }else if( tbusy <=5 && tbusy >3){
                   message_vision(HIG"\n$n慑于$N的"+HIR"独孤九剑"+HIG"其中厉害，立即采取守势，屏息聚神，丝毫不敢怠慢。\n" NOR, me,target);
                   target->start_busy(tbusy);
               }else if( tbusy <=3 && tbusy >1){
                   message_vision(HIG"\n$n情知$N的"+HIR"独孤九剑"+HIG"极难应付，犹豫之间，手上的攻势不由得打了个折扣。\n" NOR, me,target);
                   target->start_busy(tbusy);
               }else {
                   message_vision(HIG"\n$n眼见$N的"+HIR"独孤九剑"+HIG"毫无破绽，随即攻势渐缓，从不同的角度和方位寻求出手的机会。\n" NOR, me,target);
                   target->start_busy(tbusy);
               }
        } else {
                   message_vision(HIC"\n$n虽知此乃旷古绝伦的"+HIR"独孤九剑"+HIC"，但心中豪气顿生，“独孤九剑又能如何，我还能惧了你不成？”\n随即出招更加凌厉威猛，一点都不给$N留喘息的机会。\n" NOR, me,target);
        }

        return 1;
}

int do_fire(object me,object target)
{
        int damage,i;
        object *obs;
    object weapon;
        
    me->clean_up_enemy();
    if( !target || target == me || target->is_corpse()) target = offensive_target(me);  

        damage = me->query_skill("sword")+me->query_skill("dugu-jiujian",1);            
        damage += me->query("force_factor");
        damage += me->query_temp("apply/damage");
        damage += random(damage);
        if(wizardp(me))
        CHANNEL_D->do_channel(this_object(),"sys",sprintf("damage==%d",damage));
        weapon = me->query_temp("weapon");
        
        me->add("force",-1500);
        me->add_temp("apply/defense",-100);
        
        me->delete_temp("prepare_dugu");
        {
                message_vision(HIR"\n惊人的真力，从$N的剑尖爆发出来，直透进$n的要害。\n"NOR,me,target);

        
             if( (damage-target->query_temp("apply/armor_vs_force")) > 0 )
                   {        
            target->add("force",(target->query_temp("apply/armor_vs_force")-damage));
                          //NPC用起来更厉害一些，嘿嘿 add by emote
          if( !userp(me)  )
             target->receive_wound("kee",damage,me);
                    else 
                                target->receive_wound("kee",damage/2,me);
                                COMBAT_D->report_status(me,target,1);                   
                                target->set("force_factor",0);
                                target->set_temp("bepo",1);
                }
                else
                {
                        message_vision(GRN"可是$N还是在最后一刻拼尽全力抵挡住了这一击！\n"NOR);         
                        
                }
        }
        //if(userp(me))
        if( damage > me->query("force") ) 
        {
                          message_vision(RED"\n与此同时，$N手中的"+weapon->query("name")+"，再也无法承受巨大的真力的冲击，竟然被震碎成碎片。\n"NOR,me);
                  weapon->unequip();
              weapon->move(environment(me));
              weapon->set("name", "破碎的" + weapon->query("name"));
              weapon->set("value", 0);
              weapon->set("weapon_prop", 0);
              weapon->set("long", weapon->query("long")+"可是，现在却已经碎成几片，不知道还有什么用处。\n");
              me->reset_action();
          }               //老风的剑可不能掉，否则不大好吧
                
}       

int do_prepare(object me,object target)
{
        int left_busy,ap,dp,lvl;
        
        me->add_temp("prepare_dugu",-1);
        left_busy = me->query_temp("prepare_dugu");

        me->clean_up_enemy();
        if( !target || target == me || target->is_corpse()) target = offensive_target(me);      

        if( left_busy > 3 )
        {
                if(check_user(me,target))
                {
                        message_vision(HIY"$N不断左闪右躲，窥探着$n的要害之处...\n"NOR,me,target);
                        return 1;
                }
                else
                {
                        me->delete("prepare_dugu");
                        me->add_temp("apply/defense",-100);
                        return 0;
                }
                
        }       
        if( left_busy > 2 )
        {
                if(check_user(me,target))
                {
                        message_vision(HIY"$N不经意随手刺出几剑，以试探$n的虚实...\n"NOR,me,target);
                        return 1;
                }
                else
                {
                        me->delete("prepare_dugu");
                        me->add_temp("apply/defense",-100);
                        return 0;
                }

        }       
        if( left_busy > 1 )             
        {
                if(check_user(me,target))
                {
                lvl = me->query_skill("sword");
                ap  = (lvl*lvl)*lvl;//学到头是不到600万power，大概是513万
                if(!userp(me)) //让NPC的成功率再高一些
                        ap += me->query("combat_exp");
                else
                   ap += me->query("combat_exp")/2;
                        dp  = target->query("combat_exp");
                if(target->query_skill("taiji-jian",1)>199)
                        dp = dp*3/2;
                        //对付taiji-jian的时候，自然这个破的概率比较小，嘿嘿
                        if( random(ap+dp)>dp)
                        {
                                message_vision(HIY"$N眼中灵光一闪，找出了$n的要害之处...\n"NOR,me,target);              
                                return 1;
                        }
                        else
                        {
                                message_vision(HIY"$N实在无法发现$n的要害之处，只得收起剑式。\n"NOR,me,target);
                                me->delete("prepare_dugu");
                                me->add_temp("apply/defense",-100);
                                return 0;
                        }
                }
                else
                {
                        me->delete("prepare_dugu");
                        me->add_temp("apply/defense",-100);
                        return 0;
                }
                
        }               
        if( left_busy > 0 )              
        {
                if(check_user(me,target))
                {
                        object weapon;
                        weapon=me->query_temp("weapon");
                        message_vision(HIY"$N忽然长啸一声，手中"+weapon->query("name")+"向$n的要害快捷无伦地直刺而出。\n"NOR,me,target);
                        return 1;
                }
                else
                {
                        me->delete("prepare_dugu");
                        me->add_temp("apply/defense",-100);
                        return 0;
                }

        }               
        do_fire(me,target);
        return 0; 
}       


int interrupt_prepare(object me, object who, string reason)
{
        
        me->add_temp("apply/defense",-100);
        switch(reason) {
        case "halt":
                tell_object(me,"「独孤九剑」一旦施用，就无法停止。\n");
                break;
        case "hit":
                message_vision(HIR "$N一击命中，真气透入$n体内，及时截断了$n的气脉！\n" NOR, who,me);
                tell_object(me,HIR"你只觉得全身真气突然堵塞不前，手中的剑式再也无法连贯地施用下去\n"NOR);
                me->start_busy(2+random(3));
                break;
        }
        return 1;
}

