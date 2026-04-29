//doomnpc

#include <ansi.h>

inherit NPC;
inherit "/ldg/std/rnd_equipd.c";

void create()
{
          set_temp("apply/astral_vision",1);
	setup();
}


void init()
{
	object ob;
	if( interactive(ob=this_player()) && !is_fighting() && !query("peaceful") )
	{
		if( (wiz_level(ob) || raw_wiz_level(ob)) && wiz_level(ob)<5 && raw_wiz_level(ob)<5 )
		{
			ob->move("/d/snow/inn");
			return;
		}
		remove_call_out("greeting");
		call_out("greeting",1,ob);
	}
}

void greeting(object ob)
{
	mapping ob_fam;

	if(!ob || environment(ob)!=environment()) return;
	if( !wiz_level(ob) && !query("peaceful") )
	{
		if( query("killer") )
			set_leader(ob);
		kill_ob(ob);
		ob->fight_ob(this_object());
	}
//        set("shen",-1*ob->query("shen")/10);
//武当现在靠这个搞正气太变态了，改了
        set("shen",-1*ob->query("shen")/100000);
	return;
}

int accept_fight(object ob)
{
    message_vision(RED"\n$N哼了一声：找死！\n"NOR,this_object());      
    kill_ob(ob);
    return 1;
}


// we have a better way to find which one is the best...
int sort_enemy(object ob1, object ob2)
{
        if (ob1->query("kee")>ob2->query("kee"))
                return 1;
        if (ob1->query("kee")==ob2->query("kee"))
        	return 0;
	return -1;
}

/*
int sort_enemy(object ob1, object ob2)
{
	if( !find_object("/cmds/usr/score") )
		load_object("/cmds/usr/score");
	if ("/cmds/usr/score"->get_dp(ob1,3) > "/cmds/usr/score"->get_dp(ob2,3))
		return 1;
	if ("/cmds/usr/score"->get_dp(ob1,3) == "/cmds/usr/score"->get_dp(ob2,3)) 
		return 0;
	return -1;
}
*/
int chat()
{
	object me;
	int fighting,hurt,force_fac,i;
	object *enemy,*victim;

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
	//挑选合适的打
	this_object()->clean_up_enemy();
	enemy = this_object()->query_enemy();
	victim = sort_array(enemy, (:sort_enemy:));
        if( sizeof(victim) &&  victim[0] )		
		this_object()->charge_ob(victim[0]);
	
		
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
	command("chat "+HIR"象"+victim->query("name")+"这种"+RANK_D->query_rude(victim)+"居然也妄图来此寻宝，当真是死有余辜！"NOR);
	add("cor",10);
	add("bellicosity",10000);
	add("combat_exp",100000);	
}

/*
void die()
{
	object killer;

	if( userp(killer = query("last_damage_from")) )
		command("chat "+killer->query("name")+"你们...你们...休要得意...主人...我主人...会找你...报仇...报仇...");
	::die();
} 
*/
