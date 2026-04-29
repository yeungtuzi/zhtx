inherit NPC;

void create()
{
	set_name("巡逻士兵", ({ "guard" }));
	set("age", 22+random(20));
	set("gender", "男性");
	set("long", "他手持长枪，正四处巡逻。\n");
	set("attitude", "peaceful");

	set("str", 32);
	set("dex", 26);
	set("max_kee", 550);
	set("combat_exp", 50000);
	set("shen_type", -1);

	set_skill("unarmed", 40+random(20));
	set_skill("dodge", 30+random(20));
	set_skill("move", 45);
	set_skill("parry", 30+random(20));
	set_skill("spear", 40+random(20));
	set_skill("force", 30+random(20));

        set("chat_chance", 10);
	set("chat_msg", ({
		(: random_move :)
	}));
	setup();

	carry_object(__DIR__"obj/army_spear")->wield();
	carry_object(__DIR__"obj/army_armor")->wear();
	carry_object(__DIR__"obj/feather_shoe")->wear();
	carry_object(__DIR__"obj/army_head")->wear();
}
