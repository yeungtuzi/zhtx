#include <ansi.h>

inherit NPC;

void create()
{
	set_name(RED"大内高手"NOR, ({ "danei gaoshou", "gaoshou" }));
	set("age", 28+random(20));
	set("gender", "男性");
	set("long", "来自西藏的密宗高手！\n");
	set("attitude", "peaceful");

	set("str", 38);
	set("con", 30);
	set("dex", 25);
	set("max_kee", 1600);
	set("max_gin", 500);
	set("max_sen", 300);
	set("max_force", 1600);
	set("force", 1600);
	set("force_factor", 121);
	set("combat_exp", 350000);
	set("shen_type", -1);
	set("bellicosity", 500);

	set_temp("apply/armor", 50);
	set_temp("apply/armor_vs_force", 30);

	set_skill("strike", 120);
	set_skill("dodge", 120);
	set_skill("iron-cloth", 120);
	set_skill("jin-gang", 120);
	set_skill("parry", 120);
	set_skill("force", 120);
	set_skill("bolomiduo", 120);
	set_skill("bloodystrike", 120);

	map_skill("force", "bolomiduo");
	map_skill("iron-cloth", "jin-gang");
	map_skill("strike", "bloodystrike");

	prepare_skill("strike", "bloodystrike");
	

	setup();

	carry_object("obj/cloth")->wear();
}
