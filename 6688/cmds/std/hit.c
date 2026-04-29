// fight.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object obj, old_target;

	if( environment(me)->query("no_fight") ||
	    environment(me)->query("sleep_room") )
		return notify_fail("这里禁止战斗。\n");

	if(!arg || !objectp(obj = present(arg, environment(me))))
		return notify_fail("你想攻击谁？\n");

	if( !obj->is_character() )
		return notify_fail("看清楚一点，那并不是生物。\n");

	if(userp(obj))
		return notify_fail("对不起，不允许对玩家使用这个指令。\n");

	if (obj->query("bihua"))
		return notify_fail(obj->query("name") + "正在比武，你不能帮忙。\n");
	if ( ((int)obj->query("kee")*100 /(1+(int)obj->query("max_kee")) <= 50 ) ) 
		{
		return notify_fail(obj->query("name")+"已经快不行了，你还是直接杀了他来得快。\n");
		}

	if( obj->is_fighting(me) )
		return notify_fail("加油！加油！加油！\n");

	if( me->query_temp("hitting") )
		return notify_fail("加油！加油！加油！\n");
	if( !living(obj) )
		return notify_fail(obj->name() + "已经这样了你还要打，过分了点吧？\n"); 

	if(obj==me)	return notify_fail("打自己？别这么想不开。\n");

	if( userp(obj) ) {
                if( me->query("combat_exp")/(obj->query("combat_exp")+1) < 3 ){
		  message_vision("\n$N对著$n大喝一声：看招！\n\n", me, obj);
		  me->set_temp("hitting");
		  remove_call_out("do_hit");
		  call_out("do_hit", 1, me, obj);
		  return 1; 
                 }
                 else{
                   tell_object(me,HIR "大欺侮小，羞羞羞!!!\n" NOR);
                   return 1;
                 }
	}

	if( obj->query("can_speak") || (obj->query("attitude")!="aggressive")){
		message_vision("\n$N对著$n大喝一声：看招！\n\n", me, obj);
		message_vision("\n$n对$N怒喝道：你这"+RANK_D->query_rude(me)+"竟敢偷袭"+RANK_D->query_self_rude(obj)+"！\n",me,obj);
		me->fight_ob(obj);
		obj->kill_ob(me);
	} else {
		message_vision("\n$N大喝一声，开始对$n发动攻击！\n\n", me, obj);
		me->fight_ob(obj);
		obj->kill_ob(me);
	}

	return 1;
}

void do_hit(object me, object obj)
{
	if(objectp(present(obj, environment(me)))) {
		COMBAT_D->do_attack(me, obj, me->query_temp("weapon") );
		COMBAT_D->do_attack(obj, me, obj->query_temp("weapon") );
	}
	me->delete_temp("hitting");
	return;
}

int help(object me)
{
  write(@HELP
指令格式 : hit <人物>
 
这个指令让你向一个人物「讨教」或者是「切磋武艺」，这种形式的战斗纯粹是
点到为止，因此只会消耗体力，不会真的受伤，但是并不是所有的  NPC 都喜欢
打架，把他惹急了也许会杀了你的!
 
其他相关指令: kill fight

PS. 如果对方不愿意接受你的挑战，你仍然可以迳行用 kill 指令开始战斗，有
    关 fight 跟 kill 的区分请看 'help combat'.
HELP
    );
    return 1;
}
 
