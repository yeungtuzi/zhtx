//出尘子

inherit NPC;

void create()
{
	set_name("出尘子", ({ "chuchen zi", "chuchen" }));
	set("title", "星宿派八师兄");
	set("long", 
		"他就是丁春秋的八弟子出尘子。\n"
		"他身材矮胖，可手中握的钢杖又长又重。\n");
	set("gender", "男性");
	set("age", 25);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 33);
	set("int", 15);
	set("con", 28);
	
	set("max_kee", 300);
	set("force", 800);
	set("max_force", 800);
	set("force_factor", 15);
	set("combat_exp", 100000);
	set("score", 20000);

	set_skill("force", 60);
	set_skill("huagong-dafa", 40);
	set_skill("dodge", 60);
	set_skill("strike", 50);
	set_skill("xingxiu-duzhang", 20);
	set_skill("parry", 50);
	set_skill("staff", 80);
	set_skill("dugong", 40);
	set_skill("fushi-dugong", 40);


	map_skill("force", "huagong-dafa");
	map_skill("strike", "xingxiu-duzhang");
  	map_skill("parry", "xingxiu-duzhang");
	map_skill("dugong", "fushi-dugong");

	prepare_skill("strike", "xingxiu-duzhang");

	create_family("星宿派", 2, "弟子");

	setup();
  	carry_object(__DIR__"obj/gangzhang")->wield();
	carry_object("obj/cloth")->wear();
}
