#include <ansi.h>

inherit NPC;

void create()
{
	set_name("史遇斗", ({"shi yudou", "shi"}));
	set("gender", "男性");
	set("age", 62);
	set("long", @LONG
一个衣衫褴褛的老叫花，知情的人都知道他是丐帮九袋长老史遇斗。
他受了极致命的内伤，已经奄奄一息，看伤势是为散花掌所伤，不知
是哪个少林高手所为？
LONG);

	set("attitude", "peaceful");
	
	set("str", 38);
	set("con", 35);
	set("cor", 50);
	set("cps", 50);
	set("per", 20);
	set("wil", 50);

	set("max_kee", 2000);
	set("eff_kee", 1);
	set("kee", 1);
	set("max_gin", 500);
	set("max_sen", 500);
	set("force", 4000);
	set("max_force", 2000);
	set("force_factor", 150);
	set("shen", 0);
	
	set("combat_exp", 1600000);

	set_temp("apply/armor", 40);
	
	set_skill("force", 180); 
	set_skill("huntian-qigong", 180); 
        set_skill("strike", 150);
	set_skill("xianglong-zhang", 150); 
	set_skill("dodge", 120); 
	set_skill("xiaoyaoyou", 120); 
	set_skill("parry", 150); 
	set_skill("checking", 200);
	
	map_skill("force", "huntian-qigong");
	map_skill("strike", "xianglong-zhang");
	map_skill("parry", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");

	prepare_skill("strike", "xianglong-zhang");
	
	setup();

	carry_object("obj/cloth")->wear();

}

void init()
{
	object ob;

	if (interactive(ob = this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	object me = this_object();

	if (!ob || environment(ob) != environment() || !living(me)) return;
	if (ob->query_temp("tieshu") == 2) {
		ob->set_temp("tieshu", 3);
		command("say 来...来不及了，洪...洪帮主你...你老人家在...在哪里？");
		message_vision(RED"$N绝望地闭上了双眼。\n"NOR, me);
	}

	die();
}
