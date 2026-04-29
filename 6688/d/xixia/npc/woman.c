inherit NPC;

void create()
{
	set_name("贵妇人", ({ "lady" }));
	set("long", @LONG
LONG);
	set("gender", "女性");
	set("age", 42);
	set("shen_type",1);
	set("attitude", "peaceful");

	set("per", 20+random(10));

	set("max_kee", 300);
	set("max_gin", 220);
	set("wimpy", 50);
	set("max_sen", 220);
	set("force", 10);
	set("max_force", 10);
	set("force_factor", 0);

	set("combat_exp", 1000);
	set("score", 3);

	set("chat_chance", 5);
	set("chat_msg", ({
		"贵妇人说道：“再看一看。。。”\n",
		(: random_move :),
	}));

	set_skill("force", 10);
	set_skill("unarmed", 30);
	set_skill("dodge", 20);
	set_skill("parry", 30);

	setup();
 	carry_object("obj/cloth")->wear();
	add_money("gold", 1);
}
