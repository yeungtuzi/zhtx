// mp.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object *ob;
	int i;

	ob=users();
	for(i=0;i<sizeof(ob);i++)
	{
		if( ob[i]->query("family/family_name")==me->query("family/family_name")
			&& !ob[i]->query("env/mp_brief") )
			continue;
		ob[i]=0;
	}
	ob -= ({0});
	ob -= ({me});
	ob += ({me});

	message("menpai", HIW "【"+me->query("family/family_name")+"】" 
		+ me->name(1) + "：" + arg + "\n" NOR, ob);
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式：mp <讯息>

用这条指令,你可以与本门派的人对话。

HELP
	);
	return 1;
}
