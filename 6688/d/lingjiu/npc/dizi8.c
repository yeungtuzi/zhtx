inherit NPC;

void create()
{  

	set_name("灵鹫宫鸾天部弟子", ({"lingjiu dizi", "dizi"}) );
	set("gender", "女性");
	set("age", 20+random(30));
	set("long", @LONG
灵鹫宫弟子。
LONG);
	set("attitude", "friendly");

        set("atman", 200);
        set("max_atman", 200);
        set("force", 800);
        set("max_force",800);
	set("force_factor",10);

        set("mana", 200);
        set("max_mana", 200);

        set("combat_exp", 20000+random(100000));
	set("shen_type", -1);

        set_skill("sword", 40+random(40));
        set_skill("unarmed", 40+random(40));
	set_skill("hook", 40+random(40));
	set_skill("throwing", 40+random(40));
	set_skill("blade", 40+random(40));
	set_skill("dagger", 40+random(40));
	set_skill("whip", 40+random(40));
        set_skill("force", 40+random(40));
        set_skill("dodge", 40+random(40));
        set_skill("literate", 40+random(40));
        set_skill("parry", 40+random(40));


	set_temp("apply/armor",30);

	setup();

       	carry_object(__DIR__"obj/weapon"+random(6))->wield();
	carry_object(__DIR__"obj/cape")->wear();
	carry_object(__DIR__"obj/cloak")->wear();
}
