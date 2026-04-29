//agressive npc

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
	add_action("do_ride","ride");
	
	
	if( interactive(ob=this_player()) && !is_fighting() && !query("peaceful") )
	{
		remove_call_out("greeting");
		call_out("greeting",1,ob);
	}
}

void greeting(object ob)
{
	object room1;
	room1 = environment(me);

	if (room1->query("no_fight"))
		room1->set("no_fight", 0);

	if (ob->query_temp("given_treasure"))
		return;

	if (interactive(ob))
	{
		if ( random(100) > 50 ) command("heihei");
		else command("heng");
		command("say 你这家伙见了"+RANK_D->query_self_rude(me)+"我，还不赶快把身上的珍珠宝石月光宝盒啊什么的，统统交出来！\n");
		me->set_leader(ob);
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob); 
	}       

}


int accept_fight(object ob)
{
    message_vision(RED"\n$N哼了一声：找死！\n"NOR,this_object());      
    kill_ob(ob);
    return 1;
}


void killed_enemy(object victim)
{
	command("chat "+HIR"象"+victim->query("name")+"这种"+RANK_D->query_rude(victim)+"竟敢不乖乖留下宝贝秘笈，"+RANK_D->query_self_rude(me)+"管杀不管埋!"NOR);
	add("bellicosity",3000);
}


int do_ride(string arg)
{
	ob=this_player();

	if (ob->query_temp("given_treasure"))
	return 0;

	if(!arg)
		return notify_fail("正打着架，你还想乱骑什么？\n");
	if(!(present(arg,environment(ob))))
		return notify_fail("正打着架，你还想乱骑什么？\n");
	write(me->query("name")+"大叫一声，竟敢坐飞机逃跑！你给我下来吧！\n");
	write(me->query("name")+"一把把"+ ob->query("name") +"给揪了下来\n");
	return 1;

}

int accept_object(object ob, object treasure)
{
	if (treasure->query("id")=="long dan" || treasure->query("id")=="jinxian lian" || treasure->query("id")=="feng zhi yu" || treasure->query("id")=="tiepi shihu" || treasure->query("id")=="yiyuan xianlu" || treasure->query("id")=="lingshan yuye" || treasure->query("id")=="shennong zhi cao")
	{
		ob->set_temp("given_treasure",1);
        ob->start_call_out( (: call_other, __FILE__, "remove_effect", ob :), 600);

		ob->remove_all_killer();
		me->set_leader(0);
		command("pat "+ob->query("id"));
		command("goodkid "+ob->query("id"));
		command("say " +CYN"不错不错，你这娃娃很懂得孝敬，"+RANK_D->query_self_rude(me)+"不会亏待了你。饶了你啦！\n");
		destruct(treasure);
		return 1;
	}
	else
	{
		command("say "+HIR"你这个家伙，拿些垃圾货色来，想充数吗！！！你惹怒了"+RANK_D->query_self_rude(me)+"，没你的好果子吃！\n");
		add("bellicosity",3000);
		add("combat_exp",100000);
		me->kill_ob(ob);
		me->set_leader(ob);
		ob->fight_ob(me);
	}
}

void remove_effect(object ob)
{
	ob->delete_temp("given_treasure");
}
