#include <ansi.h>

inherit NPC;

void create()
{
	set_name(BLK"执戟侍卫"NOR, ({ "halberdier guard", "guard" }));
	set("age", 18+random(20));
	set("gender", "男性");
	set("long", "由长枪兵升级后的兵种，对付骑兵效果很好。\n");
	set("attitude", "peaceful");

	set("str", 38);
	set("dex", 20);

	set("max_kee", 650);
	set("combat_exp", 100000);
	set("shen_type", -1);

	set_temp("apply/attack", 20);

	set_skill("unarmed", 90);
	set_skill("dodge", 50);
	set_skill("move", 55);
	set_skill("parry", 100);
	set_skill("halberd", 100);

	setup();

	carry_object(__DIR__"obj/halberd")->wield();
	carry_object(__DIR__"obj/army_armor")->wear();
}
