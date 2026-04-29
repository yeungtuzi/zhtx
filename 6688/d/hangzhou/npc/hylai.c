//by tlang
//97.12

#include <ansi.h>
inherit NPC;

int do_escape();

void create()
{
	set_name("花夜来", ({"hua yelai", "hua"}) );
	set("long", "她一只手托着香腮，手腕圆润，手指纤美，眉目间仿佛\n"
"带着种淡淡的幽怨，仿佛正在感怀着春的易老，情人的离别。\n");
	set("per", 40);
	set("int", 30);
	set("gender", "女性");
	set("age", 30);
	set("force", 1000);
	set("max_force", 1000);
	set("force_factor", 50);
	
	set_skill("dodge", 100);
	set_skill("force", 100);
	set_skill("unarmed", 100);
	set_skill("parry", 100);
	set_skill("sword", 100);
	set_skill("chaos-steps", 80);
	set_skill("fonxanforce", 80);
	set_skill("fonxansword", 100);
	map_skill("sword", "fonxansword");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("force", "fonxanforce");	

	add_money("silver", 5);
	setup();
	carry_object("/d/suzhou/npc/obj/gangjian")->wield();
	carry_object("/d/suzhou/npc/obj/cloth2")->wear();
}

void init()
{
	object me;
	me=this_player();

	::init();
	remove_call_out("greeting"); 
   	call_out("greeting",1,me);

}

void greeting()
{
	object me;
	me=this_player();
	
	if( !me || environment(me) != environment() ) return; 
      	command("sigh");
	remove_call_out("do_escape");
	call_out("do_escape",3);
}

int do_escape()
{
	object ob,obj;
	obj=new("/d/hangzhou/npc/obj/bydao");
	obj->move("/d/hangzhou/huaf");
	command("say 有人来了，小白脸，我走了。\n");
	ob=this_object();
	destruct(ob);
		return 1;
}


	
