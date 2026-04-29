//zhang ji for helping new players
//by tlang

#include <ansi.h>
inherit NPC;

string ask_me_lucy();
string ask_me_sparrow();
int accept_object(object,object);
int dest();

string *start_loc = ({
        "/d/snow/inn",
        "/d/guanwai/inn",
        "/d/cloud/tearoom",
        "/d/jingcheng/jiuguan",
        "/d/yueyang/kedian",
	"/d/suzhou/kezhan",
});

void create()
{
	set_name(BLK"张骥"NOR, ({ "zhang ji", "zhang","ji" }));
	set("gender", "男性");
	set("age", 20);
	set("long",@LONG
他衣着华丽，样子吊二郎当的，一看就知道是个爱多事的人。
LONG
);

	set("attitude", "peaceful");

	set("str", 26);
	set("int", 30);
	set("per",30);

	set("combat_exp", 200000+random(50000));
	 	
	set("max_force", 1500);
	set("force", 1500);
	set("force_factor", 50);
	set("max_mana",1000);
	set("mana",1000);
	set("max_atman",1000);
	set("atman",1000);

	set_skill("dodge", 200);
	set_skill("move",200);
	set_skill("parry", 200);
	set_skill("force", 200);
	set_skill("unarmed", 100);
	set_skill("zixia-shengong",100);
	map_skill("force","zixia-shengong");
	
	set("chat_chance",2);
	set("chat_msg",({
		(: command,"sigh" :),
		(: command,"say 我的初恋女孩子在哪儿？唉。。。\n" : ),
		(: command,"hmm" :),
		(: command,"say 都是我对不起她。...pp\n" : ),
	}));
	set("inquiry", ([
		"初恋女孩" : ({
		(: command,"hmm" :),
		(: command,"say 她叫。。。。。\n" : ),
		(: command,"say 我说给你猜吧：早上草上有什么？她是双名。。。。。\n" :),
		}),
		"lovegirl" : ({
		(: command,"hmm" :),
		(: command,"say 她叫。。。。。\n" : ),
		(: command,"say 我说给你猜吧：早上草上有什么？她是双名。。。。。\n" :),
		}),
                "露露" : (: ask_me_lucy :),
		"lucy" : (: ask_me_lucy :),
		"麻雀" : (: ask_me_sparrow :),
		"sparrow" : (: ask_me_sparrow :),
        ]));

	set("count",3);	
	set("trigger",1);
	set("pills",2);	

	setup();	
	carry_object("/d/suzhou/npc/obj/scloth.c")->wear();   
}

string ask_me_lucy()
{
	object ob=this_player();
	object obj;
	string startroom;	

	if(!ob->query_temp("save_lucy/success") )
	{
	if(!ob->query_temp("save_lucy/zhangji") || ob->query_temp("save_lucy/zhangji")<3 )
	{	
		if( query("count")<1 )
			return "你在说什么啊？我听不懂。\n";
		if( !query_temp("done") )
		{
			ob->set_temp("save_lucy/zhangji",1);
			set_temp("done",1);
			return "露露？我。。我不大清楚。。。\n";
		}
		if( query_temp("done")==1 )
		{
			add_temp("done",1);	
			ob->add_temp("save_lucy/zhangji",1);
			command("killair "+ob->query("id"));
			return "你问这个干什么？小心我要你的命！\n";
		}
		add("count",-1);
		ob->add_temp("save_lucy/zhangji",1);
		command("whisper "+ob->query("id")+" 你既然这样问，我就告诉你吧。\n露露是我的初恋情人，可惜几年前我对不起她，她离开了我。\n如果你能帮我找到她，我忘不了你的。\n");
			return "求求你千万别告诉别人。\n";
	}
	ob->add_temp("save_lucy/zhangji",-1);
	command("sorry "+ob->query("id"));
	command("say 我究竟什么地方得罪你了，这样苦苦相逼？\n");
		return "我。。。。。唉。\n";
	}
	tell_object(ob,"你告诉张骥到空中楼阁去找露露。\n");
	if(ob->query("save_lucy/time")>= 2)
	{	
		tell_object(ob,"你已经救了两次了，你不烦我都烦了。。。哼。\n");
			return "我们已经和好了。\n";
	}
	if(ob->query("save_lucy/time")==1)
	{
		add("count",-1);
		tell_object(ob,"谢谢你了，可我只有一件破衣服可以给你了，你不嫌弃，就拿着吧。\n");
		obj=new("/d/suzhou/npc/obj/scloth2");
		obj->move(ob);
		ob->add("save_lucy/time",1);
		call_out("dest",1);
			return "说罢拿出一件衣服给你。\n";
	}	
	add("count",-1);
	command("say 谢谢泥！这一张万两银票就是报酬了。我这就去找露露，再见。。。。。\n");
	ob->add("save_lucy/time",1);
	ob->delete_temp("save_lucy/success");
	obj=new("/obj/money/tenthousand-cash");
	obj->move(ob);
//	ob->delete_temp("pending/lucy");
//	command("down");
	call_out("dest",1);
//	return "张骥飞快地跑了。\n";�	
}

