// note.c
 
 
inherit F_CLEAN_UP;
 
int help();
 
int main(object me, string arg)
{
    	// 2026-04-30: unused variable commented out
    	// int i;
	object ob;
	mapping quest; 

	if( me != this_player(1) ) return 0;
	if( !arg )
		return help();

	if( arg == "here" )
		ob = environment(me);
	else
	if( !ob = present(arg,environment(me)) )
		return notify_fail("你要记录什么？\n");
		
	message_vision("$N掏出纸笔，工整地记下了自己的所见所闻。。\n",me);
	quest = me->query("quest");
	if( !mapp(quest) || !sizeof(quest) )
		return 1;
	if( userp(ob) )
		return 1;
	
	if( quest["quest_type"] == "探路" || quest["quest_type"] == "寻人" )
	{
		if( base_name(ob) == quest["exact"] && me->query("task_time") > time() && !me->query("over_time") )
		{
			me->set("over_time",time());	
		}
	}
 
	return 1;
}
 
int help()
{
	write(@TEXT
指令格式：note here 或者 note <id>
 
当你找到了任务所需要找到的地方或者人物时，使用这个命令
来记录下来你的收获，回去就可以向你的师门报告(report)了。

TEXT
	);
	return 1;
}
