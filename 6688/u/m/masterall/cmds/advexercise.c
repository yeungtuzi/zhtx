// exercise.c

#include <ansi.h>
#include <skill.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        int kee_cost, force_gain;

        seteuid(getuid());
        
        if( me->is_fighting() )
                return notify_fail("战斗中不能练先天真气，会走火入魔。\n");

        if( me->is_busy() )
                return notify_fail("你正忙著做其他事！\n");

        if( me->query("max_realforce")>300 && (me->query("realforce")>me->query("max_realforce")*2) )
        {
                me->set("realforce",me->query("max_realforce")*2);
                return notify_fail("你感觉此刻体内真气充盈欲溢，再练下去只怕要走火入魔。\n");
        }

        if( me->query_skill("force", 1) < 350 )
                return notify_fail("你的内功修为太低了, 还无法自行修炼先天真气.\n");

        if( !arg
        ||      !sscanf(arg, "%d", kee_cost) )
                return notify_fail("你要花多少真气修炼\？\n");

        if( kee_cost < 10 ) 
                return notify_fail("你最少要花 10 点「真气」才能修炼\。\n");

        if( (int)me->query("force") -  (int)me->query("max_force") * 2 < kee_cost )
                return notify_fail("你现在的真气太少了，无法产生内息运行全身经脉。\n");

        if( (int)me->query("sen") * 100 / (int)me->query("max_sen") < 90 )
                return notify_fail("你现在精神状况太差了，无法凝神专一！\n");

        if( (int)me->query("gin") * 100 / (int)me->query("max_gin") < 90 )
                return notify_fail("你现在精力不够，无法控制内息的流动！\n");

        message_vision(HIW"$N盘膝坐了下来，开始运气修炼先天真气\。\n$N感觉一股暖热的气流从丹田升起，直人周身各大要穴。\n", me);
        me->start_busy(
                bind((: call_other, __FILE__, "do_exercise", me, me->query("kee") - kee_cost :), me),
                bind((: call_other, __FILE__, "interrupt_exercise" :), me) );
        me->add_temp("apply/short", ({ me->name() + "正盘膝坐在地下修炼先天真气 ...." }) );
        return 1;
}

int do_exercise(object me, int low_kee)
{
        int cycle;
        int max_realforce,coeff,speed_coeff;
        string *short;  
        string force_skill;     
        
        max_realforce = (int)me->query_skill("force", 1)*5 + me->query("max_force")/5; //先天真气的瓶颈和内功等级和最大内力挂钩

        if( (int)me->query("kee") < low_kee ) {

                if( (int)me->query("realforce") > (int)me->query("max_realforce") * 2) {
                        if( (int)me->query("max_realforce") >= max_realforce ) {
                                tell_object(me, HIR"当你的真气遍布全身经脉时却没有功力提升的迹象，似乎先天真气修为已经遇到了瓶颈。\n"NOR);
                        } else {
                                tell_object(me, HIC"你的先天真气增强了！\n"NOR);
                                if( me->query("max_realforce") < 4000)
                                        me->add("max_realforce", 1);
                        }
                        me->set("realforce", me->query("max_realforce"));
                }       
                message_vision("$N行功完毕，深深地吸了口气，站了起来。\n", me);
                short = me->query_temp("apply/short");
                short -= ({ me->name() + "正盘膝坐在地下修炼先天真气 ...." });
                me->set_temp("apply/short", short);
                return 0;
        }
        
        //练到上限*2自动停止。 yeung
        if( (int)me->query("realforce") > (int)me->query("max_realforce") * 2 + 100)
        {
                me->set("realforce", me->query("max_realforce") * 2 );
                message_vision("$N将周身运行的真气收回丹田，站了起来。\n", me);
                short = me->query_temp("apply/short");
                short -= ({ me->name() + "正盘膝坐在地下修炼先天真气 ...." });
                me->set_temp("apply/short", short);             
                return 0;
        }


        cycle = (int)me->query("max_force") / 800 + 1;

        if ( me->query("max_realforce") < 100 ) speed_coeff = 10;
        if ( me->query("max_realforce") < 300 && me->query("max_realforce") > 99 ) speed_coeff = 9;
        if ( me->query("max_realforce") < 500 && me->query("max_realforce") > 299) speed_coeff = 8;
        if ( me->query("max_realforce") < 800 && me->query("max_realforce") > 499) speed_coeff = 7;
        if ( me->query("max_realforce") < 1500 && me->query("max_realforce") > 799) speed_coeff = 6;
        if ( me->query("max_realforce") < 2400 && me->query("max_realforce") > 1499) speed_coeff = 5;
        if ( me->query("max_realforce") > 2399 ) speed_coeff = 2;
        //修炼的先天真气越高，速度就越慢。

        if( speed_coeff > 0 )
                cycle = (cycle*speed_coeff)/10;
                
        if(me->query("force") < cycle) 
                cycle = me->query("force");

        me->add("force", -cycle);
        me->add("realforce", cycle/2);
        return 1;
}

int interrupt_exercise(object me, object who, string reason)
{
        string *short;

        switch(reason) {
        case "halt":
                if( (int)me->query("realforce") > (int)me->query("max_realforce") * 2 )
                        me->set("realforce", me->query("max_realforce") * 2 );
                message_vision("$N将周身运行的真气收回丹田，站了起来。\n", me);
                break;
        case "hit":
                tell_object(me, HIR "\n你觉得小腹一阵绞痛，有如千百只蚂蚁在乱钻乱咬！\n\n" NOR);
                message_vision(HIR "$N「哇」地一声喷出一大口鲜血，摇摇晃晃地站了起来。\n" NOR, me);
                me->set("max_realforce", (int)me->query("max_realforce") * 9 / 10 );
                me->set("realforce",0);
                break;
        }
        short = me->query_temp("apply/short");
        short -= ({ me->name() + "正盘膝坐在地下修炼先天真气\ ...." });
        me->set_temp("apply/short", short);
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : exercise [<耗费「气」的量>]

运真气练功，控制体内的真气在各经脉间流动，藉以训练人体肌肉骨骼
的耐力、爆发力，并且用内力的形式将能量储备下来。
当一位武者运气遍布全身经络时, 也是这位武者防御最弱的时候, 如果
此时受到攻击受伤, 则会造成走火入魔。

请参考 help stats
HELP
        );
        return 1;
}

