//by tlang
//97.12
//zhuba.c

#include <ansi.h>
inherit NPC;

void create()
{
	set_name(HIW"朱八太爷"NOR, ({"zhu bataiye", "zhu"}) );
	set("long", "他就是宝珠山庄庄主朱八太爷，看上去气宇轩昂，笑嘻嘻地\n"
		"一团和气。\n");
	set("per", 30);
	set("int", 30);
	set("str", 30);
	set("gender", "男性");
	set("age", 39);
	set("combat_exp", 2000000);
	set("max_force", 1500);
	set("force", 1500);
	
	set_skill("dodge", 150);
	set_skill("unarmed", 150);
	set_skill("parry", 150);
	set_skill("finger",150);
	set_skill("force", 150);
	set_skill("nianhua-zhi", 120);
	set_skill("xiaoyaoyou", 120);
	set_skill("hunyuan-yiqi", 120);
	map_skill("finger", "nianhua-zhi");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("force", "hunyuan-yiqi");
	
	prepare_skill("finger","nianhua-zhi");
	
	add("gold", 2);
	setup();
	carry_object("/d/suzhou/npc/obj/cloth2")->wear();
}

void init()
{       
        object ob; 
        ob = this_player();

        ::init();
        remove_call_out("greeting"); 
        call_out("greeting", 1, ob);    
}

void greeting() 
{       
	object me;
	me=this_player();

        if( !me->query("sender") )
		 return; 
        command("hi");
	command("say 你可是为我送金丝背心来的？\n");
}                                   
	
int accept_object(object who, object ob)
{
	
	object me=this_player();
	// 2026-04-30: unused variable commented out
	// object obj=ob;
	
        if (!userp(ob) && (string)ob->query("id")=="gold vest")
	{
	if(!me->query("sender"))
		return notify_fail("这不是你的任务吧？！\n");
	if(!me->query("test3"))
		return notify_fail("这不是你完成的吧？！唉！\n");
	command("say 多谢了!你完成了这个任务，经验和潜能都会大有进步的。\n");
	destruct(ob);
	me->add("combat_exp", 500);
	me->add("potential",50);
	me->set("done3",1);
	me->delete("test3");
	me->delete("sender");
	tell_object(me,"你的经验和潜能都增加了。\n");
		return 1;
       	} else {
		return notify_fail("你给我这东西干嘛？\n");
		}
      
}
