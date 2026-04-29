// alias.c
#include <ansi.h>

#define MAX_REPEAT 30
#define MAX_ALIASES 40
#define HISTORY_BUFFER_SIZE 10
#define CMDS_PER_TICK 20        

mapping alias;

nosave string *history, last_input;
nosave int last_cmd, repeat_cnt = 0;
nosave int cnt = 0;

string process_input(string str)
{
        string *args, cmd, argstr,*cmds;
        int i, j,cs,ci;
        string cmdline;
        object me = this_object();

        // copy from xkx by dongsw
        if (str == "")
                 return "";

        if (userp(this_object()) 
         && (this_object()->query_temp("quit/forced") || 
             !living(this_object())) )
                return "";

        /*if ( userp(this_object()) || this_object()->query_temp("offline") )
        {
                cnt++;
                me = this_object();
                if ( cnt >  3*CMDS_PER_TICK && this_object()->query_temp("offline")) 
                {
                        tell_object( this_object(),
                                "\n\n侮天鬼王突然在一阵烟雾中出现。\n\n"
                                "\n\n侮天鬼王喝道：你是机器人!!! 连我也看不惯了，滚吧!!!\n\n");
                        log_file("FLOODER", sprintf("%s(%s) was caught flooding on %s.\n",
                                 me->query("name"), geteuid(me), ctime(time())));

                        me->set_temp("quit/forced", 1);
                        if (me->query_temp("offline")) me->delete_temp("offline");
                        if ( !command("quit") ) me->delete_temp("quit");
                        me->force_me("quit");
                        return "";
                } else if (cnt > 2 * CMDS_PER_TICK) 
                {
                        tell_object(this_object(),"\n你的指令输入的太快了，还是歇歇手吧！\n");
                        return("");
                }

        }*/
                         
        if( str==last_input ) {
                repeat_cnt++;
                if( repeat_cnt > MAX_REPEAT ) {
                        tell_object( this_object(),
                                "\n\n侮天鬼王突然在一阵烟雾中出现。\n\n"
                                "\n\n侮天鬼王喝道：你是机器人!!! 连我也看不惯了，滚吧!!!\n\n");
                        command("quit");
                }
        } else {
                repeat_cnt = 0;
                last_input = str;
        }

        if( str[0]=='!' ) {
                if( pointerp(history) && sizeof(history) ) {
                        if( sscanf(str, "!%d", i) )
                                str = (string)history[(HISTORY_BUFFER_SIZE + last_cmd - i) % HISTORY_BUFFER_SIZE];
                        else
                                str = history[last_cmd];
                } else
                        return "";
        } else {
                if( !pointerp(history) ) history = allocate(HISTORY_BUFFER_SIZE);
                last_cmd = (last_cmd + 1) % HISTORY_BUFFER_SIZE;
                history[last_cmd] = str;
        }

        if( mapp(alias) ) {
                if( !undefinedp(alias[str]) )
//                      return replace_string( alias[str], "$*", "" );
                        cmdline = replace_string( alias[str], "$*", "" );
                else 
                  if( sscanf(str, "%s %s", cmd, argstr)==2 && !undefinedp(alias[cmd]) ) {
                        cmd = replace_string( alias[cmd], "$*", argstr );
                        args = explode(argstr, " ");
                        if( (j = sizeof(args)) ) {
                                for(i=0; i<j; i++)
                                        cmd = replace_string( cmd, "$" + (i+1), args[i] );
                        }
                        cmdline = cmd;
//                      return cmd;
                  }
        }
         
        if(!stringp(cmdline)) cmdline = (string)ALIAS_D->process_global_alias(str);
//      return (string)ALIAS_D->process_global_alias(str);
        if( (raw_wiz_level(this_object())||wiz_level(this_object())) &&  stringp(cmdline) && cmdline != "") {
                string *argline;
                argline = explode(cmdline," ");
                if( sizeof(argline)>0  && (((int)GLOBAL_D->is_nolog_cmd(argline[0])) || this_object()->query("supervision")) ) 
                {
                        //object me = this_object();
                        log_file("wizlog/WIZLOG_"+geteuid(me),
                        sprintf("%s: %s(%s)  %s \n",
                                ctime(time()),
                                me->name(1),
                                geteuid(me),
                                cmdline ));
                }
        }
        //加入server-side multi-command-alias的支持.
        //不喜欢的人可以不用.
        //包含$p-指示的命令不解析.
        if( cmdline=="" || cmdline[0..4] == "alias" || (string)this_object()->query("env/parse_cmd") == "off" || strsrch(cmdline,"$p-") != -1 )
        {
                cmdline = replace_string(cmdline,"$p-","");
                return cmdline;
        }
                        
        if (cmdline != ";"){
        cmds = explode(cmdline,";");
        cs = sizeof(cmds);
        for( ci=0;ci<cs-1;ci++ )
        {
//              tell_object(this_object(),"\nparseing command");
                this_object()->fcommand((string)ALIAS_D->process_global_alias(cmds[ci]));
        }
        return (string)ALIAS_D->process_global_alias(cmds[cs-1]);
        }
        else return (string)ALIAS_D->process_global_alias(cmdline);

}

void clear_cmd_count()
{
        cnt -= 2*CMDS_PER_TICK;
        if (cnt < 0) cnt = 0;
}

int query_cmd_count() { return cnt; }

int set_alias(string verb, string replace)
{
        if( !replace ) {
                if( mapp(alias) ) map_delete(alias, verb);
                return 1;
        } else {
                if( !mapp(alias) ) alias = ([ verb:replace ]);
                else if( sizeof(alias) > MAX_ALIASES )
                        return notify_fail("您设定的 alias 太多了，请先删掉一些不常用的。\n");
                else alias[verb] = replace;
                return 1;
        }
}

mapping query_all_alias()
{
        return alias;
}


