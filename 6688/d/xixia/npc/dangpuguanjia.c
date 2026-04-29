inherit NPC;

void create()
{
	set_name("当铺管家", ({ "assistant" }));
	set("long", @LONG
他虽相貌不俗，可是嘴角总是带着一股奸笑。
LONG);
	set("gender", "男性");
	set("age", 32);
	set("shen_type",-1);
	set("attitude", "peaceful");

	set("per", 20+random(10));

	set("max_kee", 500);
	set("max_gin", 220);
	set("max_sen", 220);
	set("force", 10);
	set("max_force", 10);
	set("force_factor", 0);

	set("combat_exp", 40000);
	set("score", 3);
	set_skill("force", 10);
	set_skill("unarmed", 50);
	set_skill("dodge", 40);
	set_skill("parry", 30);
	set_skill("sword",10);

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
	command("heihei " + ob->query("id"));
}
