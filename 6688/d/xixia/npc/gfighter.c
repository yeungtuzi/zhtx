#include <ansi.h>

inherit NPC;

void create()
{
	set_name(HIR"一品堂高手"NOR, ({ "yiping fighter", "fighter" }));
	set("age", 18+random(20));
	set("gender", "男性");
	set("long", "一品堂重金聘请的武林高手。\n");

	set("str", 38);
	set("dex", 25);
	set("wil", 30);

	set("max_kee", 900);
	set("force", 800);
	set("max_force", 800);
	set("force_factor", 30);

	set("combat_exp", 300000);
	set("bellicosity", 480);
	set("shen_type", -1);

	set_skill("strike", 120);
	set_skill("dodge", 90);
	set_skill("pyrobat-steps", 120);
	set_skill("move", 85);
	set_skill("parry", 100);
	set_skill("celestrike", 120);
	set_skill("celestial", 90);
	set_skill("force", 90);

	map_skill("force", "celestial");
	map_skill("strike", "celestrike");
	map_skill("dodge", "pyrobat-steps"); 

	prepare_skill("strike", "celestrike");

	setup();

	carry_object("obj/cloth")->wear();
	add_money("gold", 2);
}

void die()
{
	object ob;

	if (objectp(ob = query_temp("last_damage_from")) && present(ob))
		ob->add_temp("killing_ypfighter", 1);

	::die();
}
