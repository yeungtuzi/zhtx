//by tlang
//97.12

#include <ansi.h>
inherit NPC;

void create()
{
	set_name(RED"侍卫"NOR, ({ "shi wei", "miaoyu_guarder" }));
        set("title","妙玉贴身侍卫");
	set("long", "他就是江湖中恶人谈而色变的诸葛先生，也是专门与恶人作对的山流组织的老大。\n");
	set("gender", "女性");
	set("age", 50);
	set("attitude", "heroism");
	set("shen_type", 10);
	set("str", 30);
	set("int", 30);
	set("con", 30);
        set("dex", 60);
       
	set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: exert_function, "kuihua" :),
		(: exert_function, "recover" :),
        }) );

	set("max_kee", 3000);
	set("max_gin", 500);
	set("atman", 300);
	set("max_atman", 300);
	set("mana", 300);
	set("max_mana", 300);
	set("force", 5000);
	set("max_force", 5000);
	set("force_factor", 80);
	set("combat_exp", 1000000);
//	set("score", 1000000);

	set_skill("force", 100);
	set_skill("kuihua-shengong", 100);
	set_skill("dodge", 100);
	set_skill("mo-zhang-jue", 100);
	set_skill("strike", 100);
	set_skill("mo-jian-jue", 100);
	set_skill("parry", 100);
	set_skill("sword", 100);
	set_skill("literate", 100);
        set_skill("daguanming",100);

	map_skill("force", "kuihua-shengong");
	map_skill("strike", "mo-zhang-jue");
	map_skill("parry", "mo-jian-jue");
	map_skill("sword", "mo-jian-jue");
	map_skill("dodge", "kuihua-shengong");

	prepare_skill("strike", "mo-zhang-jue");

	setup();

	carry_object("obj/cloth/cloth")->wear();
	carry_object("obj/weapon/gangjian")->wield();
}

void init()
{
	object me;
	me=this_player();

	remove_call_out("greeting");
	call_out("greeting",1,me);
}

void greeting()
{
	object me,ob;
	me=this_player();
	ob=this_object();

	if(!me->query("guard_enemy")) return;
	command("say 你到这儿来撒野，还想逃跑？去死吧！\n");
	ob->set_leader(me);
	ob->kill_ob(me);
}
