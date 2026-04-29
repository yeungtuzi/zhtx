#include <ansi.h>

inherit NPC;

void create()
{
	set_name("包不同", ({"bao bu tong", "bao"}));
	set("title", "慕容世家四大家将");
	set("gender", "男性");
	set("age", 41);
	set("rank_info/respect", "包先生");
	set("long", @LONG
慕容世家四大家将之一，此人最爱捣乱。
LONG);
	set("attitude", "peaceful");
	
	set("int", 30);
	set("dex", 35);
	set("per", 20);

	set("chat_chance", 5);
	set("chat_msg", ({
		"包不同：“非也，非也！”\n",
	}));

	set("max_kee", 1700);
	set("max_gin", 400);
	set("max_sen", 400);
	set("force", 1500);
	set("max_force", 1500);
	set("force_factor", 50);
	
	set("combat_exp", 400000);

	set_temp("apply/armor", 30);
	
	set_skill("force", 100); 
	set_skill("hunyuan-yiqi", 100); 
	set_skill("dodge", 120); 
	set_skill("unarmed", 220);
	set_skill("move", 120); 
	set_skill("fall-steps", 110); 
	set_skill("parry", 120); 
	set_skill("blade", 110); 
	set_skill("cibei-dao", 110); 
	
	map_skill("force", "hunyuan-yiqi");
	map_skill("blade", "cibei-dao");
	map_skill("parry", "cibei-dao");
	map_skill("dodge", "fall-steps");

	setup();
	
	carry_object("/obj/cloth")->wear();
	carry_object(__DIR__"obj/blade")->wield();
	add_money("gold", 1);
}
