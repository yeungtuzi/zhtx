// id.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int i, j;
	object obj, *inv;
	string *id;

	if( !arg ) {
		inv = all_inventory(me);
		if( !sizeof(inv) )
			return notify_fail("你身上没有任何东西。\n");
        write( "你(□)身上携带物品的别称如下(右方) :\n");
		for(i=0; i<sizeof(inv); i++) {
			if( !me->visible(inv[i]) ) continue;
			printf("%-20s = %s\n", inv[i]->name(),
				implode(inv[i]->parse_command_id_list(), ", ") );
		}
		return 1;
	}

	if( arg=="here" ) {
		inv = all_inventory(environment(me));
		if( !sizeof(inv) )
			return notify_fail("这里没有任何东西。\n");
        write( "在这个房间中, 生物及物品的(英文)名称如下 :\n");
		for(i=0; i<sizeof(inv); i++) {
			if( !me->visible(inv[i]) ) continue;
			printf("%-20s = %s\n", inv[i]->name(),
				implode(inv[i]->parse_command_id_list(), ", ") );
		}
		return 1;
	}
	else{
		string msg;

		inv=users();
		msg="";
		for(i=0;i<sizeof(inv);i++)
		{	
			if(inv[i]->name()==arg)
				if(wizardp(me))
					msg += sprintf( "%-20s : 拜师于%s\n",
						inv[i]->query("name")+"("+inv[i]->query("id")+")",
						inv[i]->query("family/family_name") );
				else
					if(inv[i]->query_temp("apply/name") || inv[i]->query_temp("apply/id") )
						msg += sprintf( "%-20s : 拜师于%s\n",
							arg+"(??????)",
							"?????????" );
					else
						msg += sprintf( "%-20s : 拜师于%s\n",
							arg+"("+inv[i]->query("id")+")",
							inv[i]->query("family/family_name") );

		}
		if(!sizeof(msg)) write("没找到这个玩家。\n");
		else write(msg);
		return 1;
	}
}
int help(object me)
{
write(@HELP
指令格式 : id [here] or id <玩家的中文名字>
 
这个指令可以让你知道物品的英文名称及名字. 只打 id 会显示
你身上所携带物品的名称. 'id here' 则显示所有跟你在同一个
环境里的物件名称.
当用id <玩家的中文名字>时，会取得玩家的id.
 
HELP
    );
    return 1;
}
 
