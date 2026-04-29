//by tlang

#include <ansi.h>
inherit NPC;

void need_help();

void create()
{
	set_name("怜儿", ({ "pity girl","girl"}) );
	set("gender", "女性" );
	set("age", 14+random(4));
        set("long","一位随母亲出来旅游的女孩。\n");
	set("combat_exp", 10000);

	set("attitude", "friendly");
	
	set("chat_chance_combat",2);
        set("chat_msg_combat", ({
               (: need_help :),
        }) );
		
	set("chat_chance_combat",30);
        set("chat_msg_combat", ({
               (: need_help :),
        }) );

	set_skill("dodge",20);
	set_skill("parry",20);
	set_skill("finger",20);
	set_skill("nianhua-zhi",10);
	map_skill("finger","nianhua-zhi");
	map_skill("parry","nianhua-zhi");

	setup();
	add_money("gold",1);   
	carry_object(__DIR__"obj/girth.c")->wear(); 
}

void need_help()
{
	object obj;
	object ob=this_player();
	object me=this_object();
	
	if(objectp(obj=present("proud woman",environment(me)) ) )
	{
		if(me->is_fighting() )
		{
			command("cry "+obj->query("id"));
			command("say 妈妈，它们欺负我。\n");
			obj->set_temp("guarded",({me}));
				return;
		}
	command("xixi "+obj->query("id"));		
		return;
	}
	if(me->is_fighting(ob) )
	{
		command("say 你们这些混账，竟然杀了我的妈妈！！！\n");
		me->kill_ob(ob);
		return;
	}
	command("cry");
	command("say 谁杀了我的妈妈？！\n");	
}


