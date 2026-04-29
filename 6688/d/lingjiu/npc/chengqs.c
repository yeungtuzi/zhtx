#include <ansi.h>

inherit NPC;

void create()
{
	set_name("程青霜", ({ "cheng qingshuang", "cheng"}));
	set("long",
	    "她是「灵鹫宫」九天九部中钧天部的首领.\n");
	set("gender", "女性");
	set("title", "灵鹫宫钧天部首领");
	set("age", 20);
	set("shen_type",1);
	set("attitude", "peaceful");

	set("str", 25);
	set("int", 25);
	set("per", 27);
	set("con", 30);

	set("kee", 800);
	set("max_kee", 800);
	set("force", 1000);
	set("max_force", 1000);
	set("force_factor", 20);

	set("combat_exp", 200000);
	set("score", 10000);
	set_skill("force", 100);
	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("hand",100);

	set_skill("zhemei-shou",80);
        set_skill("bahuang-gong", 70);

	map_skill("force", "bahuang-gong");
	map_skill("hand", "zhemei-shou");


	prepare_skill("hand", "zhemei-shou");

	create_family("灵鹫宫",3,"弟子");
	setup();
	carry_object(__DIR__"obj/cape")->wear();
	carry_object(__DIR__"obj/cloak")->wear();
	add_money("silver",10);
}

