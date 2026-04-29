// tianlang.c 天狼子

inherit NPC;

void create()
{
	set_name("天狼子", ({ "tianlang zi", "tianlang" }));
	set("title", "星宿派三师兄");
	set("long", 
		"他就是丁春秋的三弟子天狼子。\n");
	set("gender", "男性");
	set("age", 30);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 27);
	set("int", 16);
	set("con", 25);
	
	set("max_kee", 400);
	set("force", 1000);
	set("max_force", 1000);
	set("force_factor", 15);
	set("combat_exp", 150000);
	set("score", 30000);

	set_skill("force", 70);
	set_skill("huagong-dafa", 65);
	set_skill("dodge", 50);
	set_skill("strike", 80);
	set_skill("xingxiu-duzhang", 70);
	set_skill("parry", 40);

	map_skill("force", "huagong-dafa");
	map_skill("strike", "xingxiu-duzhang");
  	map_skill("parry", "xingxiu-duzhang");

	prepare_skill("strike", "xingxiu-duzhang");
	create_family("星宿派", 2, "弟子");

	setup();
	carry_object("/obj/cloth")->wear();
}
