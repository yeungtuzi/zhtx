// wujiang.c 武将
#include <ansi.h>
inherit NPC;
#include <random_name.h>

void create()
{
	string name;

       	name = get_rndname();
	set_name(name, ({ "wu jiang", "wu", "jiang" }));
	set("title","武将");
	set("gender", "男性");
	set("age", random(10) + 30);
	set("str", 25);
	set("con", 26);
	set("long", "他站在那里，的确有说不出的威风。\n");
	set("combat_exp", 75000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 60);
	set_skill("force", 60);
	set_skill("spear", 60);
	set_skill("yangjia-qiang", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);

	map_skill("spear", "yangjia-qiang");
	map_skill("parry", "yangjia-qiang");

	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 30);

	set("force", 400); 
	set("max_force", 400);
	set("enforce", 10);

	setup();
	carry_object("/obj/weapon/yinqiang")->wield();
	carry_object("/obj/npc/obj/steel_armor")->wear();
}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) && 
		(int)ob->query_condition("killer")) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
}
