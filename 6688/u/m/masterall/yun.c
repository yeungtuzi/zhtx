//yun.c 太极云手
#include <ansi.h>
#include <combat.h>
//by masterall


inherit F_DBASE;
inherit F_SSERVER;
int judge(object me,object victim)
{
            int level,mp,dp;
        level = me->query_skill("taiji-quan",1); //200max
        mp = level*level/2*level; //400万
        dp = victim->query("combat_exp");//368万max
        if( random(mp+dp)>dp )
                        return 1;
                else return 0;
}

int perform(object me, object target)
{
        int i,level,xieqi;

        if( !target ) target = offensive_target(me);

         if( !target
         ||      !target->is_character()
         ||      !me->is_fighting(target) )
                return notify_fail("「太极云手」只能在战斗中使用。\n");

        if( me->query_skill_mapped("force") != "taiji-shengong")
                return notify_fail("你所用的内功使不出「太极云手」！\n");


        if( xieqi > -10000 )
                return notify_fail("对方又不是什么阴狠的角色，犯不上使用「太极云手」！\n");

        if( (int)me->query("force") < 1000 ) return notify_fail("你的内力不够！\n");

        
        if( level < 200 )                              
                return notify_fail("你的「太极拳」等级太低！\n");
        
message_vision(HIY"$N横眉立目，正色道，“尔等平时作恶多端，今日我便要为武林除害，费掉你这个贼子！”\n话毕，施展「太极拳」中的“圆转不断”的精义，一式「太极云手」，随即左圈右圈，\n一个圆圈跟着一个圆圈，大圈、小圈、平圈、立圈、正圈、斜圈，一个个太极圆圈向$n发出！！\n\n" NOR, me, target);
            if(judge(me,target))
 {
                if(level>=200 )
                {
message_vision(HIG"\n$N左手高，右手低，一个圆圈已将$n手臂套住，太极神功的内劲使出，“喀喇”一声，\n$n的右臂上下臂骨齐断！\n" NOR, me, target);
                target->set_temp("last_damage_from",me);
                target->receive_damage("kee",me->query("force_factor")*2);
                target->receive_wound("kee",me->query("force_factor")*2);
                COMBAT_D->report_status(me,target,1);   
                }
                if(level>250 )
                {
message_vision(HIY"\n$N恨$n歹毒，“云手”使出时连绵不断，有如白云行空，一个圆圈未完，\n第二个圆圈已生，又是“喀喇”一声，$n的左臂亦断！\n"NOR, me, target);
                target->set_temp("last_damage_from",me);
                target->receive_damage("kee",me->query("force_factor")*3);
                target->receive_wound("kee",me->query("force_factor")*3);
                COMBAT_D->report_status(me,target,1);   
                }
                if(level>300 )
                {
message_vision(HIR"\n$N一想到$n的阴戾狠毒，“云手”并未停歇，三个圆圈继续划出，\n跟着“喀喀喀”几声，$n的左腿右腿也被一一绞断！\n" NOR, me, target);
                target->set_temp("last_damage_from",me);
                target->receive_damage("kee",me->query("force_factor")*4);
                target->receive_wound("kee",me->query("force_factor")*4);
                COMBAT_D->report_status(me,target,1);   
                } 
                if(level>350 )
                {
 message_vision(HIW"\n$N生平和人动手，从未下过如此辣手，但$n乃武林大害，不除之将会导致江湖中更多的\n血光之灾，一想到此处，$N的圆圈又划了出去，只听得一阵阵的骨头碎裂的声音，\n$n的双臂臂骨、胸前肋骨、肩头锁骨已尽数被$N的“云手”绞断，\n$n闷哼一声，软趴趴的摔倒，竟连呼嚎的劲气都没有了！！\n" NOR, me, target);
                target->set_temp("last_damage_from",me);
                target->receive_damage("kee",me->query("force_factor")*5);
                target->receive_wound("kee",me->query("force_factor")*5);
                COMBAT_D->report_status(me,target,1);   
                }     
                me->start_busy(1);
        } else {
message_vision(HIG"只见$n左躲右闪，间不容发的避开了$N划出的圆圈，但却已累得通身是汗，一时间手忙脚乱！\n" NOR, me, target);
                me->start_busy(random(3));
                target->add("force",-500);
        }
        me->add("force",-500);
        return 1;
}

