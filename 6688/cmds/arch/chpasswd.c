// chpasswd.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;
	
        if( me != this_player(1) ) return 0;

	if(!arg) return 0;
	if(wizhood(arg)!="(player)"||raw_wizhood(arg)!="(player)") return notify_fail("没有这个玩家。\n");
	if(! (ob = new(LOGIN_OB))) return notify_fail("can't load login object\n");
        ob->set("id", arg);
        if( !ob->restore() ) {
		destruct(ob);
		return notify_fail("读取玩家记录失败。\n");
	}
	write("请输入新的密码：");
        input_to("get_new_pass", 1, ob ,arg);
	return 1;
}


private void get_new_pass(string pass, object ob,string arg)
{
	write("\n请再输入一次新的密码：");
	input_to("confirm_new_pass", 1,ob, crypt(pass,0),arg);
}

private void confirm_new_pass(string pass, object ob, string new_pass,string arg)
{
	write("\n");
	if( crypt(pass, new_pass)!=new_pass ) {
		write("对不起，您输入的密码并不相同，保持原来的密码。\n");
		destruct(ob);
		return;
	}
	seteuid(getuid());
	if( !ob->set("password", new_pass) ) {
		write("密码变更失败！\n");
		destruct(ob);
		return;
	}

	ob->save();
	write("密码变更成功\。\n");
        log_file("CHPASS_LOG",sprintf("(%s) %s change  passwd of %s \n",ctime(time()), this_player()->query("id"), arg ));
	destruct(ob);
}

int help(object me)
{
	write(@HELP
指令格式 : passwd
 
这个指令可以修改玩家的密码。
 
HELP
    );
    return 1;
}
 
