#include <ansi.h>

inherit NPC;

void create()
{
	set_name(HIC"流云使"NOR, ({ "liuyun shi", "liuyun" }) );
	set("gender", "男性" );
        set("title", HIY"波斯明教护教使者"NOR);
	set("age", 25);
	set("int", 300);
	set("per", 30);
	set("long",
		"波斯明教派来中土寻找乾坤大挪移心法的三使者之一。\n"
		"他虬髯碧眼，相貌和中土人士大异，武功嘛，没有人知道深浅。\n"
		);
        set("force_factor", 50);
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

        set("combat_exp", 500000);
        set_skill("strike", 150);
	set_skill("hand",150);
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
 	map_skill("hand", "shenghuo-shengong");
        map_skill("sword", "shenghuo-shengong");
        map_skill("force", "moni-xinfa");
        map_skill("parry", "shenghuo-shengong");
        map_skill("dodge", "yueying-wubu");

	prepare_skill("hand","shenghuo-shengong");

        setup();

	set_temp("apply/damage",200);
	set_temp("apply/dodge",200);
	set_temp("apply/attack",200);

	carry_object(__DIR__"obj/heibaipao")->wear();
      	carry_object(__DIR__"obj/ling3")->wield();
      	carry_object(__DIR__"obj/ling4")->wield();
}

void die()
{
	object killer;
	
	if( objectp(killer = query_temp("last_damage_from")) )
	if( killer->query_temp("marks/daiyisi") )
		killer->set_temp("marks/liuyun",1);
	::die();
}

int accept_fight(object me)
{
	object victim;
	
	command("say 吾素闻彼等中华之人武艺高强，在下愧不敢以一人之力应战。\n");
	command("say 我等三人素来进退一体，如此我等三人就一起进招了。\n");	
	if( objectp(victim = present("miaofeng shi", environment(this_object()))) )
		victim->fight_ob(this_player());
	if( objectp(victim = present("huiyue shi", environment(this_object()))) )
		victim->fight_ob(this_player());

	return 1;
}

void init()
{
	add_action("do_killing", "kill");
}

int do_killing(string arg)
{
	object victim,other;
	string name;
	
        if( objectp(victim = present(arg, environment(this_object()))) && living(victim))
	{	
		name = victim->query("id");
		if(name == "miaofeng shi" || name == "huiyue shi")
		{
			message_vision(HIR"$N对你喝道：吾看你是不想活了。\n"NOR,this_object());
			kill_ob(this_player());
			this_player()->kill_ob(this_object());
		}
	}        

	return 0;
	
}
                                                 
                                                 
