#include <ansi.h>

inherit "/std/char/doomnpc";

string ask_me();

void create()
{
        set_name("圆真", ({ "yuan zhen","yuan","zhen"}) );
        set("long",
                "他是一个七十多岁的老和尚，满脸阴狠之色。\n"
                "看起来对你不太友善。\n"
         );

        set("title",GRN"少林寺长老"NOR);
        set("age",72);
        set("int",100);
        set("cor",100);

        set("max_gin", 2000);
        set("max_kee", 4000);                    
        set("max_sen", 2000);
        set("max_force",4000); 
        set("force",8000);
        set("force_factor",250);     
        set("combat_exp",2000000);
        set("bellicosity",500000);

        set_skill("jingang-quan", 250);
        set_skill("dodge", 250);
        set_skill("cuff",250);
        set_skill("parry", 250);
        set_skill("shaolin-shenfa",250);
        set_skill("force",250); 
        set_skill("hunyuan-yiqi",250);

        map_skill("cuff","jingang-quan");
        map_skill("parry","jinggang-quan");
        map_skill("dodge","shaolin-shenfa");
        map_skill("force","hunyuan-yiqi");

	prepare_skill("cuff","jingang-quan");

	set("auto_heal",1);

//        set_temp("apply/attack",100);
//        set_temp("apply/dodge",100);

	set("chat_chance",10);
        set("chat_msg", ({
                "魔教妖孽，人人得而诛之。\n",
        }) );

        set("chat_chance_combat",1);
        set("chat_msg_combat", ({
		(: command("hehe") :),
                (: exert_function,"exert roar" :),
        }) );

        set("inquiry",([
                  "成昆" : (: ask_me :),
        ]));

        setup();
        if(random(10)>2) carry_rnd_equip(3,4);
}

void init()
{
	return;
}

string ask_me()
{
	object me,player;

	player = this_player();

	if( !(player->query_temp("marks/yuanzhen")) )
	{
		kill_ob(player);
		player->kill_ob(this_object());
		return "你乱问什么！\n";
	}

        set_name(HIR"成昆"NOR, ({ "cheng kun","cheng","kun"}) );
        set("long",
                "他就是大名鼎鼎的“混元霹雳手”成昆。\n"
                "江湖人士多年找寻于他，却不想他居然在这里。\n"
         );

        set("title",HIY"混元霹雳手"NOR);
	setup();

	set("asker",player);	
	kill_ob(player);
	player->kill_ob(this_object());
	return RANK_D->query_rude(player)+"很机灵嘛，老子今天就送你上西天！\n";	
}

void die()
{
	object killer;

	if( (query("id")!="cheng kun") || !(query("asker")) || !(killer = query_temp("last_damage_from")) || killer != query("asker") )
	{
		::die();
	}		
	message_vision(HIR"成昆一声惨叫，死了。		\n"NOR,killer);
	message_vision(HIY"你拿出随身的快刀，割下了他的首级系在腰间。		\n"NOR,killer);
	new(__DIR__"obj/rentou")->move(killer);
	destruct(this_object());
}
