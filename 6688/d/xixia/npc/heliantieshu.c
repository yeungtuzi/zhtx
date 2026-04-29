#include <ansi.h>

inherit NPC;

void create()
{
	set_name("赫连铁树", ({ "helian tieshu", "helian", "tieshu" }));
	set("age", 44);
	set("title", "一品堂总管");
	set("gender", "男性");
	set("long", "他就是一品堂总管，官拜征东大将军的赫连铁树。\n");
	set("attitude", "peaceful");

	set("str", 38);
	set("per", 24);
	set("lea", 45);
	set("dex", 25);

	set("inquiry", ([
		"一品堂": "阁下若是真有意加入我们一品堂，还请露两手功夫给大家瞧瞧(accept test)！",
	]));
	set("max_kee", 1600);
	set("combat_exp", 180000);
	set("shen_type", -1);

	set_skill("unarmed", 120);
	set_skill("dodge", 90);
	set_skill("move", 85);
	set_skill("parry", 100);

	setup();

	carry_object(__DIR__"obj/silver_armor")->wear();
	carry_object(__DIR__"obj/redcoat")->wear();
	carry_object(__DIR__"obj/feather_shoe")->wear();
	carry_object(__DIR__"obj/red_hat")->wear();
	
	add_money("gold", 10);
}

void init()
{
	object ob;

	::init();

	add_action("do_test", "accept");
	add_action("do_kill", "kill");

	if (interactive(ob = this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

int do_kill(string arg)
{
	if( this_player()->query_temp("tieshu") == 4
	 && (arg == "tieshu" || arg == "helian" || arg == "helian tieshu")) {
		tell_object(this_player(), "此间高手甚多，不好下手，还是等晚上到将军府刺杀比较好。\n");
		return 1;
	}
}

void greeting(object ob)
{
	if (!ob || environment(ob) != environment())	return;

	if (ob->query("mark/一品堂"))
		message_vision("$N向$n一拱手：“这位" + RANK_D->query_respect(ob) + "一路辛苦了，请进里面休息。”\n", this_object(), ob);
	else	
		message_vision("$N向$n一拱手：“这位" + RANK_D->query_respect(ob) + "是否有意加入我们一品堂？”\n", this_object(), ob);
}

int do_test(string arg)
{
	object who, *ob;
	mapping ob_list;
	int i;

	if (arg != "test")	return 0;

	ob_list = environment()->query_temp("objects");

	if (undefinedp(ob_list[__DIR__"shiwei5"])
	 || sizeof(ob = ob_list[__DIR__"shiwei5"]) < 4)
		return notify_fail("今天捧场的太少了，我看改日吧！\n");

	for (i = 0; i < sizeof(ob); i++) {
		if (!living(ob[i]) 
		 || ob[i]->query("gin") < ob[i]->query("max_gin")
		 || ob[i]->query("kee") < ob[i]->query("max_kee")
		 || ob[i]->query("sen") < ob[i]->query("max_sen"))
			return notify_fail("今天捧场的太少了，我看改日吧！\n");
	}
		
	who = this_player();
	if (who->query_temp("yptest") || query("mark/一品堂"))	return 1;
	if (who->query("combat_exp") < 100000)
		return notify_fail("就凭你，也想来我们一品堂混饭吃！\n");

	if (query("is_recruiting"))
		return notify_fail("请阁下稍候片刻！\n");

	message_vision("$N一摆手，道：“好，你们几个陪这位" + RANK_D->query_respect(who) + "捧捧场！”\n", this_object());
	message_vision(HIR"登时，几个一品堂护法将$N团团围在中心！\n"NOR, who);
	for (i = 0; i < 4; i++) {
		ob[i]->kill_ob(who);
		who->fight_ob(ob[i]);
	}

	who->set_temp("yptest", 1);
	set("is_recruiting", 1);
	return 1;
}

void recruit_ypf(object who)
{
	object me = this_object();
	int number, i;

	if( !who || environment(who) != environment()
	 || !who->query_temp("yptest") || who->query("mark/一品堂"))
		return;

	if (query("give_bonus") || !query("is_recruiting"))	return;
	set("give_bonus", 1);
	who->delete_temp("yptest");
	who->set("mark/一品堂", 1);
	
	command("say 好功夫，从今以后，你就是我们一品堂的人啦！");
	message_vision("\n$N转身向后连拍三下，不多时出来一个手托金盘的宫女，盘子里盛着的是一个个硕大的金元宝。\n", me);
	message_vision("$N指着盘子里面金元宝对$n道：“小小见面礼，还请笑纳。”\n", me, who);

	number = who->query("combat_exp") / 100000;
	if (number > 10)	number = 10;
	for (i = 0; i < number; i++)
		new("/obj/money/tenthousand-cash")->move(who);
	if (who->query("shen") > 500000)
		who->add("shen", -500000);	
	if (number == 10)
		tell_object(who, HIW"\n得黄金一千两！\n"NOR);
	else
		tell_object(who, HIW"\n得黄金" + CHINESE_D->chinese_number(number) + "百两！\n"NOR);
	delete("give_bonus");
	delete("is_recruiting");
}
