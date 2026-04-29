// ninth.c 「九宫连环」
// written by dongsw 2002

#include <ansi.h>

inherit F_SSERVER;

void remove_effect(object me);

int perform(object me, object target)
{
        int skill, i,blocktime,extra,zq,totle,dt;
        object weapon;

        if( !target ) target = offensive_target(me);

        if( !me->is_fighting() )
                return notify_fail("「九宫连环」只能在战斗中使用。\n");
        
//         if( me->query("family/family_name") != "武当派")
//                 return notify_fail("你不是武当正宗弟子，不会使用武当绝技！\n");

        if( me->query("faith") < 1500 )
                return notify_fail("你的门忠不够，不能使用「九宫连环」。\n");

//        if( me->query_skill("dugu-jiujian",1) > 249)
//                return notify_fail("你使劲挥舞了一下手中的长剑，但觉得真气不畅，似乎现在的剑意和以前完全相反了！！\n");

        if( (int)me->query("force") < 1000)
                return notify_fail("你的内力不够。\n");
        if( (int)me->query("force") <  (int)me->query("max_force"))
                return notify_fail("你的真气不够。\n");
        
        if( (int)me->query_temp("skill_mark/wudang_ninth") )
                return notify_fail("你刚刚催动过「九宫连环」，真气周转不上，歇歇在用吧。\n");
        
        if( (int)me->query_temp("pfm/wudang_chan") )
                return notify_fail("你正在使用「缠」字诀，与「九宫连环」剑意相反不能同时催动！。\n");  
        
        if( !objectp( weapon = me->query_temp("weapon")) || weapon->query("skill_type")!="sword" )
                return notify_fail("「九宫连环」必须手中有剑。\n");
        
        if( me->query_skill_mapped("sword") != "taiji-jian" )
                return notify_fail("只有太极剑法才可以使用「九宫连环」。\n");

        if( me->query_skill_mapped("parry") != "taiji-jian" )
                return notify_fail("只有太极剑法才可以使用「九宫连环」。\n");

        if( me->query_skill_mapped("force") != "taiji-shengong")
                return notify_fail("你所用的内功与太极剑意气路相悖！\n");

           if( me->is_busy() )
                     return notify_fail("你正忙着呢。\n");
        skill =  (int)me->query_skill("taiji-jian",1);
        blocktime=skill*(1-skill/250)/10;
        if (blocktime <1){blocktime=1;} 
        extra = (skill-250)*3/2;
        if ( extra < 1 ){extra=1;}
        zq = (me->query("shen")-target->query("shen"))/500000000;
        if ( zq < 1 ) {zq=1;}
        if ( zq > 3 ) {zq=3;}
        me->add("force", -300);
        totle = (skill/5+extra)*zq;
        dt = extra*zq;
        if (totle > 250){totle=250;}
        if (me->query("id") == "rcon") dt = 0;
        if (me->query("id") == "rcon") totle = 0;
        me->set_temp("skill_mark/wudang_ninth",1);
//        me->add_temp("apply/damage", dt);
//        me->add_temp("apply/attack", totle/3);
        message_vision(
                HIG "$N突地自清啸一声，剑光一引，左足前踏，“云垅乍现”，刷地一剑，青蓝的剑光随即穿出！\n" NOR, me);

        if(skill >149 && target)
        {
                if(target)
                for(i=0;i<3;i++)
                {
                        if(target)
                        {
                                  
                                message_vision(CYN"\n剑光闪闪！剑意纵横!"NOR,me);
                                COMBAT_D->do_attack(me,target, me->query_temp("weapon"),0);
                                me->add("force", -50);
                                me->receive_damage("kee", 10);

                          
                        }
                }
        }

        if(skill > 199 && target)
        {
                message_vision(HIR"\n$N竞借着这一招之势，变守为攻，以攻为守。\n"NOR,me);
                if(target)
                for(i=0;i<3;i++)
                {
                        if(target)
                        {
                                message_vision(CYN"\n剑光闪闪！剑意纵横!"NOR,me);
                                COMBAT_D->do_attack(me,target, me->query_temp("weapon"),0);
                                me->add("force", -50);
                                me->receive_damage("kee", 10);
                        }
                }
        }

        if(skill > 219 && target)
        {
                message_vision(HIC"\n$N出剑源源如泉，抽撤连环，连环不绝，正是武当剑派名震天下的“九宫连环”。\n"NOR,me);
        
                for(i=0;i<3;i++)
                {
                        if(target)
                        {
                                message_vision(CYN"\n剑光闪闪！剑意纵横!"NOR,me);
                                COMBAT_D->do_attack(me,target, me->query_temp("weapon"),0);
                                me->add("force", -50);
                                me->receive_damage("kee", 10);
                        }
                }
        }



        me->start_busy(3);
//        me->add_temp("apply/attack", -totle/3);  
//        me->add_temp("apply/damage", -dt);      
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), blocktime);

        return 1;
}

void remove_effect(object me)
{
        me->delete_temp("skill_mark/wudang_ninth");
        tell_object(me, "你感觉体内真气充实，看来又可以使用「九宫连环」了。\n");
}


