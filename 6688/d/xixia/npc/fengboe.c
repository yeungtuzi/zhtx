#include <ansi.h>

inherit NPC;

void create()
{
	set_name("风波恶", ({"feng boe", "feng"}));
	set("title", "慕容世家四大家将");
	set("nickname", "一阵风");
	set("gender", "男性");
	set("age", 39);
	set("long", @LONG
慕容世家四大家将之一，此人最爱打架。
LONG);
	set("attitude", "heroism");
	
	set("per", 20);
	set("cor", 35);
	set("wil", 30);

	set("max_kee", 1600);
	set("max_gin", 400);
	set("max_sen", 400);
	set("force", 1500);
	set("max_force", 1500);
	set("force_factor", 40);
	
	set("combat_exp", 380000);

	set_temp("apply/armor", 30);
	
	set_skill("force", 100); 
	set_skill("qidaoforce", 100); 
	set_skill("dodge", 120); 
	set_skill("strike", 120);
	set_skill("move", 120); 
	set_skill("fall-steps", 110); 
	set_skill("parry", 120); 
	set_skill("blade", 110); 
	set_skill("shortsong-blade", 110); 
	set_skill("meihua-shou", 110);
	
	map_skill("force", "qidaoforce");
	map_skill("blade", "shortsong-blade");
	map_skill("parry", "shortsong-blade");
	map_skill("dodge", "fall-steps");
	map_skill("strike", "meihua-shou");

	prepare_skill("strike", "meihua-shou");

	setup();
	
	carry_object("/obj/cloth")->wear();
	carry_object(__DIR__"obj/blade")->wield();
	add_money("gold", 1);
}

void init()
{
	object ob = this_player();

	::init();
	if (interactive(ob) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 3, ob);
	}
}

void greeting(object ob)
{
	if (!ob || environment(ob) != environment()) return;
	command("fight " + ob->query("id"));
}

int accept_fight(object who)
{
	return 1;
}
