// wujiang.c 武将

inherit NPC;


void create()
{
	set_name("武将", ({ "wu jiang", "wu", "jiang" }));
	set("gender", "男性");
	set("age", random(20) + 30);
	set("str", 25);
	set("dex", 16);
	set("long", "他站在那里，的确有说不出的威风。\n");
	set("combat_exp", 750000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 100);
	set_skill("force", 100);
	set_skill("sword", 100+random(350));
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 30);

	set("force", 1400); 
	set("max_force", 1000);
	set("force_factor", 80);

	setup();
	carry_object(__DIR__"obj/gangjian")->wield();
	carry_object(__DIR__"obj/tiejia")->wear();
}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) && 
		(int)ob->query_condition("killer")) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
}
