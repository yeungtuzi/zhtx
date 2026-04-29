//by tlang
         
#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name(HIW"飘柔"NOR, ({ "flying girl", "girl" }));
	set("shen_type", 1);

	set("str", 20);
	set("per",29);
	set("gender", "女性");
	set("age", 22);
	set("long",  "一位漂亮的小美眉，大概缺钱用，卖起了地图。 \n");

	set("combat_exp", 1000);
	set("attitude", "friendly");
	set("inquiry", ([
		"飘柔" : "飘柔就是我啦。\n",
		"生意" : "这个么……，就靠您多关照了，嘻嘻。\n",
	]));
	
	set("vendor_goods", ([
		"/d/hangzhou/npc/obj/hzmap":30,
	]));

	setup();
	add_money("silver",1);
	carry_object("/d/suzhou/npc/obj/bjcloth")->wear();
}

void init()
{
	object ob;
	
	::init();
	if (interactive(ob = this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
        add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
	if (!ob || environment(ob) != environment())
		return;
	switch(random(2)) {
	case 0 :
		command("say " + RANK_D->query_respect(ob) +"请多关照。\n");
		break;
	case 1 :
		command("say "+ RANK_D->query_respect(ob) +"泥到杭州来最好买张地图。\n");
		break;
	}
}
