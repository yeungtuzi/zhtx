#include <ansi.h>

inherit NPC;

void create()
{
	set_name(HIM"妙风使"NOR, ({ "miaofeng shi", "miaofeng" }) );
	set("gender", "男性" );
        set("title", HIY"波斯明教护教使者"NOR);
	set("age", 30);
	set("int", 100);
	set("per", 5);
	set("long",
		"波斯明教派来中土寻找乾坤大挪移心法的三使者之一。\n"
		"他黄须鹰鼻，相貌甚是丑陋，\n"
		);
        set("force_factor", 250);
        set("max_gin", 3000);
        set("max_kee", 3000);
        set("max_sen", 3000);
        set("eff_gin", 3000);
        set("eff_kee", 3000);
        set("eff_sen", 3000);
        set("gin", 3000);
        set("kee", 3000);
        set("sen", 3000);
        set("max_atman", 300);
        set("atman", 300);
        set("max_force", 3000);
        set("force", 3000);
        set("max_mana", 300);
        set("mana", 300);

        set("combat_exp", 5000000);
        set_skill("strike", 150);
        set_skill("sword", 150);
        set_skill("force", 150);
        set_skill("parry", 150);
        set_skill("fanwen", 150);
	set_skill("dodge", 150);

	set_skill("moni-xinfa", 150);
	set_skill("shenghuo-shengong", 150);
	set_skill("yueying-wubu", 150);
	set_skill("moni-strike",150);

	map_skill("strike", "moni-strike");
        map_skill("sword", "shenghuo-shengong");
        map_skill("force", "moni-xinfa");
        map_skill("parry", "shenghuo-shengong");
        map_skill("hand", "shenghuo-shengong");
        map_skill("dodge", "yueying-wubu");

        set("chat_chance", 2);
        set("chat_msg", ({
                "我教主接获讯息，得知中土支派教主失踪，群弟子自相残杀，本教大趋式微，\n是以命云风月三使前来整顿教务。合教上下，齐奉号令，不得有误。\n",
                "见圣火令如见教主，明教弟子还不跪迎？\n",
		"明教圣火令到，明教弟子，还不下跪迎接，更待何时？\n",
		"圣女黛绮丝犯了失贞重罪，一定要火刑处死！\n",
        }) );

	setup();
	
	set_temp("apply/attack",200);
	set_temp("apply/dodge",200);
	set_temp("apply/damage",200);

	carry_object(__DIR__"obj/heibaipao")->wear();
      	carry_object(__DIR__"obj/ling5")->wield();
         if (random(100)>90) carry_object(__DIR__"obj/ling-all");
      	carry_object(__DIR__"obj/ling6")->wield();
}

int accept_fight(object me)
{
	object victim;
	
	command("say 吾素闻彼等中华之人武艺高强，在下愧不敢以一人之力应战。\n");
	command("say 我等三人素来进退一体，如此我等三人就一起进招了。\n");	
	if( objectp(victim = present("liuyun shi", environment(this_object()))) )
		victim->fight_ob(this_player());
	if( objectp(victim = present("huiyue shi", environment(this_object()))) )
		victim->fight_ob(this_player());

	return 1;
}

void init()
{
        object ob;
	
	add_action("do_killing", "kill");
	
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }

}

void greeting(object ob)
{
	object victim;
	
//	command("grin");                  
//	write("marks/daiyisi = " + ob->query_temp("marks/daiyisi") + "\n");
	if( (ob->query_temp("marks/daiyisi")) )
	{
			ob->set_temp("marks/killing_3_shi",1);
			message_vision(HIR"妙风使对你喝道：大胆！竟敢袒护叛教贱人，哪里逃！\n"NOR,ob);
			command("chat "+" 黛绮丝你这叛教贱人，你逃到天涯海角，也休想逃过圣火焚身之刑！"); 	
			add_temp("apply/attack",100);
			add_temp("apply/damage",100);
			this_object()->kill_ob(ob);
			set("max_kee",1000000);
			set("kee",1000000);
			set("eff_kee",1000000);
			ob->kill_ob(this_object());
			if( objectp(victim = present("huiyue shi", environment(this_object()))) )
			{
				victim->add_temp("apply/attack",50);
				victim->add_temp("apply/damage",50);
				victim->kill_ob(ob);
				ob->kill_ob(victim);
			}
			if( objectp(victim = present("liuyun shi", environment(this_object()))) )
                	{
				victim->add_temp("apply/attack",50);
				victim->add_temp("apply/damage",50);
				victim->kill_ob(ob);
				ob->kill_ob(victim);
			}

       	}
}

void die()
{
	object killer;
	
	if( objectp(killer = query_temp("last_damage_from")) )
	if( killer->query_temp("marks/daiyisi") && killer->query_temp("marks/killing_3_shi") )
		killer->set_temp("marks/miaofeng",1);
	::die();
}

int do_killing(string arg)
{
	object victim,other;
	string name;
	
        if( objectp(victim = present(arg, environment(this_object()))) && living(victim))
	{	
		name = victim->query("id");
		if(name == "liuyun shi" || name == "huiyue shi")
		{
			message_vision(HIR"$N对你喝道：吾看你是不想活了。\n"NOR,this_object());
			kill_ob(this_player());
			this_player()->kill_ob(this_object());
		}
	}        

	return 0;
	
}

