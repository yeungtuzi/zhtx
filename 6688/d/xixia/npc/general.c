inherit NPC;

void create()
{
	set_name("城门总管", ({ "general" }));
	set("age", 38);
	set("gender", "男性");
	set("long", "他虎背雄腰，双目如炬，立在城头，当真是威风凛凛。\n");
	set("attitude", "peaceful");

	set("str", 38);
	set("dex", 25);
	set("max_kee", 1400);
	set("combat_exp", 200000);
	set("shen_type", -1);

	set_temp("apply/attack", 50);
	set_temp("apply/damage", 50);

	set_skill("unarmed", 90);
	set_skill("dodge", 90);
	set_skill("move", 85);
	set_skill("parry", 100);
	set_skill("blade", 120);

	setup();

	carry_object(__DIR__"obj/blade")->wield();
	carry_object(__DIR__"obj/army_armor")->wear();
	carry_object(__DIR__"obj/redcoat")->wear();
	carry_object(__DIR__"obj/feather_shoe")->wear();
	carry_object(__DIR__"obj/red_hat")->wear();
}

/*int chat()
{
	string time;

	time = NATURE_D->game_time();
	if (strsrch(time, "子时") >= 0
	 || strsrch(time, "丑时") >= 0
	 || strsrch(time, "寅时") >= 0
	 || strsrch(time, "亥时") >= 0) {
		command("gate close");
		command("bridge up");
	}
	else {
		command("gate open");
		command("bridge down");
	}

	return 1;
}*/
