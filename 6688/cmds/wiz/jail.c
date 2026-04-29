// jail.c

inherit F_CLEAN_UP;
int help(object me);

int main(object me, string arg)
{
        object ob,loginob;
        string wiz_status;
        string tmpstr;
	int    block_time,cur_time;
	string name;

        if( me!=this_player(1) ) return 0;
        if( !arg )
        {
        	help(me);
        	return 1;
        }	       	

	if( sscanf(arg, "%s for %d", name,block_time)!=2 )
	{
        	help(me);
        	return 1;
	}
        ob = LOGIN_D->find_body(name);
        if( ob )
	{       
		return notify_fail("请不要对在线用户使用这个指令。\n");
	}        	
	seteuid(getuid());
	loginob = new(LOGIN_OB);
	loginob->set("id",name);
	if( !loginob->restore() )
	{
		write("没有这个用户。\n");
		destruct(loginob);
		return 1;
	}	
	ob = LOGIN_D->make_body(loginob);	
	if( !objectp(ob) )
	{
		write("无法读取用户档案。\n");
		destruct(loginob);
		return 1;
	}	

	if( !(int)(block_time) || block_time < 0 )
		block_time = 0;

	if( block_time > 1440*7 ) //一周
		return notify_fail("既然如此，不如直接purge了呢。:) \n");

	cur_time = time();
	ob->set("block_time",cur_time+block_time*60);
        ob->save();
        destruct(ob);
	destruct(loginob);	
	write("设定成功。\n");	
	return 1;
}



int help(object me)
{
	write(@HELP
 
指令格式 : jail <某人> for <时间> (时间的单位为分)

大概的时间速查：
24小时 = 1440
三天   = 4320
一周   = 10080

封更长的时间可能容易造成难于处理的情况，因此限制为一周以内。
时间为0就是放他出来啦。 

HELP
    );
    return 1;
}
 
