// /cmds/arch/tcpip.c
// 支持tcpip协议的Lpc telnet proxy
// 现在只有一点小问题了 :))
// ReWrite by akuma@xo 
// CopyRight 2000 Xo_Group

// 这个是命令，真正用用的是tcpip.c的body

inherit F_CLEAN_UP;

void create() 
{ 
        seteuid(getuid()); 
}

int main(object me,string arg)
{
        object ob;
        object linkob;
        object *tcpip;
        // 2026-04-30: unused variable commented out
        // int i;
        me=this_player();
        
        if( strsrch(arg," ")==-1) arg+=" 23";
                
        tcpip=children("/feature/tcpip");
        ob=new("/feature/tcpip");       
        linkob = me->query_temp("link_ob");
        exec(ob,me);
        ob->do_telnet(arg);
        ob->do_command("");
        me->save();
        linkob->save();
        call_out("do_dest",2,me);
        call_out("do_dest",2,linkob);
        return 1;
}
void do_dest(object ob)
{
        destruct(ob);
}


