// proxy.c

inherit F_CLEAN_UP;

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	string cmd,ip;
	int num;
	
	if( !arg )
		return notify_fail("proxy [list|add <ip> <max_connections>|remove <ip>]\n");
	if( arg == "list" )
	{
		"/adm/daemons/managed"->list_proxy();
		return 1;
	}

	if( sscanf(arg,"%s %s %d",cmd,ip,num) == 3 )	
	{
		if( cmd == "add" && num > 1 )
		{
			"/adm/daemons/managed"->add_proxy(ip,num);
			write("OK.\n");
			return 1;
		}
		return notify_fail("proxy [list|add <ip> <max_connections>|remove <ip>]\n");
	}
	
	if( sscanf(arg,"%s %s",cmd,ip) == 2 )
	{
		if( cmd == "remove" )
		{
			"/adm/daemons/managed"->remove_proxy(ip);
			write("OK.\n");
			return 1;
		}
		return notify_fail("proxy [list|add <ip> <max_connections>|remove <ip>]\n");
	}

	return notify_fail("proxy [list|add <ip> <max_connections>|remove <ip>]\n");
}

int help(object me)
{
  write(@HELP
指令格式 : proxy [list|add|remove]
 
这个指令, 对应参数不同而有以下功能:

proxy list 
	列出现在系统中注册的proxy.
proxy add ip max_num
 	注册某一IP为proxy,该proxy最多允许max_num个连接.
proxy remove ip  
	取消该IP的proxy注册.
HELP
    );
    return 1;
}
 
