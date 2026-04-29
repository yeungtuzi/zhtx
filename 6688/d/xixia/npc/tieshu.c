#include <ansi.h>

inherit NPC;

void create()
{
	set_name("赫连铁树", ({ "helian tieshu", "helian", "tieshu" }));
	set("age", 44);
	set("title", "一品堂总管");
	set("gender", "男性");
	set("long", "他就是一品堂总管，官拜征东大将军的赫连铁树。\n");
	set("attitude", "aggressive");

	set("str", 38);
	set("per", 24);
	set("lea", 45);
	set("dex", 25);
	set("env/wimpy", 10);

	set("inquiry", ([
		"一品堂": "阁下若是真有意加入我们一品堂，还请露两手功夫给大家瞧瞧(accept test)！",
	]));
	set("max_kee", 1600);
	set("combat_exp", 180000);
	set("bellicosity", 5000);
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

varargs int receive_wound(string type, int damage, object who)
{
	if (objectp(who) && who->query_temp("tieshu") == 5)
		who->set_temp("tieshu", 6);

	return ::receive_wound(type, damage, who);
}
