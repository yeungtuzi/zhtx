// purge.c

#include <ansi.h>
#define SYNTAX	"指令格式：purge [ -1 (Dummy) | <未上线天数> | <使用者姓名> because <原因>]\n"
#define SAVE_EXTENSION ".o"
#define SAVE_BAK ".bak.o"

inherit F_CLEAN_UP;
inherit F_DBASE;

int is_dummy(string name);
private int do_purge_dummy();
private int do_purge_players(int day);
private int do_purge_dummy_file(string name);

int main(object me, string arg)
{
	string name, reason;
	string status,*custom_ob,first,id;
	int day,i,n;

	status = wizhood(me);
	if( me!=this_player(1)
	|| wiz_level(me) < wiz_level(status) )
		return notify_fail("你没有权力使用这个指令。\n");

	if( !arg ) return notify_fail(SYNTAX);

	if( arg == "-1" ) return do_purge_dummy();
	
	if( sscanf(arg, "%d", day) && day >= 0) return do_purge_players(day);

	if( sscanf(arg, "%s because %s", name, reason)!=2 )
		return notify_fail(SYNTAX);

	seteuid(getuid());
	if( file_size(DATA_DIR + "login/" + name[0..0] + "/" + name + SAVE_EXTENSION)<0 )
		return notify_fail("没有这位使用者。\n");

	rm(DATA_DIR + "login/" + name[0..0] + "/" + name + SAVE_EXTENSION);
	rm(DATA_DIR + "user/" + name[0..0] + "/" + name + SAVE_EXTENSION);
        rm(DATA_DIR + "login/" + name[0..0] + "/" + name + ".bak" + SAVE_EXTENSION);    rm(DATA_DIR + "user/" + name[0..0] + "/" + name + ".bak" + SAVE_EXTENSION);
	//by yeung. 99/03/04
	// purge 同时删除自定物品
	seteuid(ROOT_UID);
	id = name;
	n = strlen(id);
	//删除武器
	custom_ob=get_dir("/data/weapon/"+id[0..0]+"/"+id+"*.c");
	i = sizeof(custom_ob);
	while(i--)
	{
		first = custom_ob[i];
		if( first[n] <= 'z' && first[n] >='a' )	continue;
		rm( "/data/weapon/"+id[0..0]+"/"+custom_ob[i]);
        	write("Purge：Delete file "+"/data/weapon/"+id[0..0]+"/"+custom_ob[i]+"\n");
       	}
	//删除衣服
	custom_ob=get_dir("/data/cloth/"+id[0..0]+"/"+id+"*.c");
	i = sizeof(custom_ob);
	while(i--)
	{
		first = custom_ob[i];
		if( first[n] <= 'z' && first[n] >='a' )	continue;
		rm( "/data/cloth/"+id[0..0]+"/"+custom_ob[i]);
        	write("Purge：Delete file "+"/data/cloth/"+id[0..0]+"/"+custom_ob[i]+"\n");
       	}
	//删除信件
	rm( "/data/mail/"+id[0..0]+"/"+id+".o" );
       	write("Purge：Delete file "+"/data/mail/"+id[0..0]+"/"+id+".o"+"\n");

	write( "使用者 " + capitalize(name) + " 删除掉了。\n");
	log_file("static/PURGE", sprintf("[%s] %s purged %s because %s.\n",
		ctime(time())[0..15], geteuid(this_player(1)), name, reason));

	return 1;
}

// 正常玩家的判断标准:
// dummy和正常玩家的最大区别是DUMMY不做任务，不挣潜能
// 因此以完成任务数量和learn_point作为判断标准。
// 茅山学的最容易，学完是 15 万点 lp。
// lp大于这个数值的和经验>50万的不检查。

