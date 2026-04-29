//by lzxx

inherit NPC;

void create()
{
	set_name("石嫂", ({ "shi sao", "shi"}));
	set("long",
		"她是灵鹫宫朱天部的首领，三十开外的年纪，大家都叫她石嫂。\n");
	set("gender", "女性");
	set("age", 37);
	set("title", "灵鹫宫朱天部首领");
	set("shen_type",1);
	set("attitude", "peaceful");

	set("str", 25);
	set("int", 25);
	set("per", 30);
	set("con", 25);

	set("kee", 800);
	set("max_kee", 800);
	set("gin", 500);
	set("sen", 500);
	set("max_gin", 500);
	set("max_sen", 500);
	set("force", 1200);
	set("max_force", 1200);
	set("force_factor", 20);

	set("combat_exp", 300000);
	set("score", 10000);
	set_skill("force", 100);
	set_skill("hand", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("blade",250);

	set_skill("zhemei-shou",100);
	set_skill("bahuang-gong", 100);

	map_skill("force", "bahuang-gong");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "zhemei-shou");

	prepare_skill("hand", "zhemei-shou");

	create_family("灵鹫宫",3,"弟子");
	setup();
	carry_object(__DIR__"obj/liu_blade")->wield();
	carry_object(__DIR__"obj/cape")->wear();
	carry_object(__DIR__"obj/cloak")->wear();
        add_money("silver",30);
}
