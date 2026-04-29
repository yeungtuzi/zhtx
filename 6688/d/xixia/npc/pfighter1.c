#include <ansi.h>

inherit NPC;

void create()
{
	set_name(HIY"大内高手"NOR, ({ "danei gaoshou", "gaoshou" }));
	set("age", 28+random(20));
	set("gender", "男性");
	set("long", "他双目炯炯有神，太阳穴高高隆起，一看就知道武功非比寻常。\n");
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
	set("bellicosity", 500);

	set_temp("apply/armor", 50);

	set_skill("claw", 120);
	set_skill("dodge", 120);
	set_skill("shaolin-shenfa", 120);
	set_skill("parry", 120);
	set_skill("force", 120);
	set_skill("hunyuan-yiqi", 120);
	set_skill("yingzhua-gong", 120);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("claw", "yingzhua-gong");
	map_skill("parry", "yingzhua-gong");

	prepare_skill("claw", "yingzhua-gong");
	

	setup();

	carry_object("obj/cloth")->wear();
}
