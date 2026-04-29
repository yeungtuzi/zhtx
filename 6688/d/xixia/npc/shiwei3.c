#include <ansi.h>

inherit NPC;

void create()
{
	set_name(HIY"御前侍卫"NOR, ({ "loyal guard", "guard" }));
	set("age", 18+random(20));
	set("gender", "男性");
	set("long", "皇帝身边的士卫，都是万利挑一的好手。\n");
	set("attitude", "peaceful");

	set("str", 38);
	set("dex", 35);

	set("max_kee", 900);
	set("combat_exp", 250000);
	set("shen_type", -1);

	set_temp("apply/attack", 40);
	set_temp("apply/damage", 20);

	set_skill("unarmed", 90);
	set_skill("dodge", 70);
	set_skill("move", 85);
	set_skill("parry", 120);
	set_skill("blade", 120);

	setup();

	carry_object(__DIR__"obj/steel_blade")->wield();
//	carry_object(__DIR__"obj/iron_shield")->wear();
	carry_object(__DIR__"obj/steel_armor")->wear();
}
