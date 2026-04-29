inherit NPC;

void create()
{
	set_name("钱庄老板", ({ "boss" }));
	set("long", @LONG
他三绺长须，一副精明干练的样子。
LONG);
	set("gender", "男性");
	set("age", 32);
	set("shen_type",-1);
	set("attitude", "peaceful");

	set("per", 20+random(10));

	set("max_kee", 700);
	set("max_gin", 220);
	set("max_sen", 220);
	set("force", 400);
	set("max_force", 400);
	set("force_factor", 1);

	set("combat_exp", 100000);
	set("score", 3);
	set_skill("force", 30);
	set_skill("unarmed", 120);
	set_skill("dodge", 120);
	set_skill("parry", 130);

	setup();
 	carry_object("obj/cloth")->wear();
}

void init()
{
	object ob;

	::init();

	if (interactive(ob = this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
}
