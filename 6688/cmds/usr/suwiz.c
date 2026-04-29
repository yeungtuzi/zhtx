// su.c

#include <ansi.h>

inherit F_CLEAN_UP;

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{

	if( me != this_player(1) ) return 0;

	if( !raw_wiz_level(me) )  return 0;
        if( me->query_temp("supervision") )
        {
        	write("你已经处于管理模式了，现在的权限等级是"+raw_wizhood(me)+"\n");      
        	return 1;
        }	         
	
        write("请输入你的安全口令：");
	input_to("check_pass", 1, me);        
	return 1;
}

private void check_pass(string pass, object me)
{
	string old_pass;
	int lvl;


	write("\n");
	old_pass = me->query("secure_password");
	if( crypt(pass, old_pass)!=old_pass ) {
		write("密码错误！\n");
		return;
	}       
	
	seteuid(getuid());
	tell_object(me,"\n你只觉得眼前一亮，整个世界以完全不同的方式，呈现在你的面前。\n");
	tell_object(me,HIY"你现在进入了管理模式，请注意，这之后你的所有动作都将被记录下来。\n"NOR);
	tell_object(me,HIY"权力同时意味着责任，请善用你的权力，并及时退出(quit)管理模式。\n\n"NOR);
	me->enable_player1();
	return;
}

int help(object me)
{
    write(@HELP
指令格式 : su
 
这个指令, 用于提升自己的权限等级，当然，你需要输入必要的
口令供系统检查。 

HELP
    );
    return 1;
}
 
