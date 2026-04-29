#include <ansi.h>

inherit NPC;

void create()
{
	set_name("南海鳄神", ({"nanhai eshen", "nanhai", "eshen"}));
        set("nickname", HIR "凶神恶煞" NOR);
	set("gender", "男性");
	set("age", 33);
	set("long", @LONG
此人在四大恶人排行老三，师传南海派，性情无常，动不动就喀嚓一声，
掐断人脖子。
LONG);
	set("attitude", "peaceful");
	create_family("南海派", 17, "传人");
	
	set("str", 35);
	set("int", 10);
	set("dex", 20);
	set("lea", 10);
	set("per", 13);

	set("max_kee", 2000);
	set("max_gin", 500);
	set("max_sen", 500);
	set("force", 1700);
	set("max_force", 1600);
	set("force_factor", 80);
	
	set("combat_exp", 900000);
	set("bellicosity", 100);

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
	}) );
	set("title", "四大恶人");

	set_temp("apply/armor", 50);
	
	set_skill("force", 100); 
	set_skill("serpentforce", 100); 
	set_skill("tianmo-dafa", 100); 
        set_skill("claw", 120);
	set_skill("spicyclaw", 100); 
	set_skill("dodge", 150); 
	set_skill("parry", 120); 
	set_skill("whip", 100); 
	set_skill("fork", 110);
	set_skill("mo-bian-jue", 110);
	set_skill("mo-shan-jue", 110);
	set_skill("mo-cha-jue", 110); 
	
	map_skill("force", "tianmo-dafa");
	map_skill("claw", "spicyclaw");
	map_skill("whip", "mo-bian-jue");
	map_skill("parry", "mo-bian-jue");
	map_skill("fork", "mo-cha-jue");
	map_skill("dodge", "mo-shan-jue");

	prepare_skill("claw", "spicyclaw");
	
	setup();

	carry_object(__DIR__"obj/crocodile_armor")->wear();
	carry_object("/obj/cloth")->wear();
	carry_object(__DIR__"obj/crocodile_scissor")->wield();
	carry_object(__DIR__"obj/crocodile_whip")->wield();
	add_money("gold", 2);
}

void init()
{
	object ob;

	::init();

	if (interactive(ob = this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	object me = this_object();
	string id;
	mapping fam;

	if ( (fam = ob->query("family")) && fam["master_id"] == "nanhai eshen"
	 && stringp(id = query_temp("apprentice"))
	 && ob->query("id") != id) {
		message_vision("$N搔了搔后脑勺对$n说：“嗯，我发现有个人比你更适合做我南海派的传人。”\n", me, ob);
		command("expell " + ob->query("id"));
		kill_ob(ob);
		return;
	}

	if (!me->query_temp("apprentice") && !ob->is_apprentice_of(me)
	  && ob->query("gender") == "男性" && ob->query_con() == query_con()) {
		message_vision("$N对$n说道：“我看你的后脑勺和我的很相似，很适合做我南海派的传人，你快跪下来拜我岳老二为师吧！”\n", this_object(), ob);
		set_temp("apprentice", ob->query("id"));
		command("recruit " + ob->query("id"));
	}
}
