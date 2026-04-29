// FanYao.c
// pal 1997.05.09

#include "ansi.h"

inherit NPC;
inherit F_MASTER;
inherit F_QUEST;

int do_kill(string arg);

void create()
{
    	set_name("范遥", ({"fan yao","fan","yao",}));
	set("long",
        "他是一位带发修行的头陀，身穿白布长袍。\n"
        "他的脸上七七八八的全是伤疤，简直看不出本来面目了。\n"
	"他正邪兼修，武功渊博无比。\n"
	);

	create_family("明教",35,"弟子");
	set("title","明教"+YEL"光明右使" NOR);
	set("gender", "男性");
	set("attitude", "peaceful");
	set("class", "bonze");

	set("age", 38);
	set("shen_type", -1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("max_kee", 3500);
	set("force", 6000);
	set("max_force", 3000);
	set("force_factor", 100);
	set("combat_exp", 8000000);
	set("score", 10000);

	set_skill("force", 180);
	set_skill("dodge", 180);
	set_skill("parry", 180);     
	set_skill("sword", 180);
	set_skill("xiaoyao-zhang",180);
	set_skill("essence-sword",180);
	set_skill("taxue-wuhen",180);
	set_skill("moni-xinfa",180);

	map_skill("force", "moni-xinfa");
	map_skill("dodge", "taxue-wuhen");
	map_skill("strike", "xiaoyao-zhang");
	map_skill("parry", "xiaoyao-zhang");
	map_skill("sword","essence-sword");

	prepare_skill("strike","xiaoyao-zhang");

	set("inquiry", ([
        	"银叶先生"     : "你...你说什么？\n",
        	"小昭"     : "唉，真象...真象...\n",
	]));

	set("chat_chance_combat", 20);
	set("chat_msg_combat", ({
                (: exert_function, "yinfengdao" :),
                (: exert_function, "touguzhen" :),
                (: exert_function, "recover" :),
                (: exert_function, "recover" :),		
	}) );


	setup();

        carry_object(__DIR__"obj/baipao")->wear();
        carry_object(__DIR__"obj/gangjian")->wield();
}

void init()
{
	::init();
	add_action("do_kill","duizhi");
	add_action("give_quest","quest");
}

int do_kill(string arg)
{
	object ob;

	if(!arg || arg != "下毒")
		return 0;
	if( !this_player()->query_temp("marks/jinhuayinye") )
		return 0;
	ob = this_player();
	message_vision(HIR "范遥面色大变：什么...你都知道了？！\n" NOR,ob);
	message_vision(HIR "范遥双目发出异芒，对$N狂吼一声：老子今天拼了！\n" NOR,ob);
	set("attitude", "agreesive");   
	set_temp("apply/attack",100);
	set_temp("apply/defense",200);
	set_temp("apply/damage",350);
	set("max_sen",20000);
	set("max_gin",20000);
	set("max_kee",5000);
	set("eff_sen",20000);
	set("eff_gin",20000);
	set("eff_kee",5000);
	set("sen",20000);
	set("gin",20000);
	set("kee",5000);
	set("mana",15000);
	clear_condition();
	setup();
	carry_object(__DIR__"obj/gangjian")->wield();
	ob->move("/d/mingjiao/zoulang8");
	move("/d/mingjiao/zoulang8");
	kill_ob(ob);
	ob->kill_ob(this_object());
	return 1;
}

void die()
{
	object ob;

	ob = this_object()->query_temp("last_damage_from");
	if( ob )
	if( ob->query_temp("marks/jinhuayinye") )
	{	
		message_vision(HIR"\n\n范遥临死之前喃喃道：一失足成千古恨，再回首已百年身...我好悔...\n"NOR,ob);
                ob->add("shen",2000000);              
		ob->set("marks/murdurer_found",1);
	}

	::die();
}

// called when not finish the task
int quest_punish(object who) {
        message_vision( (this_object())->query("name")+"对$N一拂袍袖：哼！没出息的东西！\n" ,who);
    who->set("kee",1);
    who->set("quest",0);
    return(0);
}

int valid_bribe(object who,int val) {
        message_vision( (this_object())->query("name")+"向$N一甩袍袖，说道： 什么，你想贿赂我吗？！\n",who);
        return(0);
}

