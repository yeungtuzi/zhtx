// keepid.c
// yeung

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	object ob;
	string name,option;
	
	if(!arg || sscanf(arg,"%s %s",option,name) == -1)
		return help(me);

	ob = present(name, environment(me));
	
	if( !userp(ob) )
		return notify_fail("你要改变谁的身份？\n");

	if( option == "add" )		
	{
		ob->set("play_for_chat","1");
		message_vision("$N将$n的帐号设置为永久保留。\n",me,ob);
		write("OK.\n");
		return 1;
	}
	
	if( option == "cancel" )		
	{
		ob->delete("play_for_chat");
		message_vision("$N将$n的帐号设置为非永久保留。\n",me,ob);
		write("OK.\n");
		return 1;
	}
	
	return help(me);

	
}

int help(object me)
{
write(@HELP

指令格式 : keepid [add|cancel] <id>

add id
可以设置帐号为永久保留帐号，这样就不会被认为是DUMMY而删除档案。
请谨慎使用这个命令，过多的玩家帐号会消耗系统资源。

cancel id
取消对一个帐号的永久保留。

HELP
    );
    return 1;
}
