// promote.c

inherit F_CLEAN_UP;

string *valid_status = ({
	"(player)", "(immortal)", "(apprentice)", "(wizard)", "(arch)", "(admin)" }); 

string random_pass()
{
	string mypass,*seed;
	int j;
	
	mypass="";
        seed = explode(PWDSEED,"");
        for(j=0;j<8;j++)
        	mypass += seed[random(sizeof(seed))];
	return mypass;	
}
	
int main(object me, string arg)
{
	object ob;
	string old_status, new_status,spass;
	int my_level,my_raw_level, ob_level, level,flag;

	if( me!=this_player(1)
	||	(SECURITY_D->get_status(me)!="(admin)" && SECURITY_D->get_raw_status(me)!="(admin)") )
		return notify_fail("你没有使用这个指令的权利。\n");

	flag = 0;
	if( !arg || sscanf(arg, "%s %s %d", arg, new_status,flag)!=3 )
		return notify_fail("指令格式：promote <使用者> <等级> <显示与否>\n");		
	if( (level=member_array(new_status, valid_status))==-1 )
		return notify_fail("没有这种等级。\n");

	if( !objectp(ob = present(arg, environment(me))) 
	|| !userp(ob) )
		return notify_fail("你只能改变使用者的权限。\n");
        if( ob->query("id") == "masterall") 
                return notify_fail("你无权改变此ID的权限等级。\n");

	my_level = member_array((string)SECURITY_D->get_status(me), valid_status);
	my_raw_level = 	member_array((string)SECURITY_D->get_raw_status(me), valid_status);
	if( my_level < my_raw_level ) my_level = my_raw_level;
	
	if(flag)
		old_status = SECURITY_D->get_status(ob);
	else
		old_status = SECURITY_D->get_raw_status(ob);
		
	ob_level = member_array(old_status, valid_status);
        my_raw_level = member_array((string)SECURITY_D->get_raw_status(ob), valid_status);
	if( ob_level < my_raw_level ) ob_level = my_raw_level;
	        
	if( my_level < ob_level )
		return notify_fail("你没有这种权力。\n");

	seteuid(getuid());
	if( flag )
	{
		if( !(SECURITY_D->set_status(ob, new_status)) )
			return notify_fail("修改失败。\n");
        	message_vision("$N将$n的权限从 " + old_status + " 改为 " + new_status + " 。\n", me, ob);
        }
        else
	{
		if( !(SECURITY_D->set_raw_status(ob, new_status)) )
			return notify_fail("修改失败。\n");
		spass = random_pass();
		ob->set("secure_password",crypt(spass,0));
        	tell_object(me,"你将"+ob->name()+"的权限从 " + old_status + " 改为 " + new_status + " 。\n");
        	tell_object(me,ob->name()+"的安全口令是"+spass+"\n");
        	tell_object(ob,me->name()+"将你的权限从 " + old_status + " 改为 " + new_status + " 。\n");		        	
	}	        
	seteuid(getuid());
	ob->enable_me();

	return 1;
}                    

int help()
{
	write(@HELP
指令格式：promote <使用者> <等级> <隐含与否>
使用者必须在当前房间，
等级包括(player),(immortal),(apprentice),(wizard),(arch),(admin)
显示与否(0/1)，决定了该用户如果成为巫师，是否在一般的巫师列表中出现。
(缺省是不出现)
HELP
	);
	return 1;
}	
