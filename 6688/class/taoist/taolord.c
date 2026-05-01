// taolord.c

#include <ansi.h>

inherit "/u/z/zephyr/revengenpc.c";
inherit F_MASTER;
inherit F_QUEST;
inherit "/feature/challenge";

string ask_me();

void create()
{
	set_name("林忌", ({ "master taolord", "master", "taolord" }) );
	set("nickname", "六指真人");
	set("gender", "男性");
	set("age", 47);
	set("long",
		"林忌是一位道行十分高深的修道者，你发现他的眼珠一个是黑色的，一\n"
		"个是金色的，这正是「谷衣心法」修炼到极高境界的徵兆。\n");

	set("combat_exp", 1000000);
	set("score", 200000);

	set("class", "taoist");
	set("attitude","peaceful");
	set("str", 30);
	set("int", 30);
	set("cor", 20);
	set("cps", 30);
	set("spi", 30);
	set("no_get",1);


	set("inquiry", ([
		"谷衣心法": "谷衣心法是我茅山派为对抗邪魔外道所创的内功心法。\n",
		"茅山派": "我茅山派自张天师开山立派至今，世世代代皆以降妖伏魔为己任。\n",
		"张天师": (:ask_me:),
	]) );

	set("apprentice_available", 3);
/*
	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: cast_spell, "drainerbolt" :),
		(: cast_spell, "netherbolt" :),
		(: cast_spell, "feeblebolt" :),
		(: cast_spell, "invocation" :),
	}) );
*/
	create_family("茅山派", 5, "天师");

	set_skill("literate", 200);
	set_skill("magic", 100);
	set_skill("force", 150);
	set_skill("spells", 150);
	set_skill("cuff", 70);
	set_skill("sword", 130);
	set_skill("parry", 130);
	set_skill("dodge", 100);
	set_skill("move", 100);
	set_skill("qingcheng-steps", 100);

	set_skill("gouyee", 150);
	set_skill("taosword", 150);
	set_skill("taoism", 200);
	set_skill("necromancy", 150);

        map_skill("force", "gouyee");
	map_skill("spells", "necromancy");
	map_skill("sword", "taosword");
	map_skill("parry", "taosword");
	map_skill("dodge", "qingcheng-steps");
	map_skill("move", "qingcheng-steps");

	set_temp("apply/parry", 30);
	set_temp("apply/armor", 50);

	setup();

	carry_object(__DIR__"sword")->wield();
	carry_object(__DIR__"robe")->wear();
	carry_object(__DIR__"hat")->wear();
	carry_object(__DIR__"shoe")->wear();

	set("max_kee",100);
	set("eff_kee",100);
	set("kee",100);
        set("eff_sen",800);
        set("sen",800);
        set("max_sen",800);
        set("eff_gin",2000);
	set("max_gin",2000);
	set("gin",2000);

	set("force", 2000);
	set("max_force", 1000);
	set("force_factor", 50);

	set("atman", 1000);
	set("max_atman", 1000);

	set("mana", 4000);
	set("max_mana", 2000);
	set("mana_factor", 41);
	set_temp("manashield",1);	
}

void init() {
	::init();
	add_action("give_quest","quest");
	add_action("do_exert","exert");
}                                      

int accept_fight()
{
	say("林忌说道：我们修道之人，不会轻易和别人动手。\n");
	return 0;
}

int get_sword()
{
	object mysword;
	
mysword = present("sword",environment(this_object()));
	if( objectp(mysword) && mysword->query_mana_imp() )
	{
		message_vision("$N拣起了地上的$n。\n",this_object(),mysword);
		mysword->move(this_object());
		message_vision("$N「唰」地一声抽出一把$n握在手中。\n",this_object(),mysword);
		mysword->wield();
	}                                                                
	return 1;
}	                     

int do_exert(string arg)
{
	if(stringp(arg) && strsrch(arg,"tanzhi") != -1 )
		call_out("get_sword",1);
	return 0;
}	

void attempt_apprentice(object ob)
{
	if( query("apprentice_available") ) {
		if( find_call_out("do_recruit") != -1 )
			command("say 慢著，一个一个来。");
		else
			call_out("do_recruit", 2, ob);
	} else {
		command("say 贫道今天已经收了三个弟子，不想再收徒了。");
	}
}

