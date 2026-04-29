//葵花宫护法

#include <ansi.h>

inherit "/u/z/zephyr/sunflower/npc/advance_npc";

object me = this_object();
object ob = this_player();
void create()
{
        setup();
}


void init()
{
	if( interactive(ob=this_player()) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting",1,ob);
	}
}

void greeting(object ob)
{

	if (interactive(ob) && !present("sunflower ling", ob) && !present("bingqi pu", ob))
	{
		command("say 主人说了，葵花圣宫，外人不得乱闯。得罪了！\n");
		me->set_leader(ob);
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob); 
	}  
	else if (interactive(ob) && present("sunflower ling", ob))
	{
		if ( query("gender")=="男性" ) command("bow");
		else command("fu");
		command("say 上宾请，主人恭候多时了");
		set_leader(0);
	}
}


int accept_fight(object ob)
{
	if ( present("sunflower ling", ob) || present("bingqi pu", ob) )
	{
		command("say 上宾请别开玩笑了，主人有命，让我等不可对上宾无礼。");
		return 0;
	}
    message_vision(RED"\n$N哼了一声：找死！\n"NOR,this_object());      
    kill_ob(ob);
    return 1;
}


void killed_enemy(object victim)
{
	command("chat "+HIR""+victim->query("name")+"竟敢擅闯葵花圣宫，自寻死路，须怪不得我！"NOR);
}
