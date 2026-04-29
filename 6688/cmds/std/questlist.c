// questlist.c
#include <ansi.h>

inherit F_CLEAN_UP;
inherit "/std/char/qlist.c";

int main(object me, string arg)
{
        
        int j;                          
        string str;
        me=this_player();
      	step_phase = read_table("/cmds/std/questlist");
        j=1;
        if (arg=="-i")
        {
       write(sprintf("%-20s %-15s\n","迷题探险","完成情况"));
         do{                                                  
         if( (int)me->query("秘密/"+step_phase[j]["questid"])==1) str="完成";
          else str="未完成";
       write(sprintf("%-20s %-15s\n",step_phase[j]["questid"],str));
          j++;
           }while(step_phase[j]["questid"]!="end");
         

        return 1;
        }
j=1;
if ((int)wizardp(this_player()))
 {write(sprintf("%-20s %-15s %-15s %-20s\n","谜题探险","完成人数","完成第一人","难度"));
       do{ 

 
 write(sprintf( "%-20s %-15d %-15s %-20d\n",step_phase[j]["questid"],step_phase[j]["number"],
			step_phase[j]["first"],step_phase[j]["level"])
                );
                 j++;
        }while (step_phase[j]["questid"]!="end");
       }
else
    {write(sprintf("%-20s %-15s %-20s\n","谜题探险","完成人数","难度"));
       do{ 

 
 write(sprintf( "%-20s %-15d %-20d\n",step_phase[j]["questid"],step_phase[j]["number"],
step_phase[j]["level"])
                );
                 j++;
        }while (step_phase[j]["questid"]!="end");
       }

 return 1;      
 }




int help(object me)
{
  write(@HELP
指令格式 : questlist [-i]
 
这个指令, 如果没有指定参数, 会显示出所有玩家对迷题
的解答情况连线资料. 反之, 则可显示有关自己对迷题的
解答情况.
 

HELP
    );
    return 1;
}
 
