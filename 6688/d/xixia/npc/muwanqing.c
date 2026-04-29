#include <ansi.h>

inherit NPC;

void pining();

void create()
{
	set_name("木婉清", ({ "mu wanqing", "mu"}));
	set("long", @LONG
她对段玉一往情深，结果没想到段玉就是她的亲哥哥，一腔幽怨
无处诉。
LONG);
	set("gender", "女性");
	set("nickname", HIR"见血封喉"NOR);
	set("age", 18);
	set("shen_type",-1);
	set("attitude", "peaceful");

	set("str", 23);
	set("int", 25);
	set("per", 30);
	set("dex", 27);
	set("con", 22);

	set("max_kee", 900);
	set("max_gin", 500);
	set("max_sen", 500);
	set("force", 1000);
	set("max_force", 1000);
	set("force_factor", 20);

	set("chat_chance", 5);
	set("chat_msg", ({
		(: pining :),
	}));

	set("combat_exp", 170000);
	set("score", 1);
	set("shen", -100);
	set("bellicosity", 1200);

	set_skill("force", 80);
	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("sword",100);

	set_skill("yuenv-jian", 80);
	set_skill("sunv-xinfa", 100);

	map_skill("force", "sunv-xinfa");
	map_skill("sword", "yuenv-jian");
	map_skill("parry", "yuenv-jian");

	setup();
 	carry_object(__DIR__"obj/jinpao")->wear();
	carry_object(__DIR__"obj/longsword")->wield();
        add_money("silver",70);
}

void pining()
{
	if (present("butterfly")) {
		message_vision("美丽的蝴蝶在$N身边尽情地嘻戏着，花间的美人频添三分姿色。\n", this_object());
		message_vision("$N此时心中更是烦躁！\n", this_object());
		command("kill butterfly");
		command("kill butterfly 2");
	}
}
