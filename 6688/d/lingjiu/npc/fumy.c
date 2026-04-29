//NPC fumy.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("符敏仪", ({ "fu mingyi", "fu"}));
	set("long",
	    "她是「灵鹫宫」九天九部中阳天部的首领。\n"+
	    "她穿针走线的功夫出神入化，有「针神」之誉。\n");
	set("gender", "女性");
	set("nickname", HIR "针神" NOR);
	set("title", "灵鹫宫阳天部首领");
	set("age", 22);
	set("shen_type",1);
	set("attitude", "peaceful");

	set("str", 25);
	set("int", 25);
	set("con", 30);

	set("kee", 800);
	set("max_kee", 800);
	set("gin", 500);
	set("max_gin", 500);
	set("force", 1000);
	set("max_force", 1000);
	set("force_factor", 40);

	set("combat_exp", 200000);
	set("score", 10000);
	set_skill("force", 100);
	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("hand",100);
	set_skill("throwing", 250);

	set_skill("zhemei-shou",80);
	set_skill("bahuang-gong", 100);

	map_skill("force", "bahuang-gong");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "zhemei-shou");

	prepare_skill("hand", "zhemei-shou");
	create_family("灵鹫宫",3,"弟子");
	setup();
	
	carry_object(__DIR__"obj/needle")->wield();
	carry_object(__DIR__"obj/cape")->wear();
	carry_object(__DIR__"obj/cloak")->wear();
        add_money("silver",20);
}

