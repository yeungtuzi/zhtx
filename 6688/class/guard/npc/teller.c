//with wisdomer.c for telling some secret to players by tlang
//teller.c

#include <ansi.h>
inherit NPC;

void greeting(object);
int dest();

void create()
{
	set_name(YEL"江湖百晓生"NOR, ({"teller"}) );
	set("long", "据说他对江湖中事无所不知，无所不晓。\n");
	set("per", 30);
	set("int", 30);
	set("str", 30);
	set("gender", "男性");
	set("age", 20+random(60));
	set("combat_exp", 500000+random(1000000));
	set("max_force", 1500);
	set("force", 1500);
	
	set_skill("dodge", 150);
	set_skill("unarmed", 150);
	set_skill("parry", 150);
	set_skill("blade", 150); 
	set_skill("force", 100);
	set_skill("cibei-dao", 100);
	set_skill("xiaoyaoyou", 100);
	set_skill("hunyuan-yiqi", 100);
	map_skill("blade", "cibei-dao");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("force", "hunyuan-yiqi");
	
	set("count",1);
	add("gold", 5);
	setup();
	carry_object("/d/suzhou/npc/obj/cloth2")->wear();
	carry_object("/d/suzhou/npc/obj/gangdao")->wield();
	call_out("dest",600);
}

void init()
{       
	object ob=this_player();

        ::init();
        remove_call_out("greeting"); 
        call_out("greeting", 5, ob);    
}

void greeting(object ob) 
{       
        if( !ob || environment(ob) != environment() ) return;
        command("say 如果你给我一些好处，我可以告诉你孙老儿的消息，他可\n
	以带你去了解秘密。\n");
	command("smile");
	call_out("greeting",120,ob);
}                                   

void accept_object(object who, object ob)
{
	object obj;
	
	obj=new("/class/guard/npc/wisdomer.c");

	if( query("count")<1 )
	{
		command("sigh");
		command("say 今天已经有人来过了。等下次吧。\n");	
			return;	
	} else {
		if(!ob->query("money_id") || ob->value() <5000)
		{
		command("waggle "+who->query("id"));
		command("say 这一点点还不够我喝杯茶。哼！！！！\n");
			return;
		}
		destruct(ob);
		switch(random(2))
		{
		case 0:
		command("say 孙老儿现在在苏州客栈。你可以去找他。\n");	
		obj->move("/d/suzhou/kezhan");
		add("count",-1);
	    	break;
		case 1:
		command("say 孙老儿现在在雪亭镇客栈。你可以去找他。\n");
		obj->move("/d/snow/inn");
		add("count",-1);
		break;
		default:
		command("say 孙老儿现在在西藏客栈。你可以去找他。\n");
		obj->move("/d/guanwai/inn");
		add("count",-1);
		break;
		}
	}
}

int dest()
{
	command("bye");
	destruct(this_object());
}
