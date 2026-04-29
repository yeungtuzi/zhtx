/*************************************************************************/
//    This is for for quick exercise, change age to maxforce             */
//    the unit is hour                    //lazypig                      */
/*************************************************************************/

#include <ansi.h>

int main(object me, string arg)
{
       int t_hours;
       int my_age, eff_recover;
       int start_mana, add_mana, max_mana, final_mana;

       max_mana = ( (int)me->query_skill("spells", 1) + me->query_skill("spells")/5 ) * 10;
       start_mana = me->query("max_mana") ;

       if( start_mana < 150 ) return notify_fail("你的法力太低了，自行修炼对你没有任何帮助,还是扎扎实实从头来吧！\n");
       if( start_mana >= max_mana ) return notify_fail("你已经到法力瓶颈了，修炼对你没有任何帮助！\n");

       if( !arg ) return notify_fail("请用help age2mana来看看怎么用。\n");
       if( me->is_busy() ) return notify_fail("你现在忙着呢，不能修炼。\n");
       if( me->is_fighting() ) return notify_fail("战斗中也想修炼，你想走火入魔么?\n");

       if(sscanf(arg, "with %d", t_hours)==1 )
       { 
             if( me->query_skill("spells",1) < 40) return notify_fail("你咒术修为太低，还不能长时间修炼。\n");
             if(t_hours <=0) return notify_fail("你至少要花1个小时来修练法力！\n");

             me->start_busy(3*t_hours);

             me->add("mud_age",t_hours*3600);

             my_age = me->query("mud_age")/86400;

             add_mana = ( random(me->query_msc() + me->query_spi())/4 + 8 )* t_hours;
            

             final_mana = start_mana   + add_mana ; 
  
             if ( final_mana > max_mana ) final_mana = max_mana;    // it shouldn't be more than bottle net
            
             me->set("max_mana",final_mana);  
             if (me->query("max_mana")> 4000){ me->set("max_mana",4000);}

             printf(HIC"你五行向天，静心凝神，采天地之灵气，聚日月之精华……\n"NOR);
             printf(HIM"经过%d小时的修炼，你的法力提升了%d点！！\n"NOR,t_hours,final_mana-start_mana);
             return 1;
         }            
        return 0;
}
int help(object me)
{
  write(@HELP
转换指令使用方法:

age2mana with <小时>  。

HELP
    );
    return 1;
}

