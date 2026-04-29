//《飞狐外传》
//by tlang

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("少年弈者", ({ "young player","player"}) );
	set("gender", "男性" );
	set("age", 19);
        set("long","一位充满智慧的少年，双目炯炯。\n");
	set("combat_exp", 150000+random(50000));
	set("attitude", "heroism");
	set("chat_chance",2);
        set("chat_msg", ({
                (: command,"xixi" :),
		(: command,"say 多谢老师的指点。\n" : ),
        }) );

	set("combat_exp", 999999);

        set_skill("unarmed", 120);
        set_skill("throwing", 100);
        set_skill("dodge", 100);
        set_skill("force", 130);
        set_skill("literate", 70);

	set_skill("qidaoforce", 100);
        set_skill("meihua-shou", 80);
        set_skill("fall-steps", 10);
        map_skill("unarmed", "meihua-shou");
        map_skill("dodge", "fall-steps");

	set("count",2);
	setup();
	add_money("gold",2);   
	carry_object(__DIR__"obj/girth2.c")->wear(); 
	carry_object(__DIR__"obj/wqi")->wield();
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
		if(query("count")<1 || ob->query_skill("literate",1)>=100 )
		{
			tell_object(ob,"你和少年愉快地谈了一会儿话。\n");
			return 1;
		}
		if(ob->query_temp("talk/yplayer") )
		{
			add("count",-1);
			tell_object(ob,HIC"你和少年愉快地谈了一会儿。\n"NOR);
			return 1;
		}
		add("count",-1);
		ob->set_temp("talk/yplayer",1);
		obj=new("/d/hangzhou/npc/obj/book6.c");
		obj->move(ob);
		tell_object(ob,"你和少年谈了一会儿，少年对你颇有好感，\n
				就送了一本书给你。\n");
			return 1;
	}
	tell_object(ob,"你要和谁说话？\n");
	return 1;		
}

