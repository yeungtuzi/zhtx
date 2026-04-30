//mrfeng.c
//by dwolf
//97.11.9

#include <ansi.h>
inherit NPC;
string ask_me();

void create()
{
	set_name(GRN"苗人凤"NOR, ({ "miao renfeng","miao" }) );
	set("gender", "男性" );
	set("age", 53);
	set("title",RED"飞剑客"NOR);
	set("long", "他就是当代大侠苗人凤，也就是吹雪山庄的庄主，他看上去神色黯然。\n");

	set("combat_exp", 1000000);
	set("attitude", "peaceful");
	set("rank_info/respect", "大侠");    
	set("inquiry", ([
		"苗若兰" : "正是小女，你可知道她在哪儿？",
	]));
	set_skill("sword",100);
	set_skill("dodge",100);
	set_skill("chaos-steps",100);
	set_skill("fumo-jian",100);
	map_skill("dodge","chaos-steps");
	map_skill("sword","fumo-jian");

	setup();
	add_money("gold", 1);
	carry_object("/d/suzhou/npc/obj/gangjian")->wield();
	carry_object("/d/suzhou/npc/obj/cloth2")->wear();
}       

void init()
{       
        object ob; 
        ob = this_player();

        ::init();
        remove_call_out("greeting"); 
	call_out("greeting", 1, ob);    
	add_action("do_swear", "swear");
}

void greeting(object ob) 
{       
        if( !ob || environment(ob) != environment() ) return; 
	command("say 你找到这儿，可有小女的消息？\n");
}             

int accept_object(object who, object ob)
{
	
	object me=this_player();
	// 2026-04-30: unused variable commented out
	// object obj=ob;
	int my_exp; 
	
        if (!userp(ob) && (string)ob->query("id")=="yupei" 
&& me->query("mark/玉佩")) {
	    	if(!query("yl_trigger")) {
		say("多谢了，我想感谢你，带你去一个地方，但你得发誓(swear)不泄露秘密。\n");
		destruct(ob);
		my_exp=me->query("combat_exp");
		me->add("combat_exp", my_exp*1/10000);
		tell_object(me,"你办事成功，经验增加了。\n");
		set("yl_trigger", 1);
		me->delete("mark/玉佩");
		me->set_temp("marks/mimi",1);
              }
           else say("sigh\n");
		 return 1;
	}
	return 1;
}

/*  
int accept_fight(object me)
{
        command	("say 原来你是来这儿捣乱来的？");
        command("chat 各位，这位" + RANK_D->query_respect(me) + "想到吹雪山庄来捣乱，我就不客气了。\n"); 
        command("hehe");
        kill_ob(me);
        return 1;        
}              
*/
int do_swear(string arg)
{                 
	object ob,me;
	me = this_player();

	if( !arg || arg=="" || !me->query_temp("marks/mimi")) return 0;    

        if( arg=="守秘密"
	||  arg=="不泄露秘密") 
	{
		command("haha");
		message_vision(MAG"苗人凤不知怎么把$N弄得不见了。\n"NOR, me);
		me->move("/d/xueshan/llou2");
		tell_room("/d/xueshan/llou2", RED"$N忽然从天而降。\n"NOR,me); 
		me->delete_temp("marks/mimi");
		return 1;      
	}
}
                      

