// servant.c

inherit "/u/z/zephyr/revengenpc.c";
inherit F_MASTER;
inherit F_QUEST;
inherit "/feature/challenge";

string ask_blade();

void create()
{
	set_name("於兰天武", ({ "master champion", "champion", "master" }) );
	set("title", "水烟阁传功使");
	set("nickname", "大天邪");
	set("gender", "男性");
	set("age", 54);
	set("long",
		"於兰天武是当今皇上的叔父，但是他毕生浸淫武学，甘愿抛弃荣华富\n"
		"以换取水烟阁传功使一职，以便阅读水烟阁中所藏的武学典籍，无论\n"
		"你有什麽武学上的疑难，他都能为你解答。\n");

	set("attitude", "peaceful");
          set("combat_exp", 5000000);
        set("shen_type",-1);

	set("str", 100);
	set("int", 30);
	set("cor", 100);
	set("cps", 100);                       
	set("per", 30);
	set("con", 30);
	set("no_get",1);

	set("atman", 1000);
	set("max_atman", 1000);

	set("force", 4000);
	set("max_force", 2200);
	set("force_factor", 200);

	set("mana", 1000);
	set("max_mana", 1000);

	//added by yeung,让champion防御强点,现在太容易死
	//因为powerup不能加防御
	set("max_kee",3500);
	set_temp("apply/defense",100);
	set_temp("apply/armor_vs_force",100);
	set_temp("apply/armor",100);
	
           set("bellicosity",5000);

	set("inquiry", ([
		"武学": "武学之道....嗯....只可意会，不可言喻。\n",
		"水烟阁": "水烟阁乃是历届武林盟主的行馆，你有什麽事要见武林盟主？\n",
		"拜师": "哦....老夫向来有个规矩，凡是想拜我为师的，得接我三招不死，而且，一年你只能试一次，你想试试(accept test)？\n",
		"春风拂人醉": (:ask_blade:),
	]) );

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
	}) );
	create_family("天邪派", 15, "弟子");
	assign_apprentice("弟子", 0);

	set_skill("force", 200);
	set_skill("strike", 200);
	set_skill("sword", 150);
	set_skill("blade", 220);
	set_skill("parry", 200);
	set_skill("dodge", 200);
	set_skill("throwing", 150);

	set_skill("celestial", 200);
	set_skill("celestrike", 200);
	set_skill("spring-blade", 220);
	set_skill("pyrobat-steps", 200);

	map_skill("force", "celestial");
	map_skill("strike","celestrike");
	prepare_skill("strike", "celestrike");
	map_skill("blade", "spring-blade");
	map_skill("dodge", "pyrobat-steps");

	set("shen_type",-1);
	set("skill_mark/spring-blade",1);
	setup();

	carry_object(__DIR__"houndbane")->wield();
	carry_object("/obj/cloth")->wear();
	carry_object(__DIR__"dragon_armor")->wear();
}

void init()
{
	add_action("do_accept", "accept");
	add_action("give_quest", "quest");
	if( this_player()->query("family/family_name")=="天邪派" ) return;
	else
		::init();
}


int do_accept(string arg)
{
	// 2026-04-30: unused variable commented out
	// mapping guild;
	object me;

	if( !(me = this_player())->query("can_speak") ) return 0;

	if( arg== "test" ) {
		if( me->query("family/family_name") != "天邪派" )
			return notify_fail(this_object()->name()+"说：我只收本派弟子！\n");
			
		if( me->query("family/generation") <= 16 )	
		        return notify_fail(this_object()->name()+"说：你跟我开什么玩笑！\n");

		if( (me->query("mud_age") - me->query("apprentice_champion")) <= 86400 )
		{
			return notify_fail(this_object()->name()+"说：你现在还没资格向我挑战，再好好练功吧！\n");
		}	
		
		set_temp("tester",me);
		me->set("apprentice_champion",me->query("mud_age"));
		command("unwield blade");
		command("exert powerup");
		set("force_factor",100);		
		say("\n於兰天武点了点头，说道：很好，这是第一招....\n\n");
		COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon"));
		if( (int)this_player()->query("kee") < 0 
		|| !present(this_player(), environment())) {
			say("於兰天武叹了口气，说道：连第一招都撑不过，真是自不量力....\n");
			return 1;
		}
		say("\n於兰天武说道：这是第二招....\n\n");
		COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon"));
		if( (int)this_player()->query("kee") < 0 
		|| !present(this_player(), environment())) {
			say("於兰天武「哼」地一声，说道：便是有这许多不怕死的家伙....\n");
			return 1;
		}
		say("\n於兰天武说道：第三招来了....\n\n");
		COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon"));
		if( (int)this_player()->query("kee") < 0 
		|| !present(this_player(), environment())) {
			say("於兰天武叹道：可惜，难道老夫一身武功竟无传人....\n");
			return 1;
		}
		say("\n於兰天武哈哈大笑，说道：今日老夫终於觅得一个可造之才！\n\n");
		command("recruit " + this_player()->query("id") );
		command("wield blade");
		set("force_factor",200);		
		return 1;
	}
	return 0;
}

string ask_blade()
{
	object me=this_player();
	object blade;

	if( me->query("family/family_name") != "天邪派" )
		return "你不是本派弟子，问什么问！";
			
	if( me->query("family/generation") != 16 )	
	        return "你现在还没资格问这个！";

	if( me->query("faith") < (me->query("betrayer")*20000) || me->query("faith") < 1500 )
	{
	        say("於兰天武神色间对你似乎并不信任：这个嘛...\n");
	        return "我今天有点累了，要休息一下。";
	}              
	                    
	if( me->query_skill("spring-blade",1) < 180 )                   
		return "你的刀法修为太低，说了你也听不明白！";
	
        if( !objectp( blade = present("yaodao goutu",this_object()) ) )
	{
		return "我趁手的兵器不在手头，没法给你讲解！";	
	}	
		
	if( me->query("skill_mark/spring-blade")  )
	{	
		return "我不是跟你解说过其中秘诀了么？怎么还问！";        		
	}	
	
	say("於兰天武说道：春风快意刀法，重在一气呵成，酣畅淋漓的气度，\n与率意挥洒，天马行空般无迹可寻的招式。\n");
	say("於兰天武说道：你原本招式一味求快求猛，当然一直无法领略这门\n武功最精华的部分。\n");
	say("於兰天武说道：「春风拂人醉」，本是春风快意刀法中至强至刚之招式，\n然强极易折，只有领会了至阳生至阴的武学要旨，才能真正领会。\n");
	say("於兰天武说罢，信手使出「春风拂人醉」,却见他手中"+blade->name()+"\n轻飘飘地在空中转向，招数中竟无半分火气。\n");	
	message_vision("$N默思良久，终于恍然大悟，明白了“至刚生至柔，龙虎交会，水火相济”的武学道理。\n",me);
	tell_object(me,"你学会了春风快意刀法中「春风拂人醉」这一招！\n");
	me->set("skill_mark/spring-blade",1);
	if( me->query_skill("spring-blade",1) < 220 ) me->improve_skill("spring-blade",50000);
	if( me->query_skill("spring-blade",1) < 220 ) me->improve_skill("spring-blade",50000);
	if( me->query_skill("spring-blade",1) < 220 ) me->improve_skill("spring-blade",50000);				
}                                                                         

mixed hit_ob(object me, object victim, int damage_bonus)
{
        if(victim == me) return; 
        if( objectp(me->query_temp("tester")) && me->query_temp("tester") == victim )
        	return;
        else
        	me->delete_temp("tester");
        	
	victim->receive_wound("kee",damage_bonus/2);
        return damage_bonus;
}
