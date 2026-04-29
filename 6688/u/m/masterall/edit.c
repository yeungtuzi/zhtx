// edit.c
// 支持非更新巫师在自身巫师目录中在线 edit

#include "/doc/help.h"

inherit F_CLEAN_UP;

int main(object me, string file)
{
        string arg;
        int len;
        
        arg = me->query("cwd") + file;
        len = sizeof(arg);
        
        if(geteuid(me) != "mudadm" && geteuid(me) != "masterall") 
        {
                if( !file ) return notify_fail("指令格式：edit <档名>\n");
                
                if(strsrch(file, "/") != -1)
                        return notify_fail("请不要在被编辑文件中加“/”符号，请先进入要编辑的目录在 edit。\n");

                if(len < 3) return notify_fail("目前只支持在巫师自用目录(/u/)在线编辑！\n");
                
                if(strsrch(arg[0..2], "/u/") == -1)
                        return notify_fail("目前只支持在巫师自用目录(/u/)在线编辑！\n");
        }

        if( !file ) return notify_fail("指令格式：edit <档名>\n");

        if( in_edit(me) ) return notify_fail("你已经在使用编辑器了。\n");

        seteuid(geteuid(me));
        log_file("EDIT_LOG",sprintf("(%s) %s edit %s \n",ctime(time()), me->query("name"), file ));

        ed(resolve_path(me->query("cwd"), file));
        return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : edit <档名>, edit here

利用此一指令可直接在线上编辑档案。
HELP
    );
    return 1;
}

