//NPC zhujian.c
//by lzxx

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("菊剑", ({ "ju jian", "ju"}));
	set("long",
	    "她是天山童姥的贴身四婢之一，只见她长得瓜子脸蛋，\n"+
	    "眸如点漆, 容貌姣好，\n"+
	    "叫人一见之下，顿生好感。\n");
	set("gender", "女性");
	set("age", 18);
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

	set("combat_exp", 250000);
	set("score", 10000);
	set_skill("force", 100);
	set_skill("hand", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("sword",100);

	set_skill("zhemei-shou",100);
	set_skill("bahuang-gong", 100);

	map_skill("force", "bahuang-gong");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "zhemei-shou");

	prepare_skill("hand", "zhemei-shou");

	create_family("灵鹫宫",3,"弟子");
	setup();
 	carry_object(__DIR__"obj/ju_cloth")->wear();
	carry_object(__DIR__"obj/clasp")->wear();
	carry_object(__DIR__"obj/girlsword")->wield();
        add_money("silver",30);
}

void attempt_apprentice(object ob)
{
	if( ob->query("gender") != "女性" ){
		command("say 我只收女弟子。");
		return;
	}
	command("say 好吧，我就收下你吧！");
	command("recruit "+ob->query("id"));
}
