//《雪山飞狐》
//by tlang

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("老年弈者", ({ "old player","player"}) );
	set("gender", "男性" );
	set("age", 64);
        set("long","一位充满智慧的老者，双目炯炯。\n");
	set("combat_exp", 200000+random(50000));
	set("attitude", "heroism");
	set("chat_chance",10);
        set("chat_msg", ({
                (: command,"smile" :),
		(: command,"say 你的棋艺又有进步了。\n" : ),
        }) );

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
	carry_object(__DIR__"obj/bqi")->wield();
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
			tell_object(ob,"你和老者愉快地谈了一会儿话。\n");
			return 1;
		}
		if(ob->query_temp("talk/oldplayer") )
		{
			add("count",-1);
			tell_object(ob,HIC"你和老者愉快地谈了一会儿。\n"NOR);
			return 1;
		}
		add("count",-1);
		obj=new("/d/hangzhou/npc/obj/book5.c");
		obj->move(ob);
		ob->set_temp("talk/oldplayer",1);
		tell_object(ob,"你和老者谈了一会儿，老人看你人还不错，\n
				就拿出一本书来给你。\n");
			return 1;
	}
	tell_object(ob,"你要和谁说话？\n");
	return 1;		
}

