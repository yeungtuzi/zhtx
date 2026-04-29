//NPC fumy.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("杨素兰", ({ "yang sulan", "yang"}));
	set("long", @LONG
杨素兰嫁到婆家之后，受尽折磨，后来跟随童姥到了
灵鹫宫。
LONG);
	set("gender", "女性");
	set("title", "灵鹫宫成天部首领");
	set("age", 32);
	set("shen_type",1);
	set("attitude", "peaceful");

	set("per", 22);
	set("kee", 800);
	set("max_kee", 800);
	set("gin", 500);
	set("max_gin", 500);
	set("force", 1000);
	set("max_force", 1000);
	set("force_factor", 20);

	set("combat_exp", 300000);
	set("score", 10000);
	set_skill("force", 100);
	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("hand",100);
	set_skill("whip", 250);

	set_skill("zhemei-shou",80);
	set_skill("bahuang-gong", 100);

	map_skill("force", "bahuang-gong");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "zhemei-shou");

	prepare_skill("hand", "zhemei-shou");
	create_family("灵鹫宫",3,"弟子");
	setup();
	
	carry_object(__DIR__"obj/weapon2")->wield();
	carry_object(__DIR__"obj/cape")->wear();
	carry_object(__DIR__"obj/cloak")->wear();
        add_money("silver",20);
}

