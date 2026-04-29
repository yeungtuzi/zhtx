//《碧血剑》
//by tlang

#include <ansi.h>
inherit NPC;
void improve_sword();

void create()
{
	set_name("少年剑客", ({ "young sworder","sworder","man"}) );
	set("gender", "男性" );
	set("age", 24);
        set("long","一位充满活力的少年，双目炯炯。\n");
	set("combat_exp", 200000+random(50000));
	set("attitude", "heroism");
	set("chat_chance",2);
        set("chat_msg", ({
                "少年笑道：“这儿真是练剑的好地方！”\n",
		"少年笑道：“我的剑法又涨了一点了。”\n",
        }) );

	set("chat_chance_combat",40);
        set("chat_msg_combat", ({
              (: improve_sword :),
        }) );
	set_skill("dodge",60);
	set_skill("move",100);
	set_skill("unarmed",60);
	set_skill("parry",60);	
	set_skill("sword",100);

	set("count",2);
	setup();
	add_money("gold",2);   
	carry_object(__DIR__"obj/girth2.c")->wear(); 
	carry_object("/d/suzhou/npc/obj/gangjian")->wield();
}

void init()
{
	add_action("give_talk","talk");
}

int give_talk(string arg)
{
	object obj;
	object me=this_object();
	object ob=this_player();
	int myint,obint;

	myint=me->query("int");
	obint=ob->query("int");
	if(arg==me->query("id") )
	{
		if(query("count")<1 || ob->query_skill("sword",1)>=100 )
		{
			tell_object(ob,"你和少年愉快地谈了一会儿话。\n");
			return 1;
		}
		if(ob->query_temp("talk/sworder") )
		{
			add("count",-1);
			tell_object(ob,HIC"你和少年愉快地谈了一会儿。\n"NOR);
			return 1;
		}
		add("count",-1);
		ob->set_temp("talk/sworder",1);
		obj=new("/d/hangzhou/npc/obj/book4.c");
		obj->move(ob);
		tell_object(ob,"你和少年谈了一会儿，少年对你印象不错，把\n
				自己身边的一本书送给了你。\n");
			return 1;
	}
	tell_object(ob,"你要和谁说话？\n");
	return 1;		
}

void improve_sword()
{
	object me=this_object();
	object ob=this_player();
	int mysword;
	int obsword;
	
	mysword=me->query_skill("sword");
	obsword=ob->query_skill("sword");
	
	if(!obsword || obsword<mysword )
	{
		command("haha "+ob->query("name"));
		command("say "+RANK_D->query_respect(ob)+"剑术恐怕还有待提高。\n");
		improve_skill("sword",random(mysword));
			return;
	}
	command("bow "+ob->query("id"));
	command("say "+RANK_D->query_respect(ob)+"的剑法果然高明，在下获益匪浅。\n");
	improve_skill("sword",random(obsword));
}