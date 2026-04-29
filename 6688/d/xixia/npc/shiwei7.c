#include <ansi.h>

inherit NPC;

void create()
{
	set_name("执斧侍卫", ({ "axe guard", "guard" }));
	set("age", 18+random(20));
	set("gender", "男性");
	set("long", "他手执巨斧，看起来是一个可怕的对手。\n");
	set("attitude", "peaceful");

	set("str", 38);
	set("dex", 25);
	set("max_kee", 900);
	set("combat_exp", 180000);
	set("shen_type", -1);

	set_temp("apply/damage", 50);

	set_skill("unarmed", 90);
	set_skill("dodge", 70);
	set_skill("move", 85);
	set_skill("parry", 120);
	set_skill("axe", 120);

	setup();

	carry_object(__DIR__"obj/axe")->wield();
	carry_object(__DIR__"obj/army_armor")->wear();
}
