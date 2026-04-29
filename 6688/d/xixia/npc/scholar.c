inherit NPC;

void create()
{
	set_name("落魄书生", ({ "scholar" }));
	set("long", @LONG
一个在中原不得志的书生，跑到西夏来寻求发达之路。
LONG);
	set("attitude", "peaceful");
	set("per", 20+random(10));

	set("max_kee", 600);
	set("max_gin", 220);
	set("max_sen", 220);

	set("force", 800);
	set("max_force", 800);
	set("force_factor", 15);

	set("combat_exp", 80000);
	set("env/wimpy", 50);
	set("score", 3);

	set("chat_chance", 5);
	set("chat_msg", ({
		"落魄书生眼望远方，长叹了一口气。\n",
		(: random_move :),
	}));

	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_skill("sword", 60);
	set_skill("parry", 60);
	set_skill("literate", 150);
	set_skill("move", 60);
	set_skill("mysterrier", 60);
	set_skill("mystforce", 60);
	set_skill("mystsword", 60);
	set_skill("force", 60);

	map_skill("force", "mystforce");
	map_skill("sword", "mystsword");
	map_skill("parry", "mystsword");
	map_skill("dodge", "mysterrier");
	map_skill("move", "mysterrier");

	setup();

 	carry_object("obj/cloth")->wear();
	carry_object(__DIR__"obj/umbrella")->wield();

	add_money("silver", 50);
}
