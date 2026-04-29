#include <ansi.h>

inherit NPC;

void create()
{
	set_name("小叫花", ({"little beggar", "beggar"}));
	set("gender", "男性");
	set("age", 16);
	set("long", @LONG
一个衣衫褴褛的小叫花。
LONG);

	set("attitude", "peaceful");
	
	set("str", 38);
	set("con", 35);
	set("per", 23);

	set("max_kee", 1000);
	set("force", 2000);
	set("max_force", 1200);
	set("shen", 10000);
	set("force_factor", 60);
	
	set("combat_exp", 200000);

	set("inquiry", ([
		"name": "小人名字不值一提。",
	]));

	set_temp("apply/armor", 40);
	set_temp("apply/damage", 40);
	
	set_skill("force", 150); 
	set_skill("huntian-qigong", 150); 
        set_skill("strike", 80);
	set_skill("xianglong-zhang", 80); 
	set_skill("dodge", 120); 
	set_skill("xiaoyaoyou", 120); 
	set_skill("parry", 100); 
	set_skill("staff", 130);
	set_skill("dagou-bang", 130);
	set_skill("checking", 150);
	
	map_skill("force", "huntian-qigong");
	map_skill("strike", "xianglong-zhang");
	map_skill("parry", "dagou-bang");
	map_skill("staff", "dagou-bang");
	map_skill("dodge", "xiaoyaoyou");

	prepare_skill("strike", "xianglong-zhang");
	
	setup();

	carry_object("obj/cloth")->wear();
	carry_object(__DIR__"obj/dagoubang")->wield();

}

void init()
{
	object ob;

	if (interactive(ob = this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 2, ob);
	}
}

void greeting(object ob)
{
	object shicorpse;

	if (!ob || environment(ob) != environment()) return;
	if (present("old beggar") || ob->query_temp("tieshu") != 4) return;
	if (query("move")) {
		if ((shicorpse = present("corpse"))
		 && shicorpse->name() == "史遇斗的尸体")
		command("cry corpse"); 
		ob->set_temp("littlebeggar", 1);
		return;
	}
	tell_object(ob, "你把史长老受伤至死的消息告诉了小叫花。\n");
	command("say 这不可能！！！");
	message_vision("小叫花拔腿就往城东跑，慌乱中脚下一个不稳，险些摔倒。\n", ob);
	set("move", 1);
	move("/d/xixia/eshulin");
}
