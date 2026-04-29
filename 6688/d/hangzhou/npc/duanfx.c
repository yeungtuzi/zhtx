//by tlang
//97.12
//duan2.c

#include <ansi.h>
inherit NPC;

void create()
{
	set_name(HIM"段飞熊"NOR, ({"duan feixiong", "duan"}) );
	set("long", "他就是中原大豪杰段飞熊，威风凛凛，不怒自威。\n");
	set("per", 30);
	set("int", 30);
	set("str", 30);
	set("gender", "男性");
	set("age", 39);
	set("combat_exp", 1000000);
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
	
	add_money("gold", 5);
	setup();
	carry_object("/d/suzhou/npc/obj/baishan")->wear();
	carry_object("/d/suzhou/npc/obj/gangdao")->wield();
}

void init()
{       
        object ob; 
        ob = this_player();

        ::init();
        remove_call_out("greeting"); 
        call_out("greeting", 1, ob);    
        add_action("do_accept", "accept");
	add_action("do_refuse", "refuse");
}

void greeting() 
{       
	object me;
	me=this_player();

        if( !me->query("mark/ok") || me->query("marks/save_duan")>3 )
	{
		command("hi "+me->query("id"));
			 return; 
        }
	command("say 你救了我儿，我想报答你，你愿意接受(accept)钱还是不要(refuse)?\n");
	me->delete("mark/ok");
	me->set_temp("pending/duan", 1);
}                                   

int do_accept()
{
	object me,ob;
	me=this_player();

	if( !me->query_temp("pending/duan") )
		return 0;
	command("say 如此多谢了。\n");
	me->delete_temp("pending/duan");
	ob=new("/obj/money/thousand-cash");
	ob->move(me);
		return 1;
}
	
int do_refuse()
{
	object me=this_player();
	int help_time;

	help_time=me->query("marks/save_duan");

	if( !me->query_temp("pending/duan") )
		return 0;
	me->delete_temp("pending/duan");
	me->add("combat_exp", 500*1/help_time);
	me->add("potential",100*1/help_time);
	me->set("marks/kid",1);
	command("say 好孩子，我告诉你一些江湖趣事，让你涨涨经验。\n");
		return 1;
}
	
int accept_object(object who, object ob)
{
	
	object me=this_player();
	object obj;
		
        if (!userp(ob) && (string)ob->query("id")=="biyu dao" 
&& me->query("marks/kid")) {
	    	if(!query("yl_trigger")) 
		{
		say("多谢了，老夫幼年在苏州曾经蒙金庸先生送了一个光碟，就转送给你吧。\n");
		destruct(ob);
		obj=new("/d/hangzhou/npc/obj/guangdie");
		obj->move(me);	
		set("yl_trigger", 1);
		me->delete("marks/kid");
			return 1;
          	}   
	command("sorry "+me->query("id"));  
		return 1;
	}
	return 0;
}
