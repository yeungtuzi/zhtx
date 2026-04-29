#include <ansi.h>

inherit NPC;

void create()
{
	set_name("老叫花", ({"old beggar", "beggar"}));
	set("gender", "男性");
	set("age", 62);
	set("long", @LONG
一个衣衫褴褛的老叫花。
LONG);

	set("attitude", "peaceful");
	
	set("str", 38);
	set("con", 35);
	set("cor", 50);
	set("cps", 50);
	set("per", 20);

	set("max_kee", 2000);
	set("max_gin", 500);
	set("max_sen", 500);
	set("force", 4000);
	set("max_force", 2000);
	set("force_factor", 150);
	set("shen", 50000);
	
	set("combat_exp", 1600000);

	set("inquiry", ([
		"name": "小人名字不值一提。",
	]));

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
	if (!ob || environment(ob) != environment()) return;
	tell_object(ob, "老叫花抬头瞥了你一眼。\n");
}

int accept_object(object who, object ob)
{
	object me = this_object();

	if (ob->id("shou yu") && ob->name() == "手谕" 
	 && who->query_temp("tieshu") == 1) {
		message_vision(HIY"$N接过手谕打开一扫，惊呆了！好半天才缓过来，黄豆大的汗珠自额头涔涔掉下。\n"NOR, me);
		message_vision(HIY"$N向$n一拱手道：“在下丐帮史遇斗，多谢英雄以消息相赠，现在是十月初六，离大会只有三天期限，我当星夜兼程，禀告洪帮主！”\n"NOR, me, who);
		if (present("little beggar"))
			message_vision("$N转身对小叫花道：“乖孙子，你留在中兴府随时注意西夏一品堂的动静！爷爷有要事先走一步啦！”\n", me);
		message_vision("$N对着$n一拱手：“英雄不言谢，咱们后会有期！告辞！”\n", me, who);
		message_vision("$n拱了拱手道：“史长老一路保重！”\n", me, who);

		who->set_temp("tieshu", 2);
		who->add("potential", 30);
		who->add("combat_exp", 300);
		tell_object(who, HIW"得经验三百点，潜能三十点。\n"NOR);

		call_out("go_away", 1, me);
		return 1;
	}


	return 0;
}

void go_away(object me)
{
	message_vision("言毕，史遇斗急急忙忙的离开了。\n", me);
	destruct(me);
}
