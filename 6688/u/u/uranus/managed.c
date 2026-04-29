// managed.c by yeung

// 99/7/11修改
// 加入自动存盘,增强了对proxy的定义,可以指定最大连接数
// yeung

//改正自动存盘消耗时间太多的问题

inherit F_DBASE;
#include <ansi.h>

void check_multi_login(int limit,int punish);
void read_proxy();
void write_proxy();
void kickout_ip(string ip,int time);
void auto_save();
void auto_save_back();
string query_save_file();

int saveing;
mapping proxys;

void create()
{
	seteuid(ROOT_UID);
        set("name","管理精灵");
        set("id","managed");
	read_proxy();	
	call_out("check_multi_login",5,0,0);
//	call_out("auto_save",900);
//      call_out("auto_save_back",1200);
	saveing = 0;	
}

string query_save_file()
{
	return DATA_DIR+"proxy";
}

void auto_save()
{
	object *usr,link_ob;
	int i;

	remove_call_out("auto_save");
	call_out("auto_save_back",900);	
	
	saveing = 1;	
	usr = users();
	i = sizeof(usr);
	while( i-- )
		if( !(environment(usr[i])) ) usr[i]=0;
	usr -= ({0});
	
	reset_eval_cost();
	i = sizeof(usr);
	while( i-- )
	{
		if( objectp(link_ob=(usr[i])->query_temp("link_ob")) )
		{
			tell_object(usr[i],"自动存盘...");
			usr[i]->save(1);
			link_ob->save();
			tell_object(usr[i],"完毕.\n");
		}
	}	
	saveing = 0;
}

void auto_save_back()
{
	object *usr,link_ob;
	int i;

      remove_call_out("auto_save_back");
         call_out("auto_save",900);
	
	saveing = 1;	
	usr = users();
	i = sizeof(usr);
	while( i-- )
		if( !(environment(usr[i])) ) usr[i]=0;
	usr -= ({0});
	
	reset_eval_cost();
	i = sizeof(usr);
	while( i-- )
	{
		if( objectp(link_ob=(usr[i])->query_temp("link_ob")) )
		{
			tell_object(usr[i],"自动备份数据...");
			usr[i]->save_back();
			link_ob->save_back();
			tell_object(usr[i],"完毕.\n");
		}
	}	
	saveing = 0;
}

void read_proxy()
{
	if(!restore_object(query_save_file()))
		CHANNEL_D->do_channel(this_object(),"sys","无法读取PROXY设定文件.\n");
}

void write_proxy()
{
	save_object(query_save_file());
}

void add_proxy(string pxy,int num)
{
	if( !mapp(proxys) ) 
		proxys = ([ pxy: num ]);
        else 
        	proxys[pxy] = num;
	write_proxy();
}

void remove_proxy(string pxy)
{
        if( mapp(proxys) )
                map_delete(proxys, pxy);
	write_proxy();
}

void list_proxy()
{
	int j,k;
	string *pname;

	if( !mapp(proxys) )
	{
		printf("目前没有注册的PROXY.\n",k);
		return;
	}	
	printf("\n                          "+HIY"已登记的proxy有                          \n"NOR);	
	printf("\n___________________________________________________________________\n");	
	printf("IP地址\t\t\t\t\t  最大允许连接数\n");
	printf("___________________________________________________________________\n");
	
	pname = keys(proxys);
	k = sizeof(pname);
	for(j=0;j<k;j++)
		printf("%s\t\t\t\t\t%d\n",pname[j],(int)proxys[pname[j]]);

	printf("___________________________________________________________________\n");
	printf("                      共计%d个已注册的proxy ip                     \n",k);
}

void check_multi_login(int limit,int punish)
{
	mapping multi_login = ([]);
	object *usr;
	int i,j,login_num;
	string ip,*multi_ip,*pname;

	remove_call_out("check_multi_login");
	call_out("check_multi_login",600,0,0);

	//如果正在自动存盘,不检查
	if( saveing ) return;
	
	usr = users();
	i = sizeof(usr);
	
	//清除所有的尝试连线的连接
	//清除所有断线的用户,防止类似仙客来的断线BUG
	seteuid(ROOT_UID);
	while( i-- )
	{
		if( !(environment(usr[i])) )
		{
			tell_object(usr[i],"系统清理多重连线用户中,请您等待1分钟后再来.\n");
			destruct(usr[i]);
			usr[i]=0;
			continue;
		}
		if( usr[i]->query_temp("netdead") )
		{
			tell_room( environment(usr[i]), HIW "侮天鬼王" RED+"敲了敲"+usr[i]->query("name") + "的脑袋：咦？没有魂魄了？那还不快滚？说罢一脚把"+usr[i]->query("name")+"踢了出去！\n");
			usr[i]->save(1);
			usr[i]->save_back(1);
			destruct(usr[i]);
			usr[i]=0;
			continue;			
		}
	}
	
	seteuid(getuid());
	usr -= ({0});
	i = sizeof(usr);

	if(i<100) return; //100人以下不检查
	
	if( limit <= 0 )
	{
		if(i<120)
		{
			limit = 3; //120人以下禁止三连线
			if( punish <= 0 ) punish = 5; //并禁止登录5 min
		}
		else
		{
			limit = 2; //120人以上禁止双连线
			if( punish <= 0 ) punish = 10; //并禁止登录5 min
		}
		
	}

	multi_login = ([]);

	for( i=0;i<sizeof(usr);i++ )
	{

		ip=query_ip_name(usr[i]);

		if( undefinedp(multi_login[ip]) ) 
			multi_login[ip] = 1;
		else
			multi_login[ip] = (int)multi_login[ip]+1;
	}

	multi_ip=keys(multi_login);
	pname = keys(proxys);
	
	for( i=0;i<sizeof(multi_ip);i++ )
	{
		login_num = (int)multi_login[multi_ip[i]];

		if( member_array(multi_ip[i],pname) != -1 && login_num < (int)proxys[multi_ip[i]])
			continue;

		if( login_num >= limit )
			kickout_ip(multi_ip[i],punish);
	}
	return;
}

void kickout_ip(string ip,int time)
{
	object *usr;
	int i,cur_time;

	message("shout",HIY"【通知】管理精灵(Managed)：中止"+ip+"的访问。\n"NOR,users());
	
	reset_eval_cost(); //这个用来防止too long execution error...
	usr = users();
	i = sizeof(usr);
	while( i-- )
	{
		if( query_ip_name(usr[i]) == ip && !wiz_level(usr[i]) )
		{
			if( time )
			{
				cur_time = time();
				(usr[i])->set("block_time",cur_time+time*60);
			}
		
			tell_object(usr[i],"对不起，您因为多重连线而被暂时终止连接。"+(time?"\n请您等候"+time+"分之后再来。\n":"\n"));
        		usr[i]->save(1);
        		usr[i]->save_back(1);
        		destruct(usr[i]);
		}
	}
}

