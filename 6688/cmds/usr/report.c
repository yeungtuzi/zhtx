#include <ansi.h>

inherit F_CLEAN_UP;
int time_period(int timep, object me);
int main(object me, string arg)
{
 int nowtime = time();
 int overtime,tasktime;
 mapping quest;
 string mastername;
 object master;

 if(!arg) return notify_fail("你想向谁报告什么？\n");
 sscanf(arg,"%s",mastername) ; 
 if((!master = present(mastername, environment(me))) || !living(master))  {
        return notify_fail("你想向谁报告？\n");
 }
 if(!(quest =  me->query("quest")))
        return notify_fail("你想报告什么！\n");
 if( master->query("family/family_name") != me->query("family/family_name")) {
                return notify_fail(master->name()+"不会对此感兴趣的！\n");
        }
 tasktime = (int)  me->query("task_time");
 overtime = (int)  me->query("over_time");
 if(overtime && (overtime-tasktime) <= 0) 
        {
                tell_object(me,CYN + master->name()+"说道：你做的不错，下去休息吧！\n" NOR);

                master->give_bonus(me,quest);    
                me->set("quest",0);
        }    
 else if( (tasktime -  nowtime) < 0) {
        me->set("quest_ok",0);
        master->quest_punish(me);
 }
 else return notify_fail("你的任务还没完成，还不快去！\n" NOR);
 return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : report master_name

这个指令让你向师父报告任务的执行情况。

HELP
);
return 1;
}

