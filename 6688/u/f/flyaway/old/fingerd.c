// fingerd.c

#include <net/dns.h>
#include <ansi.h>

int cmp(object,object);

void create() { seteuid( getuid() ); }

string age_string(int time)
{
	int month, day, hour;

	time /= 3600;
	hour = time % 24;
	time /= 24;
	day = time % 30;
	month = time / 30;
	return (month?month+"月":"")+(day?day+"天":"")+hour+"小时";
}

string finger_all()
{
	object *ob;
	int i;
	string msg;

	ob = users();
	msg = "";
	for(i=0; i<sizeof(ob); i++) 
	{
		if( this_player() && !this_player()->visible(ob[i]) ) continue;
		msg+=sprintf("%-20s  %-20s  %-10s ********\n",
			ob[i]->query("name"), ob[i]->query("id"),
			age_string( (int)ob[i]->query("mud_age")) );
	}
	return msg+"\n";
}

string finger_allw()
{
	mapping multi_login = ([]);
	object *usr;
	int i,j;
	string ip,*multi_ip,msg;

	usr = users();
	i = sizeof(usr);
	while( i-- )
		if( !(environment(usr[i])) ) usr[i]=0;
	usr -= ({0});
	usr=sort_array(usr,(:cmp:));
	
	msg = "";

	for( i=0;i<sizeof(usr);i++ )
	{
		msg += sprintf("%-15s %-15s %-20s %s\n",usr[i]->query("name"), 
			usr[i]->query("id"),age_string( (int)usr[i]->query("mud_age")), 
			query_ip_name(usr[i]) );
		if( i != 0 && (ip=query_ip_name(usr[i])) == query_ip_name(usr[i-1]) )
		{
			if(undefinedp(multi_login[ip])) multi_login[ip] = ({ usr[i-1]->query("id")});
			multi_login[ip] += ({ usr[i]->query("id")});
		}
	}

	if( sizeof(multi_login) != 0 )
	{
		msg += sprintf("___________________________________________________________________");
		msg += sprintf(HIR"");
		multi_ip=keys(multi_login);
		for( i=0;i<sizeof(multi_ip);i++ )
		{
			msg += sprintf("\n"+multi_ip[i]+":\n");
			msg += sprintf(implode(multi_login[multi_ip[i]], "\n"));
		}
	}
	msg += sprintf(NOR"\n___________________________________________________________________\n");
	msg += sprintf("共有 %d 位玩家。\n",sizeof(usr));
	return msg+"\n";
}
 
string finger_user(string name)
{
	object ob, body;
	string msg, mud;

	if( sscanf(name, "%s@%s", name, mud)==2 ) {
		GFINGER_Q->send_finger_q(mud, name, this_player(1));
		return "网路指令传送过程可能需要一些时间，请稍候。\n";
	}

	ob = new(LOGIN_OB);
	ob->set("id", name);
	if( !ob->restore() ) return "没有这个玩家。\n";
	msg =  sprintf("\n英文代号：\t%s\n姓    名：\t%s\n权限等级：\t%s\n"
		"电子邮件地址：\t%s\n\n",
		ob->query("id"),
		ob->query("name"),
		SECURITY_D->get_status(name),
		ob->query("email"),
		ob->query("last_from"),
//		ctime(ob->query("last_on"))
	);
	if( objectp(body = find_player(name)) && geteuid(body)==name && this_player()->visible(body) ) {
		msg += sprintf("\n%s目前正在连线中。\n", body->name(1),
			query_ip_name(body));
	}
	destruct(ob);
	return msg;
}

string finger_userw(string name)
{
	object ob, body;
	string msg, mud;

	if( sscanf(name, "%s@%s", name, mud)==2 ) {
		GFINGER_Q->send_finger_q(mud, name, this_player(1));
		return "网路指令传送过程可能需要一些时间，请稍候。\n";
	}

	ob = new(LOGIN_OB);
	ob->set("id", name);
	if( !ob->restore() ) return "没有这个玩家。\n";
	msg =  sprintf("\n英文代号：\t%s\n姓    名：\t%s\n权限等级：\t%s\n"
		"电子邮件地址：\t%s\n上次连线地址：\t%s( %s )\n真实姓名：\t%s\n所属组织：\t%s\n"
		"通讯地址：\t%s\n隐含权限：\t%s\n\n",
		ob->query("id"),
		ob->query("name"),
		SECURITY_D->get_status(name),
		ob->query("email"),
		ob->query("last_from"),
		ctime(ob->query("last_on")),
		ob->query("realname"),
		ob->query("schoolname"),		
		ob->query("postadd"),		
		SECURITY_D->get_raw_status(name)				
	);
	if( objectp(body = find_player(name)) && geteuid(body)==name && this_player()->visible(body) ) {
		msg += sprintf("\n%s目前正在从 %s 连线中。\n", body->name(1),
			query_ip_name(body));
	}
	destruct(ob);
	return msg;
}

