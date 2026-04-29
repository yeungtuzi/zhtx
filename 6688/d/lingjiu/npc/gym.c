//NPC fumy.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("张聆心", ({ "zhang lingxin", "zhang"}));
	set("long", @LONG
她本是江湖中人称不悔刀客张问心的妹子，不知怎么跑
到「灵鹫宫」来当了九天九部中鸾天部的首领。
LONG);
	set("gender", "女性");
	set("title", "灵鹫宫鸾天部首领");
	set("age", 18);
	set("shen_type",1);
	set("attitude", "peaceful");

	set("str", 25);
	set("int", 25);
	set("con", 30);
	set("per", 40);

	set("kee", 1000);
	set("max_kee", 1000);
	set("gin", 500);
	set("max_gin", 500);
	set("force", 1000);
	set("max_force", 1000);
	set("force_factor", 40);

	set("combat_exp", 250000);
	set("score", 10000);
	set_skill("force", 100);
	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("hand",100);
	set_skill("sword", 250);

	set_skill("zhemei-shou",80);
	set_skill("bahuang-gong", 100);

	map_skill("force", "bahuang-gong");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "zhemei-shou");

	prepare_skill("hand", "zhemei-shou");
	create_family("灵鹫宫",3,"弟子");
	setup();
	
	carry_object(__DIR__"obj/weapon0")->wield();
	carry_object(__DIR__"obj/cape")->wear();
	carry_object(__DIR__"obj/cloak")->wear();
        add_money("silver",20);
}

