#include <ansi.h>

inherit NPC;

void create()
{
	set_name("一品堂护法", ({ "yiping fighter", "fighter" }));
	set("age", 18+random(20));
	set("gender", "男性");
	set("long", "一品堂重金聘请的武林高手。\n");
	set("attitude", "peaceful");

	set("str", 38);
	set("dex", 25);
	set("wil", 30);

	set("max_kee", 800);
	set("force", 900);
	set("max_force", 900);
	set("force_factor", 80);

	set("combat_exp", 200000);
	set("bellicosity", 400);
	set("shen_type", -1);

	set_temp("apply/attack", 50);

	set_skill("strike", 120);
	set_skill("dodge", 90);
	set_skill("move", 85);
	set_skill("parry", 100);
	set_skill("celestrike", 90);
	set_skill("celestial", 100);
	set_skill("force", 100);

	map_skill("force", "celestial");
	map_skill("strike", "celestrike");

	prepare_skill("strike", "celestrike");

	setup();

	carry_object("obj/cloth")->wear();
	add_money("gold", 1);
}

void unconcious()
{
	object ob, helian;

	if (!(ob = query_temp("last_damage_from")))	return;

	if ((helian = present("helian tieshu")) && helian->query("is_recruiting") && ob->query_temp("yptest"))
		if (ob->query_temp("hitdownypf") >= 3) {
			ob->delete_temp("hitdownypf");
			helian->recruit_ypf(ob);
		}
		else	ob->add_temp("hitdownypf", 1);

	return ::unconcious();
}