varargs string remote_finger_user(string name, int chinese_flag)
{
	object ob, body;
	string msg;

	ob = new(LOGIN_OB);
	ob->set("id", name);
	if( !ob->restore() )
		return chinese_flag ? "没有这个玩家。\n" : "No such user.\n";
	if( chinese_flag ) msg =  sprintf(
		"\n英文代号：\t%s\n姓    名：\t%s\n权限等级：\t%s\n"
		"电子邮件地址：\t%s\n\n",
		ob->query("id"),
		ob->query("name"),
		SECURITY_D->get_status(name),
		ob->query("email"),
		ob->query("last_from"),
//		ctime(ob->query("last_on"))
	);
	else msg =  sprintf(
		"\nName\t: %s\nStatus\t: %s\nEmail\t: %s\n\n",
		capitalize(ob->query("id")),
		SECURITY_D->get_status(name),
		ob->query("email"),
		ob->query("last_from"),
//		ctime(ob->query("last_on"))
	);
	if( body = find_player(name) ) {
		if( !this_player() || this_player()->visible(body) )
			msg += chinese_flag ?
				("\n" + ob->query("name") + "目前正在线上。\n"):
				("\n" + capitalize(name) + " is currently connected.\n");
	}

	destruct(ob);
	return msg;
}

varargs string remote_finger_userw(string name, int chinese_flag)
{
	object ob, body;
	string msg;

	ob = new(LOGIN_OB);
	ob->set("id", name);
	if( !ob->restore() )
		return chinese_flag ? "没有这个玩家。\n" : "No such user.\n";
	if( chinese_flag ) msg =  sprintf(
		"\n英文代号：\t%s\n姓    名：\t%s\n权限等级：\t%s\n"
		"电子邮件地址：\t%s\n上次连线地址：\t%s( %s )\n\n",
		ob->query("id"),
		ob->query("name"),
		SECURITY_D->get_status(name),
		ob->query("email"),
		ob->query("last_from"),
		ctime(ob->query("last_on"))
	);
	else msg =  sprintf(
		"\nName\t: %s\nStatus\t: %s\nEmail\t: %s\nLastOn\t: %s( %s )\n\n",
		capitalize(ob->query("id")),
		SECURITY_D->get_status(name),
		ob->query("email"),
		ob->query("last_from"),
		ctime(ob->query("last_on"))
	);
	if( body = find_player(name) ) {
		if( !this_player() || this_player()->visible(body) )
			msg += chinese_flag ?
				("\n" + ob->query("name") + "目前正在线上。\n"):
				("\n" + capitalize(name) + " is currently connected.\n");
	}

	destruct(ob);
	return msg;
}

object acquire_login_ob(string id)
{
	object ob;

	if( ob = find_player(id) ) {
		// Check if the player is linkdead
		if( ob->query_temp("link_ob") )
			return ob->query_temp("link_ob");
	}
	ob = new(LOGIN_OB);
	ob->set("id", id);
	return ob->restore() ? ob : 0;
}

int cmp( object a,object b)
{
	int i,j,tmp;
	string *ip1,*ip2,arg;
	int *ipn1=({}),*ipn2=({});

	arg=query_ip_number(a);

	ip1=explode(arg,".");
	
	ipn1=({});
	for( i=0;i<4;i++ )
	{
		sscanf(ip1[i],"%d",tmp);
		ipn1 += ({tmp});
	}

	arg=query_ip_number(b);

	ip2=explode(arg,".");

	ipn2=({});
	for( i=0;i<4;i++ )
	{
		sscanf(ip2[i],"%d",tmp);
		ipn2 += ({tmp});
	}

	if( ipn1[0]<ipn2[0] )	return -1;
	if( ipn1[0]>ipn2[0] )	return 1;	
	if( ipn1[0]==ipn2[0] )
	{
		if( ipn1[1]<ipn2[1] )	return -1;
		if( ipn1[1]>ipn2[1] )	return 1;
		if( ipn1[1]==ipn2[1] )
		{
			if( ipn1[2]<ipn2[2] )	return -1;
			if( ipn1[2]>ipn2[2] )	return 1;
			if( ipn1[2]==ipn2[2] )
			{
				if( ipn1[3]<ipn2[3] )	return -1;
				if( ipn1[3]>ipn2[3] )	return 1;
				if( ipn1[3]==ipn2[3] )	return 0;
			}
		}
	}
}

