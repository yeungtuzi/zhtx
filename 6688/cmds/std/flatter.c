// flatter.c
// by yeung

#include "/doc/help.h"
#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int fp,dp,level;
	string msg;
	object enemy;
	
	if( !arg || !objectp(enemy = present(arg,environment(me))) || !enemy->is_character() || !living(enemy) )
	{
		return notify_fail("你要向谁歌功颂德？\n");
	}

	level = me->query_skill("flattering",1);
	
	if( !level )
		return notify_fail("你不懂拍马溜须的要诀，还是赶快去学吧。\n");

        if( !me->is_fighting(enemy) ) {
                return notify_fail(enemy->query("name")+"现在没有在打你啊。\n");
        }

        if(!me->is_busy()) {
		fp = level/2 + me->query_per() + me->query_elo();
		if( enemy )
			dp = (enemy->query_cps())*2 + enemy->query_wil()*2;
		else 
			dp = 1;

		msg = "\n$N突然掏出随身行头，吹奏起来，倒也悠扬动听。\n";
		msg += "众人一呆之际，$N大声唱道：\n";
		if( enemy->query("gender") == "女性" )
		{
			msg += ("\t"YEL + enemy->query("name")+RANK_D->query_respect(enemy)+",\t绝代佳人\n"NOR);
			msg += (GRN + "\t貌赛西施，\t颜胜昭君\n"NOR);
		}		
		else
		{
			msg += ("\t"YEL + enemy->query("name")+RANK_D->query_respect(enemy)+",\t德配天地\n"NOR);
			msg += (GRN + "\t威震寰宇，\t古今无比\n"NOR);
		}
                                                                        
		me->receive_damage("sen",20);                                                                      
		me->start_busy(1);
		message_vision(msg, me);

		if( random(fp+dp) >= dp)
	        {
//		        me->remove_all_killer();
			enemy->remove_all_enemy();
			message_vision("$N一怔之下，接着哈哈大笑：说得好，这次就放你一马！\n",enemy);
			me->improve_skill("flattering",me->query_elo()/5);
			message_vision("$N一看，时机来了，嘿嘿。\n",me);
			COMBAT_D->do_attack(me,enemy,me->query_temp("weapon"),TYPE_QUICK);			
			return 1;
		}
		else
		{
			message_vision("$N哼了一声：无耻！\n",enemy);
			COMBAT_D->fight(enemy,me);			
			return 1;
		}	
        } else return notify_fail("你正忙着呢！\n");
        return 1;
}

int help(object me)
{
   write(@HELP
指令格式: flatter 某人
HELP
   );
   return 1;
}
