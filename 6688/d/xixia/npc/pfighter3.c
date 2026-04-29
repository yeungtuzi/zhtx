#include <ansi.h>

inherit NPC;

void create()
{
	set_name("大内高手", ({ "danei gaoshou", "gaoshou" }));
	set("age", 28+random(20));
	set("gender", "男性");
	set("long", "方圆十丈之外，你都能感觉得到他的杀气！\n");
	set("attitude", "peaceful");

	set("str", 38);
	set("con", 30);
	set("dex", 25);
	set("max_kee", 1600);
	set("max_gin", 500);
	set("max_sen", 300);
	set("max_force", 1600);
	set("force", 1600);
	set("force_factor", 101);
	set("combat_exp", 350000);
	set("shen_type", -1);
	set("bellicosity", 1000);

	set_temp("apply/armor", 50);

	set_skill("strike", 120);
	set_skill("dodge", 120);
	set_skill("pyrobat-steps", 120);
	set_skill("parry", 120);
	set_skill("force", 120);
	set_skill("celestial", 120);
	set_skill("celestrike", 120);

	map_skill("force", "celestial");
	map_skill("dodge", "pyrobat-steps");
	map_skill("strike", "celestrike");

	prepare_skill("strike", "celestrike");
	

	setup();

	carry_object("obj/cloth")->wear();
}
