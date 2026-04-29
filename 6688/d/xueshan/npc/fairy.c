//magic fairy
//by tlang for recovering exp 
 
#include <ansi.h>

inherit NPC;

int do_regret(string arg);
//void checking();
//int do_celebration();
             
void create()   
{
	set_name(MAG"警幻仙子"NOR, ({"magic fairy", "fairy"}));
        set("gender", "女性");
	set("long", "幻亦是真，真亦是幻，幻不是真，真不是幻。似幻似真，似真似幻.是真是幻，仙子示之。\n");
        set("age", 20);
	set("per", 50);
	set("cps", 500);
	set("max_kee",3000);
	set("max_gin",1000);
	set("max_sen",1000);
	set("combat_exp", 29999999);
	set_skill("dodge",250);
	set_skill("literate",200);

	setup();
	carry_object("/d/xueshan/npc/obj/fcloth")->wear();
}

void init()
{       
        object ob=this_player();

        ::init();
        remove_call_out("greeting"); 
        call_out("greeting", 1, ob);    
        add_action("do_regret", "regret");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment()) return;
	if(!ob->query("marks/fairy") || ob->query("marks/fairy")!=2 )
	{
		command("? "+ob->query("id"));
			return;
	}
	command("smile "+ob->query("id"));
        command("say 你找到这儿，是有什么后悔(regret)的事吗？\n"); 
}

int do_regret(string arg)
{                 
        object ob,me;
        ob=this_player();
	me=this_object();

       	if( arg=="美容" || arg=="健美")
	{
		if(!ob->query("marks/fairy") || ob->query("marks/fairy")!=2 )
		{
		command("heng "+ob->query("id"));
		command("say 你到这儿来干什么？\n");
		ob->unconcious();	
		//ob->move("/d/suzhou/shizx");
			return notify_fail("你竟然敢骗我？有罪给你受的！！！\n");
		}
		if( arg=="美容" )
		{
		if(!ob->query("marks/per") ) 
        	{               
			command("waggle "+ob->query("id"));
				return notify_fail("你不要搞错了喔。。。\n");
		}              	
                command("sigh");
                command("say 药王这小子又随便给人美容了，来，我给你加上经验吧。\n");
                 // ob->add("combat_exp", 10000);
                message_vision("只见一团亮光包住$N,然后只听见仙子说:道行了，光消失了。\n",ob);
              	ob->delete("marks/per");
		ob->set("marks/fairy",3);
			return 1;
		}
		if( arg=="健美" ) 
		{
		if(!ob->query("marks/con") ) 
        	{
			command("waggle "+ob->query("id"));   
				return notify_fail("你不要搞错了喔。。。\n");
		}                          	
                command("sigh");
                command("say 药王这小子又随便给人健美了，来，我给你加上经验吧。\n");
      //          ob->add("combat_exp", 15000);
                message_vision("只见一团亮光包住$N,然后只听见仙子说道:行了，光消失了.\n",ob);
                ob->delete("marks/con");
		ob->set("marks/fairy",3);
			return 1;
		}
		return 1;
	}
	command("pat "+ob->query("id"));
	command("say 不要这么紧张嘛！\n");		
 		return notify_fail("说罢嫣然一笑。\n");
}
                   
int accept_fight()
{       
	command("shake "+this_player()->query("id"));
	call_out("do_halt",2);
		return 1;            
}

int do_halt()
{
	command("halt");
	command("sigh");
}      

int accept_object(object who, object what)
{                              
        command("say 是你给我东东吗？谢谢了。");
        command("thank " + who->query("id") );
        destruct(what);
	        return 1;
}

void kill_ob(object ob)
{
	command("kick "+ob->query("id"));
	command("say 你竟然感到天堂来捣乱。死罪可免，活罪难饶。\n");
	ob->unconcious();
	remove_killer(ob);
}

//from here is for celebrating birthday,just for 20 years old.
/*void checking()
{
	object *ob,theob,env,obj;
        int i;
	
	command("lovelook");
	ob = users();
	if( query("being_celebrating") ) 
	{
		command("sigh");
		return;
	}
	for(i=0; i<sizeof(ob); i++) {
		if( !environment(ob[i]) ) continue;
		if( ob[i]->query("age")!=20 ) continue;
		if( ob[i]->query_temp("been_celebrated") ) continue;
		command("love");
		theob=ob[i];
		env=environment(theob);
		tell_object(theob, YEL "你的二十岁生日到了，赶快准备，\n
然后等着我送你到西湖三雅园去。\n\n" NOR);
		theob->set("celebrating", 1);
		theob->save();
		set("being_celebrating",1);
		command("chat 有人过生日！大家有兴趣的可去杭州三雅园。\n");
		call_out("do_celebration",20);
	}
	obj=new("/d/xueshan/npc/fairy2");
	obj->move("/d/hangzhou/syyuan2");
	call_out("checking", 600);
}


int do_celebration()
{
	object *ob,theob;
	int i;

	command("smile");
	ob = users();
	for(i=0; i<sizeof(ob); i++) {
		if( !environment(ob[i]) ) continue;
		if( ob[i]->query("age")!=20 ) continue;
		if( ob[i]->query_temp("been_celebrated") ) continue;
		if( !ob[i]->query("celebrating")) continue;
		theob->set_temp("been_celebrated", 1);
		delete("being_celebrating");
		command("smile");
		theob=ob[i];
		theob->move("/d/hangzhou/syyuan2");
	}
}
*/
	
