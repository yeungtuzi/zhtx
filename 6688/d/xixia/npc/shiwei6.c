#include <ansi.h>

inherit NPC;

void create()
{
	set_name(HIY"金甲卫士"NOR, ({ "loyal guard", "guard" }));
	set("age", 18+random(20));
	set("gender", "男性");
	set("long", "西夏军中千里挑一的勇士。\n");
	set("attitude", "peaceful");

	set("str", 38);
	set("dex", 25);
	set("max_kee", 2400);
	set("combat_exp", 300000);
	set("shen_type", -1);

	set_temp("apply/attack", 30);
	set_temp("apply/damage", 30);
	set_temp("apply/defense", 30);

	set_skill("unarmed", 90);
	set_skill("dodge", 100);
	set_skill("move", 85);
	set_skill("parry", 120);
	set_skill("sword", 120);

	setup();

	carry_object(__DIR__"obj/longsword")->wield();
	carry_object(__DIR__"obj/golden_head")->wear();
	carry_object(__DIR__"obj/golden_shield")->wear();
	carry_object(__DIR__"obj/golden_armor")->wear();
}
