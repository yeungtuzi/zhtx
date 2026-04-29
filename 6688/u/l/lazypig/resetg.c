#define MAX_ENV_VARS    20
 
inherit F_CLEAN_UP;
 
int help();

int main(object me,string arg)
{
	object login_ob,user_ob;
          if( me != this_player(1) ) return 0;

        me=this_player();
        if( me->query("combat_exp")>2500000) return notify_fail("你已经是高手了,不能重新分配属性\n!");
        if( me->query("mud_age")>172800) return notify_fail("你已经长大成人了,不能重新分配属性\n!);
        if( me->query_skill("force",1)>220) return notify_fail("你的内功心法等级太高,不合适重新分配属性\n");
	if( !arg || !(user_ob = find_player(arg)) )
		return help();
	if( !userp(user_ob) || !(login_ob=user_ob->query_temp("link_ob")) )
	{
		write("Cannot find this player's login object.\n");
		return 1;
	}	
	user_ob->set("reset_gift_accquired",1);
	login_ob->set("reset_gift_accquired",1);
	user_ob->save();
	login_ob->save();
	tell_object(user_ob,"Please quit and login now to select your gift again.\n");
	user_ob->fcommand("quit");
	return 1;
}

int help()
{
	write("
@HELP
	This command will help wizard to rellocate gifts for player.
	Formant: resetgift username
	by Yeung, 2001-12-10
HELP
	");
	return 1;
}