// 登录的前7天要做10个任务，100 lp
// 第十四天要做25个任务,150 lp
// 第30天要做 50 个任务，800 lp
// 此后任务数量不能<login_days*2个, lp不能<login_days*30
// 否则就是dummy
// 对怀疑是dummy的人物,并不真正删除,而是放在一个备份
// 目录下面,以免误杀. 该备份目录可以定期删除.

// Yeung 99/05/08
int is_dummy(string name)
{
	object ob,user;
	mapping ob_map;
	int days,lp,tasks;
        
        reset_eval_cost();
        ob = new(LOGIN_OB);
        ob->set("id", name);
        if( !ob->restore() ) return 0;
        if( !objectp(user = LOGIN_D->make_body(ob)) ) return 0;
        if( !user->restore() ) return 0;
        	
	ob_map = user->query_entire_dbase();
	
	//write("\n"+name+" "+ob->query("name")+" "+ob_map["id"]);
	
	//经验>50万不检查
	if( (int)ob_map["combat_exp"] > 500000 ) return 0;
	
	lp = (int)ob_map["learned_points"];
	tasks = (int)ob_map["score"];
	
	//learn_points>15万不检查
	if( lp > 150000 ) return 0; 

	//申请的聊天帐号不检查	
	if( ob_map["play_for_chat"] ) return 0;
	
	days = (time() - ob_map["birthday"])/86400;
		
	if( days > 7 && (tasks < 10|| lp < 100) )
		return 1;
	if( days > 14 && (tasks < 25 || lp <150) )
		return 1;
	if( days > 30 && (tasks < 50 || lp < 800) )
		return 1;
	if( tasks < (days*2) || lp < (days*30) )
		return 1;

	return 0;
	
}

private int do_purge_dummy_file(string name)
{

        string status,*custom_ob,first;
        int i,n;
        
        reset_eval_cost();	

	cp(DATA_DIR + "login/" + name[0..0] + "/" + name + SAVE_EXTENSION,"/databak/login/" + name + SAVE_EXTENSION);
	cp(DATA_DIR + "user/" + name[0..0] + "/" + name + SAVE_EXTENSION,"/databak/user/"  + name + SAVE_EXTENSION);

	rm(DATA_DIR + "login/" + name[0..0] + "/" + name + SAVE_EXTENSION);
	rm(DATA_DIR + "user/" + name[0..0] + "/" + name + SAVE_EXTENSION);
        rm(DATA_DIR + "login/" + name[0..0] + "/" + name + ".bak" + SAVE_EXTENSION);    rm(DATA_DIR + "user/" + name[0..0] + "/" + name + ".bak" + SAVE_EXTENSION);
	rm(DATA_DIR + "user/" + name[0..0] + "/" + name + ".bak" + SAVE_EXTENSION);    rm(DATA_DIR + "user/" + name[0..0] + "/" + name + ".bak" + SAVE_EXTENSION);

	// purge 同时删除自定物品
	n = strlen(name);
	//删除武器
	custom_ob=get_dir("/data/weapon/"+name[0..0]+"/"+name+"*.c");
	i = sizeof(custom_ob);
	while(i--)
	{
		first = custom_ob[i];
		if( first[n] <= 'z' && first[n] >='a' )	continue;
		rm( "/data/weapon/"+name[0..0]+"/"+custom_ob[i]);
        	//write("Purge：Delete file "+"/data/weapon/"+name[0..0]+"/"+custom_ob[i]+"\n");
       	}
	//删除衣服
	custom_ob=get_dir("/data/cloth/"+name[0..0]+"/"+name+"*.c");
	i = sizeof(custom_ob);
	while(i--)
	{
		first = custom_ob[i];
		if( first[n] <= 'z' && first[n] >='a' )	continue;
		rm( "/data/cloth/"+name[0..0]+"/"+custom_ob[i]);
        	//write("Purge：Delete file "+"/data/cloth/"+id[0..0]+"/"+custom_ob[i]+"\n");
       	}
	//删除信件
	rm( "/data/mail/"+name[0..0]+"/"+name+".o" );
	
	return 1;
}

