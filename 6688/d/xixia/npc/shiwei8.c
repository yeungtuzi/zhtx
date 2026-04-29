#include <ansi.h>

inherit NPC;

void create()
{
	set_name(HIY"带刀侍卫"NOR, ({ "blade guard", "guard" }));
	set("age", 18+random(20));
	set("gender", "男性");
	set("long", "皇帝身边的亲信，这时候他正急急忙忙似在办理一件很重要的事。\n");
	set("attitude", "peaceful");

	set("str", 38);
	set("dex", 25);

	set("max_kee", 2400);
	set("max_force", 1000);
	set("force", 1000);
	set("force_factor", 20);

	set("combat_exp", 500000);
	set("shen_type", -1);

	set_skill("unarmed", 90);
	set_skill("force", 40);
	set_skill("huashan-neigong", 60);
	set_skill("dodge", 70);
	set_skill("move", 85);
	set_skill("parry", 120);
	set_skill("blade", 100);
	set_skill("liuhe-dao", 80);

	map_skill("force", "huashan-neigong");
	map_skill("blade", "liuhe-dao");
	map_skill("parry", "liuhe-dao");

	setup();

	carry_object(__DIR__"obj/steel_blade")->wield();
	carry_object(__DIR__"obj/steel_armor")->wear();
	carry_object(__DIR__"obj/shouyu");
	carry_object(__DIR__"obj/lingpai");
}

void die()
{
	object ob;

	if (!random(10))	carry_object(__DIR__"obj/shouyu2");
	if (!(ob = query_temp("last_damage_from")) || environment(ob) != environment()) {
		::die();
		return;
	}
	else	ob->set_temp("tieshu", 1);

	::die();
}
