/*
 * add offline system and update trigger system
 *                              by dongsw@zhtx2
 */

#include <ansi.h>

#define MAX_TRIGGERS 10
#define MAX_WAIT_TIME 99

mapping trigger;
mapping offline;

nosave int      allow_trigger;
void slow_cmds(object me, string cmd);

int set_trigger(string verb, string replace, int time)
{

        if( !replace ) {
                if ( time )
                {
                        tell_object(this_object(),"触发器用法不对，正确用法为：\n\n"
                        HIY"trigger [触发语句] [延迟时间] [执行命令]\n"NOR);
                        return 1;
                }
                tell_object(this_object(),"此语句触发已被删除。\n");
                if( mapp(offline) ) map_delete(offline, verb);
                if( mapp(trigger) ) map_delete(trigger, verb);
                return 1;
        } else {
                if( time > MAX_WAIT_TIME )
                return notify_fail("您的等待时间过长，请缩短到"
                                   +chinese_number(MAX_WAIT_TIME+1)+"秒以内。\n");
                
                if(!mapp(offline))
                {
                        offline = ([ verb:time]);
                }
                if( !mapp(trigger) ) 
                {
                        trigger = ([ verb:replace ]);
                }
                
                else if( sizeof(trigger) > MAX_TRIGGERS )
                        return notify_fail("您设定的触发太多了，请先删掉一些不常用的。\n");
                else
                {
                        trigger[verb] = replace;
                        offline += ([ verb:time ]);
                        tell_object(this_object(),"新的触发设定成功，请用trigger来查看以设定的触发菜单。\n");
                }
        
                return 1;
        }
}

mixed query_trigger(string verb)
{
        if( mapp(trigger) && stringp(trigger[verb]) )
                return trigger[verb];
        return 0;
}

void delete_all_trigger()
{
        trigger = ([]);
        offline = ([]);
        return;
}

mapping query_all_trigger()
{
        return trigger;
}

mapping query_all_offline()
{
        return offline;
}

void disable_trigger()
{
        allow_trigger = 0;
}

void enable_trigger()
{
        allow_trigger = 1;
}

int query_trigger_enabled()
{
        return allow_trigger;
}

int fire_trigger(string pattern)
{
        string cmd,*patterns;
        int i,s,time;
        object me;
        if( !allow_trigger ) return 0;
        me = this_object();
        if( me->query_temp("parseing") && !me->query_temp("offline")) return 0;
        if( !mapp(trigger) ) return 0;
        pattern = replace_string(pattern,"> ","");

        patterns = keys(trigger);
        s = sizeof(patterns);
        for(i=0;i<s;i++)
        {
                if( !this_object() || !mapp(trigger) || !patterns[i] ) return 0;
                if( strsrch(pattern,patterns[i]) != -1 )
                //if( strsrch(pattern,patterns[i]) != -1 || regexp(pattern,patterns[i]) )
                {
                        cmd = trigger[patterns[i]];
                        time = offline[patterns[i]];
                        if (!time) time = 0;
                        //write(chinese_number(time)+"\n");
                        if( stringp(cmd) )
                        {
                                if( cmd == "$gag" ) return -999;
                                //防止有人用quit来避免死亡
                                if( cmd == "quit" )
                                {
                                        me->check_status();
                                        command("quit");
                                        return -999;
                                }
/*                              if ( environment(me)->query("no_fight"))
                                {*/
                                        if ( time != 0)
                                        {
                                                call_out("slow_cmds",time,me,cmd);
                                                return 1;
                                        }
/*                              }
                                else
                                {
                                        me->delete_temp("offline");
                                        me->fcommand( me->process_input("quit") );
                                        return 1;
                                }*/
                                me->set_temp("parseing",1);             
                                tell_object(me,WHT"触发指令："+cmd+"\n"NOR);                    
                                me->fcommand( me->process_input(cmd) );
                                me->delete_temp("parseing");
                                return 1;
                        }       
                }
        }
        return 0;

}

void slow_cmds(object me, string cmd)
{
        me->set_temp("parseing",1);             
        tell_object(me,WHT"触发指令："+cmd+"\n"NOR);
        me->fcommand( me->process_input(cmd) );
        me->delete_temp("parseing");
}

