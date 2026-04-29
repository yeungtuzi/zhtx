/*************************************************************************/
//    This is for for quick exercise, change age to maxforce             */
//    the unit is hour                    //lazypig                      */
/*************************************************************************/

#include <ansi.h>

int main(object me, string arg)
{
       int t_hours;
       int my_age, eff_recover;
       int eff_kee_2_force, eff_force_2_kee, ex_time, auto_recover, recover_time;
       int auto_ex_time, loop_ex_time,heart_point1,heart_point2;
       int start_force, final_force, total_point, max_force;

       max_force = 3 * me->query_skill("force",1) + 5 * ( me->query_skill("force",0) + me->query_skill("force",1) / 2);
       start_force = me->query("max_force") ;

       if( start_force >= max_force ) return notify_fail("你已经到内力瓶颈了，修炼对你没有任何帮助！\n");

       if( !arg ) return notify_fail("请用help age2force来看看怎么用。\n");
       if( me->is_busy() ) return notify_fail("你现在忙着呢，不能修炼。\n");
       if( me->is_fighting() ) return notify_fail("战斗中也想修炼，你想走火入魔么?\n");

       if(sscanf(arg, "with %d", t_hours)==1 )
       { 
             if( me->query_skill("force") < 1) return notify_fail("你内功心法等级太低，还不能长时间修炼。\n");
             if(t_hours <=0) return notify_fail("你至少要花1个小时来修练内力！\n");

             me->start_busy(3*t_hours);

             me->add("mud_age",t_hours*3600);

             my_age = me->query("mud_age")/86400;

             
//     normal auto recover: 10 sec 1 food.
//     14 year old has the highest recover efficiency,heart beat is 4 times, 15-23 is 2 times, > 23 is 1 

             eff_recover = 1;
             if ( my_age <= 1 ) eff_recover = 4;
             if ( my_age <= 7 && my_age > 1 ) eff_recover = 2;

             eff_kee_2_force  = 10 * (me->query("max_kee")/25 + 1) ;   // 1 food = 10 heart beat
             eff_force_2_kee  = me->query_skill("force")*eff_kee_2_force/100;

//    force -> kee is :      recovered_kee = 100 / query_skill("force") * used_force
//    1 heart-beat can transfer x kee to force: x = query("max_kee")/25 + 1                    
 
             ex_time      = (int) me->query("max_kee") / eff_kee_2_force  ;
             auto_recover = 10 * ( start_force/10 + 2 * me->query("con") ) * eff_recover ;   // here, should be me->query("force") + 2*con) * eff_recover, 
                                                                                  // but here we just use the average force. lazypig 

//                    ex time + recover time + recover kee to force time

             auto_ex_time =  1  +  10 + (int) (auto_recover / eff_kee_2_force) + 1 ;

//                    ex time + loop force to kee then to force's time

             loop_ex_time = 1 + (int) (eff_force_2_kee / eff_kee_2_force) + 1 ;

             heart_point1 = ( auto_recover - eff_kee_2_force ) / auto_ex_time  ;         
             heart_point2 = ( eff_force_2_kee - eff_kee_2_force ) / loop_ex_time ;  

//    check if one can exercise with looping.

             if ( heart_point1 < heart_point2 ) heart_point1 = heart_point2;

             total_point = (int) heart_point1 * t_hours * 3600 / 10 ;   // how much total force points one can get in 1 hours
            
/*    calculate the max_force point one can get
         start max_force is N, final max_force is M, then total_point = ( M - N + 1 ) * ( M + N ) / 2
         -------------------------------> M = (int) (sqrt( 1 + 4 * ( 2 * total_point + N * N - N) ) - 1) /2  ~ sqrt( 2* total_point + N * N - N)

   But it seams there is no sqrt in LPC ?  so use a approx value for M ~ N + total_point / N - total_point / N / 6             */

//             final_force = (int) (sqrt ( 1 + 4 * ( 2 * total_point + start_force * start_force - start_force ) ) - 1) / 2 ;

             final_force = start_force + 5 * total_point / start_force / 6 ; 
    
             if ( start_force < 1000 ) final_force = start_force + 4*total_point / start_force / 5 ;
                         
             if ( final_force > max_force ) final_force = max_force ;    // it shouldn't be more than bottle net
            
             me->set("max_force",final_force);  

             printf(HIC"经过%d小时的修炼，你的内力提升了%d点\n"NOR,t_hours,final_force-start_force);
             return 1;
         }            
        return 0;
}
int help(object me)
{
  write(@HELP
转换指令使用方法:

age2force with <小时>  。

HELP
    );
    return 1;
}


