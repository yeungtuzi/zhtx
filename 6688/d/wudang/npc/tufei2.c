// tufei2.c

inherit NPC;

void create()
{
	set_name("土匪", ({ "tufei","bandit","fei" }) );
	set("gender", "男性");
	set("age", 20);
	set("long",
		"这家伙满脸横肉��一付凶神恶煞的模样，令人望而生畏。\n");
	set("combat_exp", 5000);
        set("shen_type", -1);
	set("attitude", "aggressive");

	set("apply/attack", 10);
	set("apply/defense", 10);

//	set("chat_chance", 30);
//	set("chat_msg", ({
//		"土匪一声大喊: 此山是我开，此树是我栽，若要从此过，留下买路财 !\n",
//	}) );

	set_skill("unarmed", 25);
	set_skill("parry", 20);
	set_skill("dodge", 20);

	setup();
        carry_object("/obj/cloth")->wear();
	add_money("silver", 10);
}
