// shihou.c 狮吼子

inherit NPC;

string ask_me();

void create()
{
	set_name("狮吼子", ({ "shihou zi", "shihou" }));
	set("title", "星宿派二师兄");
	set("long", 
		"他就是丁春秋的二弟子狮吼子。\n"
		"他三十多岁，狮鼻阔口，耳挂铜环，一望而知不是中土人士。\n");
	set("gender", "男性");
	set("age", 32);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 28);
	set("int", 20);
	set("con", 26);
	
	set("max_kee", 500);
	set("max_gin", 500);
	set("force", 1000);
	set("max_force", 1000);
	set("force_factor", 20);

	set("combat_exp", 200000);
	set("score", 30000);

	set_skill("force", 80);
	set_skill("huagong-dafa", 70);
	set_skill("dodge", 40);
	set_skill("strike", 70);
	set_skill("xingxiu-duzhang", 40);
	set_skill("parry", 60);
	set_skill("literate", 50);
	set_skill("dugong", 60);
	set_skill("fushi-dugong", 70);

	map_skill("force", "huagong-dafa");
	map_skill("strike", "xingxiu-duzhang");
  	map_skill("parry", "xingxiu-duzhang");

	prepare_skill("strike", "xingxiu-duzhang");

	create_family("星宿派", 2, "弟子");

	setup();
	carry_object(__DIR__"obj/y_cloth")->wear();
}