void do_recruit(object ob)
{
	if( (string)ob->query("gender") != "男性" )
		command("say 贫道是出家人，不便收女徒，得罪了。");
	else {
		command("say 嗯... 想入我茅山派？也好....");
		command("recruit " + ob->query("id") );
	}
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "taoist");
	add("apprentice_availavble", -1);
}

// check if bribe is valid
int valid_bribe(object who,int val) {
        message_vision( (this_object())->query("name")+"向$N一甩袍袖，说道： 什么，你想贿赂我吗？！\n",who);
        return(0);
}

// called when not finish the task
int quest_punish(object who) {
        message_vision( (this_object())->query("name")+"向$N一甩袍袖，说道： 真笨，你好好学学功夫再要任务吧！\n" ,who);
    who->set("quest",0);
    return(0);
}

// 让master聪明点
int chat()
{       
	object *enemys,victim;
	int i;
	
	if( !is_fighting() )
	{
		//没魔法盾牌了
		if( !query_temp("manashield") && ((int)query("mana"))>1000 )
			command("cast manashield");			
		//来点惊喜 :)
		if( random(100) > 80 && query("mana")<query("max_mana")*2)
		{
			if(!random(5))
				message_vision(BLU"$N的金色瞳孔之中突然闪过一道妖异的光芒.\n"NOR,this_object());
			add("mana",300);
		}	
		//法力不够了
		if( query("mana") < 2000 )
			command("exert concentrate");	
		return ::chat();
	}	                
	//别太累了
	if( random(100) > 80 || is_busy() ) return ::chat();
	
	clean_up_enemy();
	enemys = query_enemy();
	i = sizeof(enemys);
	//不和NPC之类的家伙战斗
	while(i--)
	{
		if( !userp(enemys[i]) )
		{
			remove_enemy(enemys[i]);
			enemys[i]->remove_enemy(this_object());
		}                                            
	}	
	//现在对手就只剩下玩家了.来判断一下策略
	clean_up_enemy();
	enemys = query_enemy();
	i = sizeof(enemys);
	if( !i ) return ::chat();
	
	//随机挑一个对手吧
	victim = enemys[random(i)];	
	
	//看看怎么对付合适
	
	//是鬼?强盗碰着贼爷爷,正好撞到钟馗
	if (victim->is_ghost())
	{ 
			command("say 何方妖孽,竟敢到我茅山天师座下撒野!");
			kill_ob(victim);
			command("cast thunderbolt");			
	}			                    
	//对茅山的就省点力气吧,胆敢欺师灭祖,哼哼
	else if ( !query("in_race") && victim->query("family/family_name") == "茅山派") 
	{ 
			command("say 胆敢欺师灭祖,真是反了!");
			message_vision(BLU"$N的金色瞳孔之中突然一道妖异的光芒射向$n.\n"NOR,this_object(), victim);
			victim->add("faith", -100);
			victim->unconcious();
		//	command("expell "+victim->parse_command_id_list()[0]);
	}
        else if (victim->query("gin") < 250)
        { 
			evaluate((: cast_spell, "drainerbolt" :));
	}
	else if (victim->query("sen") < 250) 
	{ 
			evaluate((: cast_spell, "feeblebolt" :));
	}
	else
			evaluate((: cast_spell, "netherbolt" :));
	
	return ::chat();		
}	

string ask_me()
{
	object me;
	
	me=this_player();
	if( !objectp(present("dark sword",me)) || !me->query("marks/zhangtianshi_givequest") )
	{
		command("heng");
		return "他？你怎么知道？他是本门叛徒！\n";
	}
	command("say 他？你怎么知道？他是本门叛徒！");
	message_vision("却听得$N高举手中兵刃说：叛徒？只怕事情并非如此吧！\n",me);
	message_vision("$N大怒，喝道：孽畜！竟敢犯上作乱，何来你插嘴的余地！\n",this_object());
	set("in_race",1);
	set("opponent",me);
	move("/d/taoguan/mishi");
	me->move("/d/taoguan/mishi");
	kill_ob(me);
	me->fight_ob(this_object());
}

int die()
{
	object me,sword;
	
	if( query("in_race") && (me=query_temp("last_damage_from"))==query("opponent") && objectp(me) && objectp(sword=present("dark sword",me)) )
	{
		message_vision("$N将手中"+sword->query("name")+"贴在$n胸前，只见一股股黑色之气不停从$n胸口流出，涌入兵刃。\n",me,this_object());
		sword->set("mana_for_zhangtianshi",200);
	}
	return ::die();
}
	
