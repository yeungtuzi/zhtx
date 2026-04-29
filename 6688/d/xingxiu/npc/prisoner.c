#include <ansi.h>

inherit NPC;

void create()
{
	set_name("穿云子", ({ "chuanyun zi", "chuanyun" }));
	set("nickname", "星宿派前大师兄");
	set("long", @LONG
他本是丁春秋的大弟子穿云子，因为自恃武功高强，不但对老仙不敬，
更异想天开想取代丁春秋做星宿派的掌门，遂被老怪制服后关押在此。
他蓬头垢面，双眼泛红，脸上和双手皆呈紫黑之色，看来中毒已久。他
已经完全疯了！
LONG);
	set("gender", "男性");
	set("age", 39);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 40);
	set("int", 20);
	set("per", 10);
	set("con", 26);
	set("bellicosity", 1500);
	
	set("max_kee", 1000);
	set("max_gin", 300);
	set("max_sen", 300);
	set("force", 1800);

	set("max_force", 1800);
	set("force_factor", 60);

	set("combat_exp", 700000);
	set("score", 30000);
	set("chat_chance_combat", 5);
	set("chat_msg_combat", ({
		"如今只有拿你练毒入体了！\n",
		"穿云子势如恶狼，恨不得要把你吃了！\n",
	}));

	set_skill("force", 100);
	set_skill("huagong-dafa", 120);
	set_skill("dodge", 90);
	set_skill("strike", 120);
	set_skill("xingxiu-duzhang", 120);
	set_skill("parry", 100);
	set_skill("literate", 80);
	set_skill("dugong", 100);
	set_skill("fushi-dugong", 100);

	map_skill("force", "huagong-dafa");
	map_skill("strike", "xingxiu-duzhang");
  	map_skill("parry", "xingxiu-duzhang");
	map_skill("dugong", "fushi-dugong");

	prepare_skill("strike", "xingxiu-duzhang");

	create_family("星宿派", 2, "弟子");

	setup();
	carry_object("/obj/cloth")->wear();
}

void init()
{
	object me;

	me = this_player();

	message_vision(HIR"穿云子一见到$N，就扑了过去。。。\n"NOR, me);
	kill_ob(me);
}

int accept_object(object who, object ob)
{
	object me = this_player();

	if( who->query("mark/ding_chushi") == 1
	&& ob->query("poison_available") ){
		me->remove_killer(ob);
		me->remove_enemy(ob);
		command("halt");
		command("say 多...多谢这位"+RANK_D->query_respect(ob)+"，不过为时已...已晚，我已经七天七夜没...没有炼毒入体了，已...已经回天无...无力了。");
		command("say 我告...告诉你一个秘密，星...星宿老怪原是一个叫逍...逍遥派的...的叛徒，他来...来星宿海好象是找...找什么秘藉。");
		if( me->query("gender") == "女性" )
			command("say 你...你现在已...已经是大...大师姐了，要提...提防丁老怪！");
		else	
			command("say 你...你现在已...已经是大...大师兄了，要提...提防丁老怪！");
		who->set("mark/ding_chushi", 2);
		message_vision("穿云子说完这几句话，脸黑如墨，甚是恐怖，呼吸已是出气多入气少。。。\n", me);
		tell_object(me, "你听了满腹狐疑，但想起丁春秋平素的所做所为，又不由得不信，况且人之将死，穿云子又何必说慌呢？");
		call_out("to_die", 1, me);
		return 1;
	}
	return 0;
//	return ::accept_object(who, ob);
}

void to_die(object me)
{
	tell_object(me, "你想再问个明白，可是穿云子已经死了。\n");
	die();
	return;
}