string ask_me_sparrow()
{
	object ob=this_player();
	object obj;
	string startroom;
	
	if(!ob->query_temp("have_asked") || query("trigger")<1 )
	{
		command("heng "+ob->query("id"));
		ob->set_temp("have_asked",1);
		return "谁叫你问这种问题的？小心点儿。\n";
	}
	if(ob->query_temp("have_asked")==1)
	{
		command("kick "+ob->query("id"));
		ob->add_temp("have_asked",1);
		return "听不懂人话还是怎么的？叫你别问了。\n";
	}
	if(ob->query_temp("have_asked")==2)
	{
		command("angry "+ob->query("id"));
		ob->add_temp("have_asked",1);
		return "你欠揍是不是？哼。。。。\n";
	}
	if(ob->query_temp("have_asked")==3)
	{
		add("trigger",-1);
		command("bow "+ob->query("id"));
		ob->add_temp("have_asked",1);
		obj=new("/obj/money/gold");
		obj->move(ob);
		return "这是我的踔号，求求你千万别说出去。这两黄金算是报酬。\n";
	}
	command("smash "+ob->query("id"));
	if( ob->query("age")>=16 )
	{
		startroom = start_loc[random(sizeof(start_loc))];  
		ob->move(startroom);   
		return "问上瘾了很难收口是不是？别以为我好欺负！！！滚你的蛋吧。\n";	
	}
	ob->move("/d/suzhou/kezhan");
	tell_object(ob,"问上瘾了很难收口是不是？别以为我好欺负！滚吧。\n");
	return "要不是看你年纪小，就送你到天涯海角去，哼！\n";
}

void init()
{
	object ob=this_player();
	remove_call_out("greeting");
	call_out("greeting",1,ob);
	add_action("do_kick","kick");
	add_action("do_yell","yell");
}

void greeting(object ob) 
{       
        if( !ob || environment(ob) != environment()  )
		return;
	if(ob->query("combat_exp")>=2000 )
	{
		command("hi "+ob->query("id") );
			return;
	}
	if(ob->query("gender")!="女性" )
	{
		if(ob->query_temp("have_yelled"))
		{
			command("pat "+ob->query("id"));
				return;
		}
		command("whisper "+ob->query("id")+" 你叫(yell)我一声大哥，我可以考虑帮助你。\n");
			return;
	}
	if(!ob->query_temp("have_yelled") )
	{
		if(ob->query("per")<25 )
		{
			command("ysis "+ob->query("id"));
			command("say 叫(yell)我一声大哥，我就给泥一点money......\n");
				return;
		}				
		command("kiss "+ob->query("id"));
		command("whisper "+ob->query("id")+" 叫(yell)我一声大哥，我会给泥一些money.....嘻嘻\n");
			return;	
	}
	command("lovelook "+ob->query("id"));
	command("whisper "+ob->query("id")+" 明天再来啊。\n");
}                                   

void do_kick(string arg)
{
	object ob=this_player();

	if(!arg || arg!=this_object()->query("id") )
	{
		command("xixi "+ob->query("id"));	
			return;
	}
	command("chat "+ob->query("name")+"这破人居然敢踢我!\n"); 
	command("kick "+ob->query("id"));
}

void kill_ob(object ob)
{
	switch(random(2)){
		case 0:
			command("knife "+ob->query("id"));
			break;
		case 1:
			command("killair "+ob->query("id"));
		}	
	command("bye "+ob->query("id"));
	ob->start_busy(3);
	command("down");
	command("up");
//	random_move();
	remove_killer(ob);
}

