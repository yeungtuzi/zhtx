inherit NPC;

void create()
{
	set_name("城门守卫", ({ "guard" }));
	set("age", 22+random(20));
	set("gender", "男性");
	set("long", "他手持长枪，正立在城门一侧站岗。\n");
	set("attitude", "peaceful");

	set("str", 28);
	set("dex", 16);
	set("max_kee", 550);
	set("combat_exp", 30000);
	set("shen_type", -1);

	set_skill("unarmed", 30+random(20));
	set_skill("dodge", 20+random(20));
	set_skill("move", 35);
	set_skill("parry", 20+random(20));
	set_skill("spear", 30+random(20));
	set_skill("force", 40+random(20));

        set("chat_chance", 2);
	set("chat_msg", ({
		"城门守卫冲着你厉声喝道：抬起头来！\n",
	}));
	setup();

	carry_object(__DIR__"obj/army_spear")->wield();
	carry_object(__DIR__"obj/army_armor")->wear();
	carry_object(__DIR__"obj/army_head")->wear();
}
