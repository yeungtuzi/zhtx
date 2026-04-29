#include <ansi.h>
inherit NPC;

void kill_ob(object ob)
{
	command("kick");
	remove_all_killer();
}	                    

void accept_kill(object ob)
{
	kill_ob(ob);
}	

void create()
{
	set_name(HIG"花云"NOR, ({ "hua yun","hua","yun","easts"}) );
	set("gender", "女性" );
	set("title",HIM"唧唧歪歪"NOR);
	set("age", 20);
        set("long","一位漂亮的小美眉，因为和神仙有了矛盾，\n所以神仙把她变成了机器人，放在华山。\n");
	set("per",30);
	set("int",30);

	set("combat_exp", 1000000); 
	set("attitude", "friendly");
		
	set("max_force",1000);
	set("force",1000);
	set("max_mana",800);
	set("mana",800);
	set("max_atman",800);
	set("atman",800);

	set("chat_chance",2);
        set("chat_msg", ({
                (: command("face") :),
                (: command("pat fox") :),
                (: command("hug fox") :)
        }) );

	set("chat_chance_combat",60);
        set("chat_msg_combat", ({
//                (: perform_action, "sword.chan" :),
                (: exert_function , "powerup" :)
        }) );
	
	set_skill("literate",200);
	set_skill("music",150);

	set_skill("dodge",150);
	set_skill("cuff",150);
	set_skill("parry",150);
	set_skill("sword",150);	
	set_skill("force",150);
	set_skill("huashan-shenfa",120);
	set_skill("poyu-quan",120);
	set_skill("zixia-shengong",120);	
	set_skill("dugu-jiujian",120);		
	map_skill("dodge","huashan-shenfa");
	map_skill("cuff","poyu-quan");	
	map_skill("parry","dugu-jiujian");
	map_skill("sword","dugu-jiujian");	
	map_skill("force","zixia-shengong");
	prepare_skill("cuff","poyu-quan");
	set("force_factor",80);

	set("inquiry",([
	"道可道" : ({
		(: command,"fear" :),
		(: command,"shake" :),
		(: random_move :),
		}),
	"dao" : ({
		(: command,"fear" :),
		(: command,"shake" :),
		(: random_move :),
		}),
	"流星雨" : ({
		(: command,"fear" :),
		(: command,"shake" :),
		(: random_move :),
		}),
	"logs" : ({
		(: command,"fear" :),
		(: command,"shake" :),
		(: random_move :),
		}),
	]));

	setup();
	carry_object("/d/suzhou/npc/obj/bjcloth.c")->wear(); 
	carry_object("/obj/weapon/sword")->wield();
}

void init()
{
	add_action("do_look","look");	
}	
                                     
int do_look(string arg)
{
	object ob = this_player();
	
	if( !arg || !id(arg) ) return 0;
	command("say "+HIG"看也没用，可怜的"+ob->name()+"，别妒忌我的美貌。\n"NOR);
	command("sing "+ob->query("id"));
	return 0;
}	                                     

