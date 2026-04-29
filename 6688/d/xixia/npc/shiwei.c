#include <ansi.h>

inherit NPC;

void create()
{
	set_name(HIY"金衣侍卫"NOR, ({ "golden guard", "guard" }));
	set("age", 18+random(20));
	set("gender", "男性");
	set("long", "皇宫的守卫，军中百里挑一的武士。\n");
	set("attitude", "peaceful");

	set("str", 38);
	set("dex", 25);
	set("max_kee", 1000);
	set("combat_exp", 200000);
	set("shen_type", -1);

	set_temp("apply/attack", 30);

	set_skill("unarmed", 90);
	set_skill("dodge", 90);
	set_skill("move", 85);
	set_skill("parry", 100);
	set_skill("blade", 120);

	setup();

	carry_object(__DIR__"obj/blade")->wield();
	carry_object(__DIR__"obj/army_armor")->wear();
}
