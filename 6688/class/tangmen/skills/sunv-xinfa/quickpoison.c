// unpoison.c
// written by tang
// 1998.4.30
// update by dongsw

#include <ansi.h>

//inherit F_CONDITION;

int exert(object me, object target)
{
        // 2026-04-30: unused variable commented out
        // string *conditions=({}),*list,arg;
        object *enemy;
        int i,mark,lev,jk;
        
        seteuid(getuid());
        lev = (int)me->query_skill("sunv-xinfa", 1);
        
        if( !(me->is_fighting()) )
                return notify_fail("要在战斗中才行。\n");

        if ( lev < 120)
                return notify_fail("你的素女心法修为还不够。\n");

        if( (int)me->query("force") < 300 ) 
                return notify_fail("你的真气不够。\n");

        if( (int)me->query("eff_kee") < (int)me->query("max_kee") / 2 )
                return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");

        if( objectp( me->query_temp("weapon")))
                return notify_fail("你只能空手催毒。\n");

        if( target == me )
                return notify_fail("你要对什么人催毒？\n");
        else
        {
                enemy = me->query_enemy();
                i = sizeof(enemy);
                while( i-- )
                        if( target == enemy[i] )        mark = 1;
                        
                if( !mark )
                        return notify_fail("对方不是你的对手。\n");

                message_vision( HIY "$N绕到$n的背后，伸出手掌按在他的背上，
运内力激发他体内的毒素...\n"NOR,me,target);
        }

        me->start_busy(random(3));

        me->add("force",-250);

        if( random(me->query("force")) < random(target->query("force"))/2 )
        return 1;
/*
        list = get_dir("/daemon/condition/");
        
        i = sizeof(list);
        while( i-- )
        {
                arg = list[i];
                if( arg[strlen(arg)-8..strlen(arg)-3] == "poison" )
                        conditions += ({arg[0..strlen(arg)-3]});
        }
        
        i = sizeof(conditions);
        while(i--) 
        {
                if( target->query_condition(conditions[i]) > 0 )
                        for(jk=20;jk<lev;jk=2)
                        {
                                target->update_condition(conditions[i],1);
                        }
        }
*/
                //if( call_other(target,"update_condition","tm_poison",2) != 1 )
                //      return notify_fail("update condition error\n");

        if( target->query_condition("tm_poison") > 0 )
        {
                target->update_condition("tm_poison");
                if(lev>160)
                {
                        message_vision( HIY"\n然后$N把双掌化爪插入$n体内加速毒素的发作！\n"NOR,me,target);
                        target->update_condition("tm_poison");
                }
                if(lev>200)
                {
                        message_vision( HIY"\n接着$N加强力激发$n体内毒素，$n身体冒出浓浓的黑烟！\n"NOR,me,target);
                        target->update_condition("tm_poison");
                }               
                if(lev>249)
                {
                        message_vision( HIY"\n$N行功完毕，跳了出去，$n眼看就快不行了！\n"NOR,me,target);
                        target->update_condition("tm_poison");
                }               
        }

        return 1;
}

 
