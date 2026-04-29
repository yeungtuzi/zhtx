#include <ansi.h>

inherit NPC;

void create()
{
	set_name(HIG"一品堂高手"NOR, ({ "yiping fighter", "fighter" }));
	set("age", 18+random(20));
	set("gender", "男性");
	set("long", "一品堂重金聘请的武林高手。\n");
	set("attitude", "aggressive");

	set("str", 48);
	set("dex", 25);
	set("wil", 30);

	set("max_kee", 1500);
	set("force", 1800);
	set("max_force", 1800);
	set("force_factor", 130);

	set("combat_exp", 1000000);
	set("bellicosity", 5200);
	set("shen_type", -1);

	set_skill("strike", 220);
	set_skill("dodge", 190);
	set_skill("pyrobat-steps", 120);
	set_skill("move", 85);
	set_skill("parry", 100);
	set_skill("celestrike", 220);
	set_skill("celestial", 190);
	set_skill("force", 90);

	map_skill("force", "celestial");
	map_skill("strike", "celestrike");
	map_skill("dodge", "pyrobat-steps"); 

	prepare_skill("strike", "celestrike");

	setup();

	carry_object("obj/cloth")->wear();
	add_money("gold", 5);
}

void die()
{
	object ob;

	if (objectp(ob = query_temp("last_damage_from")) 
	 && present(ob) && ob->query_temp("killing_ypfighter") >= 10) {	
		message_vision("$N杀出一条血路，冲出了将军府。\n", ob);
		ob->add("combat_exp", 300);
		ob->add("potential", 50);
		ob->move("/d/xixia/generalgate");
	}

	::die();
}
