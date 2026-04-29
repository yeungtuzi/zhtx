// kill.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object obj;
	string *pk_id, callname;

	if( environment(me)->query("no_fight") 
	    || environment(me)->query("sleep_room"))
		return notify_fail("这里不准战斗。\n");

	if( !arg )
		return notify_fail("你想杀谁？\n");

	if(!objectp(obj = present(arg, environment(me))))
		return notify_fail("这里没有这个人。\n");

	if( !obj->is_character() || obj->is_corpse() )
		return notify_fail("看清楚一点，那并不是活物。\n");

	if(obj==me)
		return notify_fail("用 suicide 指令会比较快:P。\n");

	if(userp(obj))
		return notify_fail("对不起，不允许对玩家使用这个指令。\n");
		
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

	if( !userp(obj) ) {
                me->kill_ob(obj);
		obj->accept_kill(me);
		obj->kill_ob(me);
	} else {
//		if(obj->query_temp("pk_id") 
//			&& member_array(me->query("id"),obj->query_temp("pk_id"))!=-1 )
//		{
//			me->kill_ob(obj);
//			obj->fight_ob(me);
//			tell_object(me,HIW"你开始反击"+obj->name()+"。\n"NOR);
//		}
		if((int)me->query("age") >= 15 && ( me->query("combat_exp")/(obj->query("combat_exp")+1) < 3) ){
                    me->kill_ob(obj);
		    obj->fight_ob(me);
//		    if(!me->query_temp("pk_id") 
//			|| member_array(obj->query("id"),me->query_temp("pk_id"))==-1 )
//			       me->add_temp("pk_id",({obj->query("id")}) );
//                    obj->set_temp("killed",1);
//                    obj->set("pker_id",me->query("id"));
//                    if( (int)obj->query("age") >= 15 )
//		      tell_object(me,HIW"你开始主动pk"+obj->name()+"。\n"NOR);
		      tell_object(obj, HIR "如果你要和" + me->name() 
			+ "性命相搏，请你也对这个人下一次 kill 指令。\n" NOR);
                 }
                 else {
                  if((int)me->query("age") < 15)
                   tell_object(me,HIR "小小年纪就这么残忍？？\n" NOR);          
                  else
                    tell_object(me,HIR "大欺侮小，羞羞羞!!!\n" NOR);
                  }
	}

	return 1;
}
int help(object me)
{
  write(@HELP
指令格式 : kill <人物>
 
这个指令让你主动开始攻击一个人物，并且□试杀死对方，kill 和 fight 最大的
不同在於双方将会真刀实枪地打斗，也就是说，会真的受伤。由於 kill 只需单方
面一厢情愿就可以成立，因此你对任何人使用 kill 指令都会开始战斗，通常如果
对方是 NPC 的话，他们也会同样对你使用 kill。

当有人对你使用 kill 指令时会出现红色的字样警告你，对於一个玩家而言，如果
你没有对一名敌人使用过 kill 指令，就不会将对方真的打伤或杀死( 使用法术除
外)。

其他相关指令: fight

有关 fight 跟 kill 的区分请看 'help combat'.
HELP
    );
    return 1;
}
 
