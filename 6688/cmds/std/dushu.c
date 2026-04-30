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
       object ob1,ob2,ob3,ob4;

       max_force = 3 * me->query_skill("force",1) + 5 * ( me->query_skill("force",0) + me->query_skill("force",1) / 2);
       start_force = me->query("max_force") ;
       myexp = me->query("combat_exp");
       myskill = me->query_skill("literate", 1);

       if( start_force < 2500 ) return notify_fail("你的内力太低了，这样读下去还要不要命了？\n");
       if( myskill > 200 ) return notify_fail("你的读书识字已经很高了，再读下去也没有什么结果了。\n");
       if( myexp < 500000 ) return notify_fail("你的战斗经验太少了，还是先去体验一下江湖再来学习课本吧！\n");

       if( !arg ) return notify_fail("请用help dushu来看看怎么用。\n");
       if( me->is_busy() ) return notify_fail("你现在忙着呢，不能研读书籍。\n");
       if( me->is_fighting() ) return notify_fail("战斗中也想研读书籍，你想走火入魔么?\n");

        if (!objectp(ob1 = present("libai shiji",me) ) )
                return notify_fail("你身上没有《李白诗集》，还是找一本来再说！\n");  

        if (!objectp(ob2 = present("dufu shiji",me) ) )
                return notify_fail("你身上没有《杜甫诗集》，还是找一本来再说！\n");  

        if (!objectp(ob3 = present("zhuang zi",me) ) )
                return notify_fail("你身上没有《庄子》，还是找一本来再说！\n");  

        if (!objectp(ob4 = present("lao zi",me) ) )
                return notify_fail("你身上没有《老子》，还是找一本来再说\n");  

       if(sscanf(arg, "with %d", t_hours)==1 )
       { 
             if( me->query_skill("literate", 1) < 150) return notify_fail("你读书识字等级太低，还不能长时间研读书籍。\n");
             if(t_hours <=0) return notify_fail("你至少要花1个小时来研读书籍！\n");

             me->start_busy(3*t_hours);

             me->add("mud_age",t_hours*3600);

             my_age = me->query("mud_age")/86400;
 
             addskill = t_hours*2;

             me->set_skill("literate", myskill + addskill);
 
             if( me->query_skill("literate", 1) > 201) me->set_skill("literate", 201);
             printf(HIM"你找了个没人的地方，开始全神贯注地啃起书本来……\n"NOR);
             printf(HIG"经过%d小时的刻苦学习，你的读书识字提高了%d级！！\n"NOR,t_hours,addskill);
             return 1;
         }            
        return 0;
}
int help(object me)
{
  write(@HELP
转换指令使用方法:

dushu with <小时>  。

HELP
    );
    return 1;
}

