inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string site;

	if (!arg)
		LOGIN_D->ban_ip("query");
	else if (sscanf(arg, "+ %s", site) == 1) {
		if (site[sizeof(site)-1] == '*' ||
		    site[sizeof(site)-1] == '?' ||
		    site[sizeof(site)-1] == '+')
			write("不能禁以 *, +, ? 结尾的地址。\n");
		else
			{LOGIN_D->ban_ip(arg);write("ok\n");}
		}
	else if (sscanf(arg, "- %s", site) == 1)
		{LOGIN_D->ban_ip(arg);write("ok\n");}
	else write("指令格式：ban [+|- site]\n");

	return 1;
	
}

int help(object me)
{
	write(@HELP
指令格式：ban [+|- site] 或者不带参数(列出当前被禁止的IP)

这条命令是用来防止有人蓄意捣乱。

注意:这个命令只是暂时性的，当机器重起或者update LOGIN_D
后就失去作用了。
HELP
	);
	return 1;
}
