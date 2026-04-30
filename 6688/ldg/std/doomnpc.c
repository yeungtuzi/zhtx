//doomnpc

#include <ansi.h>

inherit NPC;
inherit "/ldg/std/rnd_equipd.c";

void create()
{
        setup();
}


void init()
{
	object ob;
	if(random(10)>4) set_skill("perception",50+random(100));
	
	if( interactive(ob=this_player()) && !is_fighting() && !query("peaceful") )
	{
		remove_call_out("greeting");
		call_out("greeting",1,ob);
	}
}

void greeting(object ob)
{
	// 2026-04-30: unused variable commented out
	// mapping ob_fam;

	if(!ob || environment(ob)!=environment()) return;
	if( !wiz_level(ob) && !query("peaceful") )
	{
		if( query("killer") )
			set_leader(ob);
		kill_ob(ob);
		ob->fight_ob(this_object());
	}
	return;
}

int accept_fight(object ob)
{
    message_vision(RED"\n$N哼了一声：找死！\n"NOR,this_object());      
    kill_ob(ob);
    return 1;
}


int chat()
{
	object me;
	int fighting,hurt,force_fac;

	me = this_object();
	if( !environment(me) ) return 0;
	fighting = me->is_fighting();

	//消除自己的busy
	if( random(4) > 2 && is_busy() )
		interrupt_me(this_object(),"death");
	//自动疗伤
	if( query("auto_heal") && query("eff_kee")<query("max_kee")*70/100)	
	{
		force_fac = query("force_factor");
		if(fighting) command("halt");
		hurt = query("max_kee")-query("eff_kee");
		hurt /= 100;
		while( hurt-- )
			command("exert heal");
		set("force_factor",force_fac);
	}	  
	//自动解毒
	if( query("auto_unpoison") && (query_condition("tm_poison") || query_condition("rose_poison") || query_condition("snake_poison")) )
	{
		command("halt");
		command("exert unpoison");
	}                            
	if(query("sen")<(query("eff_sen")*70/100))
		command("exert refresh");
	if(query("kee")<(query("eff_kee")*70/100))
		command("exert recover");
	if(query("gin")<(query("eff_gin")*70/100))
		command("exert regenerate");
	::chat();
}

void killed_enemy(object victim)
{
	command("chat "+HIR"象"+victim->query("name")+"这种"+RANK_D->query_rude(victim)+"居然也来挑衅，当真是死有余辜！"NOR);
	add("cor",10);
	add("bellicosity",1000);
	add("combat_exp",100000);	
}
