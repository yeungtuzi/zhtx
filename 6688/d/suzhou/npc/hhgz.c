//NPC:/d/suzhou/npc/hhgz.c
//by dwolf              
//97.11.4

#include <ansi.h>
inherit NPC;

void create()
{
	set_name(BLK"花花公子"NOR, ({ "huahua gongzi", "gongzi" }));
	set("gender", "男性");
	set("age", 20);
	set("long",
        	YEL"他衣着华丽，面目凶恶，看见你在看它，狠狠地瞪了你一眼。\n"NOR);

	set("attitude", "peaceful");

	set("str", 26);
	set("int", 25);
	set("per", 20);
	set("combat_exp", 30000);
        	
		
	set("chat_chance", 5);
	set("chat_msg", ({
		MAG"花花公子陶醉地道，“这小妞不错啊！ \n"NOR,
		RED"花花公子象是在自言自语：要多和人talk.\n"NOR,
	}) );
	
	set("shen_type",-1);
	set("bellicosity",100);	
	set("force", 200);
	set("max_force", 200);
	set("force_factor", 5);

	set_skill("dodge", 30);
	set_skill("blade", 40);
	set_skill("parry", 50);
	set_skill("force", 30);
	set_skill("unarmed", 40);
	
	setup();

	carry_object("/d/huashan/obj/baishan")->wear();
}      

void init()
{
	object ob=this_player();
	remove_call_out("greeting");
	call_out("greeting",1,ob);
}

void greeting()
{
	object ob=this_player();
	
	if(!environment() || environment(ob)!=environment() )
		return;
	if(ob->query("gender")!="女性")
		return;
	if(ob->query("per")<=20 )
	{
		command("sigh "+ob->query("id"));
		return;
	}
	command("kiss "+ob->query("id"));
		return;
}	
		