void accept_fight()
{
	object ob=this_player();
	object me=this_object();
	int obexp,myexp;

	obexp=ob->query("combat_exp");
	myexp=me->query("combat_exp");
	if( obexp>=myexp*1/2 )
	{
		command("shake "+ob->query("id"));
		switch(random(2)){
		case 0:
		command("taste "+ob->query("id"));
		break;
		case 1:
		command("heng "+ob->query("id"));
		break;
		}		
		return;
	}
	command("nod "+ob->query("id"));
	fight_ob(ob);
}

int do_yell(string arg)
{
	object ob=this_player();
	object obj;

	if(!arg || arg!="大哥" || ob->query("combat_exp")>=2000 )
		return notify_fail("你叫什么叫？\n");
	if(query("pills")<1)
		return notify_fail("张骥道：我今天都听烦了。。。。。\n");
	if(ob->query("gender")=="女性" )
	{
		if(ob->query_temp("have_yelled")==1 )
		{
			obj=new("/obj/money/silver");
			obj->move(ob);
			message_vision("$N甜甜地叫了张骥一声大哥，张骥无赖地掏出一锭银子给$N。\n",ob,ob);
			command("lovelook "+ob->query("id"));
			ob->add_temp("have_yelled",1);
				return 1; 
		} 
		if(ob->query_temp("have_yelled")==2 )
		{
			obj=new("/obj/money/coin");
			obj->move(ob);
			message_vision("$N甜甜地叫了张骥一声大哥，张骥很不高兴地掏出一纹钱给$N。\n",ob,ob);
			command("sigh");
			ob->add_temp("have_yelled",1);
				return 1;
		}
		if(ob->query_temp("have_yelled")==3 )
		{
			message_vision("$N甜甜地叫了张骥一声大哥。\n",ob);
			command("heng "+ob->query("id"));
			command("say 你是不是做机器人赚钱？你滚下去吧！\n");
			ob->move("/d/suzhou/shizx");
			ob->unconcious();
				return 1;
		}
		add("pills",-1);
		message_vision("$N羞涩地叫了张骥一声大哥。\n",ob);
		command("whisper "+ob->query("id")+"  我给你二两银子。\n");
		command("loveshoe "+ob->query("id"));
		ob->set_temp("have_yelled",1);
		obj=new("/obj/money/silver");
		obj->set_amount(2);
		obj->move(ob);
			return 1;
	}
	if(ob->query_temp("have_yelled")==1 )
	{
		obj=new("/obj/money/silver");
		obj->move(ob);
		message_vision("$N高兴地叫了张骥一声大哥。\n",ob);
		command("say 就再给你一两银子吧。。。。唉。。。\n");
		ob->add_temp("have_yelled",1);
			return 1;
	}
	if(ob->query_temp("have_yelled")==2 )
	{
		obj=new("/obj/money/coin");
		obj->move(ob);
		message_vision("$N高兴地叫了张骥一声大哥，张骥生气地掏出一纹钱给$N。\n",ob,ob);
		command("kick "+ob->query("id"));
		ob->add_temp("have_yelled",1);
			return 1;		
	}
	if(ob->query_temp("have_yelled")==3)
	{
		message_vision("$N高兴地叫了张骥一声大哥。\n",ob);
		command("smash "+ob->query("id"));
	 	command("say 你是不是做机器人赚钱？你滚下去吧！\n");
		ob->move("/d/suzhou/shizx");
		ob->unconcious();
			return 1;	
	}
	add("pills",-1);	
	message_vision("$N忍气吞声地叫了张骥一声大哥。\n",ob);
	command("say 好吧，就给你一点银子吧。\n");
	obj=new("/obj/money/silver");
	obj->move(ob);
	ob->set_temp("have_yelled",1);
		return 1; 
}

int accept_object(object who, object what)
{               
	int myage,right;

	myage=who->query("age");
       	right=11+myage;
        
 	if(userp(what) )
		return notify_fail("这东西我不敢要。pp\n");
        if(what->query("money_id") && what->value()==right 
&& (who->query_temp("water/status") || who->query_temp("bath/here") 
|| who->query_temp("watch/picture") ) )
	{
		who->delete_temp("bath/here");
		who->delete_temp("water/status");
		who->delete_temp("watch/picture");
		command("thank "+who->query("id"));
		return 1;
	}
	command("say 是你给我东东吗？谢谢了。");
	command("thank " + who->query("id") );
        destruct(what);
	        return 1;
}

int dest()
{
	command("down");
	destruct(this_object());
		return 1;
}	