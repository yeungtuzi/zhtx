// /d/xizang/class/bad/npc/nstar.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("西瓜", ({ "nstar", "xi gua", "gua" }));
	set("title", YEL+"武当义士"+NOR);
	set("gender", "男性" );
	set("age", 29);
	set("str", 32);
	set("cor", 34);
	set("cps", 22);
	set("int", 22);
	set("per", 22);
	set("long", "他身强体壮,风尘仆仆,正是慷慨豪侠的武当义士西瓜\n");
	set("combat_exp", 1600000);
	set("attitude", "heroism");
	set("force", 2500);
	set("max_force", 2500);
	set("force_factor", 50);
	set_skill("unarmed", 100);
	set_skill("parry", 100);
	set_skill("dodge", 99);
	set_skill("sword", 160);
	set_skill("force", 199);
	set_skill("taiji-jian", 140);
	set_skill("taiji-quan", 155);
	set_skill("taiji-shengong", 199);
	set_skill("move", 99);
	set_skill("tiyunzong", 199);

	map_skill("sword", "taiji-jian");
	map_skill("parry", "taiji-jian");
	map_skill("unarmed", "taiji-quan");
	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("move", "tiyunzong");

	setup();
	carry_object(OBJ_DIR"cloth")->wear();
	carry_object(OBJ_DIR"weapon/gangjian")->wield();
}
