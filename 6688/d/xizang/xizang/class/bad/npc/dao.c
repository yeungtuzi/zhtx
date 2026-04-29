// /d/xizang/class/bad/npc/dao.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("道可道", ({ "dao", "dao ke dao" }));
	set("title", HIY+"无念天师"+NOR);
	set("gender", "男性" );
	set("age", 25);
	set("str", 26);
	set("cor", 28);
	set("cps", 30);
	set("per", 28);
	set("int", 33);
	set("long", @TEXT
他就是道可道,外号叫作"无念天师",当然是别人遇到他就没咒可念了.他自称
是这个世界的主人,一身"六合八荒唯我独尊神功"深不可测.
TEXT
);
	set("combat_exp", 90000000);
	set("attitude", "heroism");
	set("kee", 4000);
	set("max_kee", 4000);
	set("gin", 4000);
	set("max_gin", 4000);
	set("sen", 4000);
	set("max_sen", 4000);
	set("force", 5000);
	set("max_force", 10000);
	set("mana", 5000);
	set("max_mana", 10000);
	set("atman", 5000);
	set("max_atman", 10000);
	set_skill("force", 1000);
	set_skill("dodge", 1000);
	set_skill("parry", 1000);
	set_skill("unarmed", 1000);
	set_skill("move", 1000);
	set_skill("iron-cloth", 100);
	set_skill("bahuang-gong", 900);

	map_skill("force", "bahuang-gong");

	setup();
	carry_object("/obj/cloth")->wear();
}

//add fight feature
