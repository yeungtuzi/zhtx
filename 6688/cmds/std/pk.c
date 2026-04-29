// pk.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object obj;
	string *pk_id, callname;

	//在除了休息室的任何地方战斗
	if(  environment(me)->query("sleep_room") || environment(me)->query("no_death") )
		return notify_fail("这里不准战斗。\n");

	if( me->query("combat_exp") < 50000 )
		return notify_fail("你武功尚浅,现在不能参加江湖仇杀. \n");
		
        if( me->query("id") == "diablo" )
                return notify_fail("由于你胡乱使用此指令，被取消了PK的资格，还是好好反省一下先. \n");
	if( !arg )
		return notify_fail("你想杀谁？\n");

	if(!objectp(obj = present(arg, environment(me))))
		return notify_fail("这里没有这个人。\n");

	if( !obj->is_character() || obj->is_corpse() )
		return notify_fail("看清楚一点，那并不是活物。\n");

	if(obj==me)
		return notify_fail("用 suicide 指令会比较快:P。\n");

	if( !userp(obj) )
		return notify_fail("这个命令只能对玩家使用。\n");

	//当杀手帮的杀手戴上面具时,使面具失效
	if( userp(obj) )
	{
		if( me->query_temp("pker_masked") )
		{
			me->delete_temp("apply/id");
			me->delete_temp("apply/name");
			me->delete_temp("apply/short");
			me->delete_temp("apply/long");
		}
	}

	callname = RANK_D->query_rude(obj);

	message_vision("\n$N对著$n喝道：「" 
		+ callname + "！今日不是你死就是我活！」\n\n", me, obj);

	if( (int)(obj->query("combat_exp"))/((int)me->query("combat_exp")+1) > 10 )
		return notify_fail("他比你强这么多，想找死吗？\n");
		
	// 捣乱dummy可以杀,经验>150万的老家伙也可以随便杀 *_^
	if( obj->query("combat_exp") < 5000 || obj->query("combat_exp") > 1500000 )
	{
		me->bihua_ob(obj);
		obj->bihua_ob(me);
	      	tell_object(obj, HIR "如果你要和" + me->name() 
			+ "性命相搏，请你也对这个人下一次 pk 指令。\n" NOR);
		if(obj->query("combat_exp") > 1500000)
		{
			me->apply_condition("quit_delay",15);
			obj->apply_condition("quit_delay",7);
		}
	       	
	       	log_file("PK_LOG",sprintf("%s(%s) trys to kill %s(%s) on %s and will not be punished.\n",
                                me->name(1), geteuid(me), obj->name(1), geteuid(obj),ctime(time()) ) );

	}
	else if((int)me->query("age") >= 15 && ( me->query("combat_exp")/(obj->query("combat_exp")+1) < 5) )
	{
                
                me->kill_ob(obj);
	     	obj->bihua_ob(me);
		tell_object(obj, HIR "如果你要和" + me->name() 
			+ "性命相搏，请你也对这个人下一次 pk 指令。\n" NOR);

   		me->apply_condition("quit_delay",15);
		obj->apply_condition("quit_delay",7);

		log_file("PK_LOG",sprintf("%s(%s) trys to kill %s(%s) on %s and will be punished.\n",
                                me->name(1), geteuid(me), obj->name(1), geteuid(obj),ctime(time()) ) );
			
        }
        else {
                  if((int)me->query("age") < 15)
	                  tell_object(me,HIR "小小年纪就这么残忍？？\n" NOR);          
                  else
        	          tell_object(me,HIR "大欺侮小，羞羞羞!!!\n" NOR);
        }
	return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : pk <人物>
 
这个指令让你主动开始攻击一个玩家，并且尝试杀死对方，
这是一个进行你死我活的仇杀的指令，请不要随便使用。

其他相关指令: fight kill

有关 fight 跟 kill 的区分请看 'help combat'.
HELP
    );
    return 1;
}
 
