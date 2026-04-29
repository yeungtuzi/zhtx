// help.c
// Update by Dongsw 2003
// Add help here for view map

#include <ansi.h>
#include "/doc/help.h"
inherit F_CLEAN_UP;
#include "/doc/help_maps.h" // dir to mapfile

string *default_search = DEFAULT_SEARCH_PATHS;

int main(object me, string arg)
{
        int i, t;
        string file, *search, roompath, roomname, map, *filepath;

        if( !arg ) {
                if (file_size(HELP_DIR + "/help/topics") > 0)
                {
                        REPLACE_D->replace_ansi(HELP_DIR + "/help/topics");
                } else
                {
                        write("没能找到帮助主题。\n");
                }
                return 1;
        }

        if(arg == "here")
        {
                roompath = base_name(environment(me));
                roomname = REPLACE_D->ansi_remove(environment(me)->query("short"));
                i = 0;
                t = strsrch(roompath,"/d/xizang/class/");
                me->set("t",t);
                filepath = (t == -1) ? keys(maps) : keys(xizang_maps);
                me->set("filepath",filepath);
                while(i<sizeof(filepath) && (strsrch(roompath,filepath[i])==-1)) i++;
                if (i>=sizeof(filepath))
                {
                        write("您所查阅的地区尚未开放此功能。\n");
                        return 1;
                }
                map = replace_string(read_file("/doc/help/map/" + 
                ((t == -1) ? maps[filepath[i]] : xizang_maps[filepath[i]])),roomname,BLINK+HIW + roomname + NOR);
                me->start_more(map);
                return 1;
        }
        
        // Else, try if a command name is specified.
        seteuid(getuid());
        if( stringp(file = me->find_command(arg)) ) {
                notify_fail("有这个指令存在，但是并没有详细的说明文件。\n");
                return file->help(me);
        }

        // Search the individual search path first.
        if( pointerp(search = me->query("help_search_path")) ) {
                i = sizeof(search);
                while(i--) if( file_size(search[i] + arg)>0 ) {
                        me->start_more( REPLACE_D->ansi_filter(read_file(search[i] + arg)));
                        return 1;
                }
        }

        // Support efun/lfun help with same name as other topics such as
        // ed() and ed command.
        sscanf(arg, "%s()", arg);

        // Finally, search the default search paths.
        if( pointerp(default_search) ) {
                i = sizeof(default_search);
                while(i--) if( file_size(default_search[i] + arg)>0 ) {
                        me->start_more(REPLACE_D->ansi_filter(read_file(default_search[i] + arg) ));
                        return 1;
                }
        }

        return notify_fail("没有针对这项主题的说明文件。\n");
}

int help(object me)
{
        write(@HELP
指令格式：help <主题>              例如：> help cmds
          help <函数名称>()        例如：> help call_out()

这个指令提供你针对某一主题的详细说明文件，若是不指定主题，则提供你有关
主题的文件。
HELP
        );
        return 1;
}



