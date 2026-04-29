//by tlang

#include <ansi.h>
inherit NPC;

void love_girl();

void create()
{
	set_name("贵妇人", ({ "proud woman","woman"}) );
	set("gender", "女性" );
	set("age", 40);
        set("long","这是一位衣着华丽的贵妇人。\n");
	set("combat_exp", 100000); 
	set("attitude", "friendly");
	set("chat_chance",2);
        set("chat_msg", ({
               	(: love_girl :),
        }) );
	set("chat_chance_combat",10);
        set("chat_msg_combat", ({
               	(: love_girl :),
        }) );
	
	set_skill("dodge",40);
	set_skill("finger",40);
	set_skill("parry",40);
	set_skill("nianhua-zhi",20);
	map_skill("finger","nianhua-zhi");
	map_skill("parry","nianhua-zhi");	
	
	setup();
	add_money("gold",1);   
	carry_object(__DIR__"obj/girth3.c")->wear(); 
}

void love_girl()
{
	object obj;
	object ob=this_player();
	object me=this_object();
	
	if(objectp(obj=present("pity girl",environment(me)) ) )
	{
		if(me->is_fighting() )
		{
			command("pat "+obj->query("id"));
			command("say 你们如果敢动我儿一根头发，我就杀了你们。\n");
				return;
		}
	command("smile "+obj->query("id"));		
		return;
	}
	if(me->is_fighting(ob) )
	{
		command("say 你们这些混账，竟然杀了我的女儿！！！\n");
		me->kill_ob(ob);
		return;
	}
	command("cry");
	command("say 谁杀了我的女儿？！\n");	
}
