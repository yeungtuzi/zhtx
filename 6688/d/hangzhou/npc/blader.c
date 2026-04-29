//《鸳鸯刀》
//by tlang

#include <ansi.h>
inherit NPC;
void improve_blade();

void create()
{
	set_name("少年刀客", ({ "young blader","blader","man"}) );
	set("gender", "男性" );
	set("age", 24);
        set("long","一位充满活力的少年，双目炯炯。\n");
	set("combat_exp", 200000+random(50000));
	set("attitude", "heroism");
	set("chat_chance",2);
        set("chat_msg", ({
                "少年笑道：“这儿真是练刀的好地方！”\n",
		"少年笑道：“我的刀法又涨了一点了。”\n",
        }) );

	set("chat_chance_combat",40);
        set("chat_msg_combat", ({
              (: improve_blade :),
        }) );
	set_skill("dodge",60);
	set_skill("move",100);
	set_skill("unarmed",60);
	set_skill("parry",60);	
	set_skill("blade",100);


	set("count",2);
	setup();
	add_money("gold",2);   
	carry_object(__DIR__"obj/girth2.c")->wear(); 
	carry_object("/d/suzhou/npc/obj/gangdao")->wield();
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
		if(query("count")<1 || ob->query_skill("blade",1)>=100 )
		{
			tell_object(ob,"你和少年愉快地谈了一会儿话。\n");
			return 1;
		}
		if(ob->query_temp("talk/blader") )
		{
			add("count",-1);
			tell_object(ob,HIC"你和少年愉快地谈了一会儿。\n"NOR);
			return 1;
		}
		add("count",-1);
		ob->set_temp("talk/blader",1);
		obj=new("/d/hangzhou/npc/obj/book3.c");
		obj->move(ob);
		tell_object(ob,"你和少年谈了一会儿，少年对你印象不错，把\n
				自己身边的一本书送给了你。\n");
			return 1;
	}
	tell_object(ob,"你要和谁说话？\n");
	return 1;		
}

void improve_blade()
{
	object me=this_object();
	object ob=this_player();
	int myblade;
	int obblade;
	
	myblade=me->query_skill("blade");
	obblade=ob->query_skill("blade");
	
	if(!obblade || obblade<myblade )
	{
		command("haha "+ob->query("name"));
		command("say "+RANK_D->query_respect(ob)+"刀法恐怕还有待提高。\n");
		improve_skill("blade",random(myblade)*2);
			return;
	}
	command("bow "+ob->query("id"));
	command("say "+RANK_D->query_respect(ob)+"的刀法果然高明，在下获益匪浅。\n");
	improve_skill("blade",random(obblade)*2);
}