#include <ansi.h>

inherit NPC;

void create()
{
	set_name(HIR"将军府护卫"NOR, ({ "guard"}));
	set("age", 18+random(20));
	set("gender", "男性");
	set("long", "将军府护卫。\n");
	set("attitude", "peaceful");

	set("str", 23);
	set("dex", 25);

	set("max_kee", 400);
	set("combat_exp", 60000);
	set("shen_type", -1);

	set_skill("unarmed", 50);
	set_skill("dodge", 30);
	set_skill("move", 25);
	set_skill("parry", 50);
	set_skill("spear", 40);

	setup();

	carry_object(__DIR__"obj/army_spear")->wield();
	carry_object(__DIR__"obj/army_armor")->wear();
}
