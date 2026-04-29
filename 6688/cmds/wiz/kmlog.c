// kmlog.c
#include <ansi.h>

inherit F_CLEAN_UP;

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	int limit,punish;
	
	if( !arg )
		return notify_fail("kmlog <人数限制> <惩罚时间>\n");

	if( sscanf(arg,"%d %d",limit,punish) != 2 )
		return notify_fail("kmlog <人数限制> <惩罚时间>\n");

	if( limit <= 1 )
		return notify_fail("kmlog <人数限制> <惩罚时间>\n");

	message("shout",HIY"【通知】管理精灵(Managed)：10秒钟后将所有同时连线数>="+limit+"的玩家踢出"+punish+"分钟。\n"NOR,users());
	call_out("start_kick",10,limit,punish);
	write("OK.\n");
	return 1;
}

void start_kick(int limit,int punish)
{
	remove_call_out("start_kick");
	"/adm/daemons/managed"->check_multi_login(limit,punish);
	return;
}

int help(object me)
{
  write(@HELP
指令格式 : kmlog <人数限制> <惩罚时间>
立刻将同时连线人数>限制的玩家踢出一定时间.
HELP
    );
    return 1;
}
 
