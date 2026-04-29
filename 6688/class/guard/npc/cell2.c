//poisoner.c
//based on sungoku.c and logind.c
//modified by tlang for hospital

#include <ansi.h>

inherit NPC;
inherit F_SAVE;

string query_save_file()
{
	return __DIR__"data/poisoner";
}

string *start_loc = ({
        "/d/snow/inn",
        "/d/guanwai/inn",
        "/d/cloud/tearoom",
        "/d/jingcheng/jiuguan",
        "/d/yueyang/kedian",
	"/d/suzhou/kezhan",
});

void create()
{
	set_name( "流行病毒", ({ "poisoner", "liuxing bingdu", "bingdu" }) );
	if( !restore() ) {
		set("short", HIC "可怕的流行病毒" NOR "(poisoner)");
		set("long","可怕的病毒，会传染的喔。好怕怕呀！\n");
			
		set("race", "人类");
		set("max_kee",300);
		set("combat_exp",0);
		set("chat_chance", 15);
		set("chat_msg", ({
			(: this_object(), "random_move" :),
			CYN "我们是病毒！我们是病毒！\n" NOR,
			CYN "嘿嘿！！！\n" NOR,
		}) );
		set("chat_msg_combat", ({
			CYN "\n病毒扮个鬼脸，说道：来呀！再来呀！\n" NOR,
			CYN "\n病毒说道：这一招是我自己悟出来的，厉害吧！\n" NOR,
		}) );

// We have 5 pills per reset.
		set("pills", 5);

		set("perm_apply", ([
			"attack":	10,
			"dodge":	10,
			"damage":	5,
		]) );

		set("age", 14);
		set("str", 25);
		set("con", 25);
		set("per", 10);
		
		
		set_skill("unarmed", 1);
		set_skill("dodge", 1);
		set_skill("force", 1);
		set_skill("parry", 1);
	}

	set_temp("apply", query("perm_apply"));
	setup();
	carry_object("/d/suzhou/npc/obj/cloth")->wear();

//This line is for testing.	
	call_out("go_around",5);
}

//This is for restore data.
void reset()
{
	int learn;

	set("pills", 5);

	if( (int)query("potential") > (int)query("learned_points") ) {
		learn = (int)query("potential") - (int)query("learned_points");
		add_temp("apply/attack", learn / 3);
		add_temp("apply/dodge", learn / 3);
		add_temp("apply/damage", learn / 3);
		add("learned_points", (learn / 3) * 3);
		call_out("go_around",1);
	}
	save();
}

//This is for hurting people.
void init(object ob)
{
	::init();
 	if( interactive(ob = this_player()) && !is_fighting() ) {
	remove_call_out("greeting");
	call_out("greeting",1,ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	command("smile");
	call_out("do_poison",1,ob);	
}

int do_poison(object ob,object me)
{
}

int accept_fight(object who)
{
	if( is_fighting() ) {
		if( random(query("eff_kee")) > (int)query("kee") ) {
			command("waggle");
			return 0;
		} else {
			command("heng");
			return 1;
		}
	}
	command("nod");
	return 1;
}

int receive_damage(string type, int pts)
{
	int damage;

	damage = ::receive_damage(type, pts);
	if( (type=="kee") && (damage > (int)query("max_kee") / 6) ) {
		command("heng");
		if( random(query("kee")) < damage)
			random_move();
	}

	if( (int)query("pills")
	&&	(((int)query("kee")) < 100 
		|| ((int)query("gin") < 30) 
		|| ((int)query("sen") < 30) )) {
		say( HIY "流行病毒摇晃了几下，突然精神大振。\n" NOR);
		set("gin", query("eff_gin"));
		set("kee", query("eff_kee"));
		set("sen", query("eff_sen"));
		add("pills", -1);
                save();
	}
	return damage;
}

varargs void improve_skill(string skill, int amount, int raw)
{
// Thus we can gain skill levels from direct fighting.
	::improve_skill(skill, amount);
}

void revive()
{
// This is a feature of poisoner's race. 
	add("combat_exp", (int)query("combat_exp") / 3 + 10);
	reset();
	::revive();
}

void kill_ob(object ob)
{
	command("hehe");
	fight_ob(ob);
}

void defeated_enemy(object ob)
{
	command("nomatch");
	remove_killer(ob);
}

//added for go around the mud.
int go_around()
{
	
	object *ob,me;
        int i;
	string room;

	me=this_object();
	ob=users();
	command("?");
	for(i=0; i<sizeof(ob); i++) {
	if( !ob[i] || environment(ob[i]) != environment() ) continue;
	command("hi");
	room = start_loc[random(sizeof(start_loc))];
	command("grin");
	me->move(room);
	}
	command("hehe");
}