private int do_purge_dummy()
{
	int i, j, ppl_cnt, count;
	string *dir, *ppls, name;
	mixed info;

	seteuid(getuid());
	message("system", HIY"\n*** 整理玩家储存档中，请稍候.... ***\n"NOR, users());
	write("处理中：");
	count = 0;
	ppl_cnt = 0;
	dir = get_dir(DATA_DIR + "user/");
	for(i=0; i<sizeof(dir); i++) {
		reset_eval_cost();
		write(dir[i]);
		ppls = get_dir(DATA_DIR + "user/" + dir[i] + "/");
		for(j=0; j<sizeof(ppls); j++) {
			//忽略*.bak.o       yeung 99/05/08
			if( sscanf(ppls[j], "%s.bak.o", name)==1 ) continue;	
			ppl_cnt ++;
			if( sscanf(ppls[j], "%s.o", name)==1 )
			{
	//			write("\n"+HIG"processing "+name+NOR+"\n");
				if( (string)SECURITY_D->get_status(name)!="(player)" )
					continue;
				if( is_dummy(name) )
				{
					do_purge_dummy_file(name);
					count ++;
				}
			}
		}
	}
	write("\n\n原来总共有 " + ppl_cnt + " 位使用者。\n");
	write( count + " 个被怀疑为DUMMY的使用者被清除掉了。\n");
	write("现在总共有 " + (ppl_cnt - count) + " 位使用者。\n");
	log_file("static/PURGE", sprintf("[%s] %s purged %d dummy-like characters.\n"
		"\t\tResulting statistics: %d characters remaining.\n",
		ctime(time())[0..15], geteuid(this_player(1)), count, ppl_cnt - count));

	return 1;

}

private int do_purge_players(int day)
{
	int i, j, ppl_cnt, count;
	string *dir, *ppls, name;
	mixed info;

	seteuid(getuid());
	message("system", "\n*** 整理玩家储存档中，请稍候.... ***\n", users());
	write("处理中：");
	count = 0;
	ppl_cnt = 0;
	dir = get_dir(DATA_DIR + "login/");
	for(i=0; i<sizeof(dir); i++) {
		reset_eval_cost();
		write(dir[i]);
		ppls = get_dir(DATA_DIR + "login/" + dir[i] + "/");
		ppl_cnt += sizeof(ppls);
		for(j=0; j<sizeof(ppls); j++) {
			//忽略*.bak.o       yeung 99/05/08
			if( sscanf(ppls[j], "%s.bak.o", name)==1 ) continue;	
			if( sscanf(ppls[j], "%s.o", name)==1 )
				if( (string)SECURITY_D->get_status(name)!="(player)" )
					continue;
			info = stat(DATA_DIR + "login/" + dir[i] + "/" + ppls[j]);
			if( (time()-(int)info[1])/86400 >= day ) {
				rm(DATA_DIR + "login/" + dir[i] + "/" + ppls[j]);
				rm(DATA_DIR + "user/" + dir[i] + "/" + ppls[j]);
				count ++;
			}
		}
	}
	write("\n\n原来总共有 " + ppl_cnt + " 位使用者。\n");
	write( count + " 个超过 " + day + " 天未上线的使用者被清除掉了。\n");
	write("现在总共有 " + (ppl_cnt - count) + " 位使用者。\n");
	log_file("static/PURGE", sprintf("[%s] %s cleaned up %d characters who didn't login for more than %d days\n"
		"\t\tResulting statistics: %d characters remaining.\n",
		ctime(time())[0..15], geteuid(this_player(1)), count, day, ppl_cnt - count));


	return 1;
}

int help(object me)
{
write(@HELP
指令格式：purge [<未上线天数>] | <使用者姓名> because <原因>

清除一个使用者或清除超过一定天数不曾上线地使用者。
HELP
	);
    return 1;
}
