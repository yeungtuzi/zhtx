inherit NPC;

void create()
{
	set_name("青年公子", ({ "youngman" }));
	set("long", @LONG
一位春风得意的青年公子。
LONG);
	set("attitude", "peaceful");
	set("per", 20+random(10));

	set("max_kee", 600);
	set("max_gin", 220);
	set("max_sen", 220);

	set("force", 800);
	set("max_force", 800);
	set("force_factor", 15);

	set("combat_exp", 50000);
	set("score", 3);

	set_skill("unarmed", 100);
	set_skill("dodge", 60);
	set_skill("sword", 60);
	set_skill("parry", 60);
	set_skill("move", 60);
	set_skill("force", 60);


	setup();

 	carry_object("obj/cloth")->wear();
	add_money("silver", 50);
}
