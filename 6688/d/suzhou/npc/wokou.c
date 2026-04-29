// wokou.c
// by Tang


#include <ansi.h>

inherit NPC;

string *first_name = ({ "龟田","武宫","小林","山本","田中","西条",
"上杉","丰臣","木下","桥本","竹下","酒井" });
string *name_words = ({ "太郎","次郎","三郎","四郎",
"秀季","英机","雷臧","康夫","原","健","刚造","三十七", });

string ask_me(object who);

void create()
{
	int i;

	string name, id;

	name = first_name[random(sizeof(first_name))];
	name += name_words[random(sizeof(name_words))];

	set_name(name, ({ "wokou" }) );

	set("title", "浪人");
	set("gender", "男性" );
	set("shen_type", -1);
	set("age", 30+random(30));
	set("str", 30);
	set("cor", 30);
	set("cps", 30);
	set("int", 30);
	set("long",
		"这是个来自扶桑的浪人，正盯着手中的酒杯喃喃地念叨着什麽。\n" );

	set("attitude", "aggressive");

	set("inquiry", ([
		"贡品"   : (: ask_me :),
	]) );

	i=random(100)+30;

	set("combat_exp",i*i*i*2/10);

	set("eff_kee",500+(i-30)*5);
	set("kee",500+(i-50)*5);
	set("max_force",i*15);
	set("force",i*15);
	set("force_factor",i/2);

	set_skill("blade", i);
	set_skill("dodge", i);
	set_skill("unarmed", i);
	set_skill("parry", i);
	set_skill("force", i);

	set_temp("apply/attack",  50);
	set_temp("apply/defense", 50);
	set_temp("apply/damage",  20);

	set("chat_msg_combat", ({	(: random_move :)	}) );
	set("chat_chance", 15);
	set("chat_msg", ({	(: random_move :)	}) );
	set("bellicosity", 10000);
	
	setup();
	
	carry_object(__DIR__"obj/wushidao")->wield();
	carry_object(__DIR__"obj/cloth")->wear();
	carry_object(__DIR__"obj/gongpin");
}

string ask_me(object who)
{
	int i;
	object obj,*ob;

	if( obj=present("gongpin",this_object()) ) 
	{
		i=this_object()->query_skill("blade");
		obj->set("tactic_bonus",i*i/10);
	}

	command("grin");
	ob = all_inventory(environment());

	for(i=sizeof(ob)-1; i>=0; i--) 
	{
		if( !userp(ob[i]) ) continue;
		kill_ob(ob[i]);
		ob[i]->fight(this_object());
	}
}
