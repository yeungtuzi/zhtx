/*************************************************************************/
//    This is for for quick exercise, change age to maxforce             */
//    the unit is hour                    //lazypig                      */
/*************************************************************************/

#include <ansi.h>

int main(object me, string arg)
{
       int t_hours;
       int my_age, eff_recover, myskill, myexp, addskill;
       // 2026-04-30: unused variable commented out
       // int eff_kee_2_force, eff_force_2_kee, ex_time, auto_recover, recover_time;
       // 2026-04-30: unused variable commented out
       // int auto_ex_time, loop_ex_time,heart_point1,heart_point2;
       int start_force, final_force, total_point, max_force;

       max_force = 3 * me->query_skill("force",1) + 5 * ( me->query_skill("force",0) + me->query_skill("force",1) / 2);
       start_force = me->query("max_force") ;
       myexp = me->query("combat_exp");
       myskill = me->query_skill("force", 1);

       if( start_force < 1300 ) return notify_fail("你的内力太低了，这样修炼无法提升你的内功造诣！\n");
       if( myskill > 200 ) return notify_fail("你的内功造诣已经不低了，再修炼下去将是非常艰难的，还是通过其他的方式成长吧！\n");
       if( myexp < 500000 ) return notify_fail("你的战斗经验太少了，还是先去体验一下江湖再来修炼吧！\n");

       if( !arg ) return notify_fail("请用help xiulian来看看怎么用。\n");
       if( me->is_busy() ) return notify_fail("你现在忙着呢，不能修炼。\n");
       if( me->is_fighting() ) return notify_fail("战斗中也想修炼，你想走火入魔么?\n");

       if(sscanf(arg, "with %d", t_hours)==1 )
       { 
             if( me->query_skill("force") < 100) return notify_fail("你内功心法等级太低，还不能长时间修炼。\n");
             if(t_hours <=0) return notify_fail("你至少要花1个小时来修练内功！\n");

             me->start_busy(3*t_hours);

             me->add("mud_age",t_hours*3600);

             my_age = me->query("mud_age")/86400;
 
             addskill = t_hours*3;

             me->set_skill("force", myskill + addskill);
 
             if( me->query_skill("force", 1) > 201) me->set_skill("force", 201);

             printf(HIW"经过%d小时的修炼，你的内功心法提升了%d级！！\n"NOR,t_hours,addskill);
             return 1;
         }            
        return 0;
}
int help(object me)
{
  write(@HELP
转换指令使用方法:

xiulian with <小时>  。

HELP
    );
    return 1;
}

