// yaow.c 
//by dwolf

#include <ansi.h>
inherit NPC;

string ask_for_per();
string ask_for_con();
void do_opration(object ob, int stage);

string *make_msg = ({
 	HIW"想做手术？好呀。--------哈哈。\n"NOR,	
	HIW"只见药王变戏法般的拿出一套工具，让你躺在一张石桌上，\n"NOR,
	YEL"手术开始了。\n"NOR,
	HIW"模模糊糊中，也不知道过了多久。。。。。。\n"NOR,
	HIM"只听的药王说道：行了。你才惊醒过来，发现自己的资质已经变了。\n"NOR,
});

void create()
{
        set_name(HIW"药王"NOR, ({ "yao wang", "wang" }));
        set("title", GRN"药王谷主"NOR);
        set("gender", "男性");
        set("long", "他就是医术高超的药王。看上去挺健康的。\n");
        set("age", 55+random(20));

        set("int", 30);

        set("kee", 1500);
        set("max_kee", 1500);
        set("gin", 1000);
        set("max_gin", 1000);
        set("shen_type", 5);

        set("combat_exp", 500000);
        set("attitude", "friendly");

        set_skill("unarmed", 80);
        set_skill("dodge", 80);
        set_skill("parry", 60);
        set_temp("apply/attack", 70);
        set_temp("apply/defense", 70);
        set_temp("apply/damage", 50);   
	set("inquiry", ([
		"美容" : (: ask_for_per :),
		"per" : (: ask_for_per :),
		"健美" : (: ask_for_con :),
		"con" : (: ask_for_con :),
	]));																																																								
     
	setup();
        add_money("gold", 1);
	carry_object("/d/huashan/obj/baishan")->wear();
}           

string ask_for_per()
{     
	object ob=this_player();
  
	if( ob->query("marks/fairy")==3)
		return "你不仅做过手术，而且已经恢复过经验，还来干什么？\n";
	if( ob->query("marks/手术") ) 
		return "老夫不能为你做两次手术。\n";
        if( ob->query("combat_exp") < 15000)
                 return "你体质太弱了，先去练练功夫吧\n";
       	ob->start_busy(20);
	remove_call_out("do_opration");
	call_out("do_opration",1,ob,0);
	ob->add("combat_exp", -10000);
	ob->add("per", 1); 
	ob->set("marks/手术", 1);
	ob->set("marks/per",1);
	command("haha"); 
		return YEL"药王笑着看着你。\n"NOR;
}
   
string ask_for_con()
{       
	object ob=this_player();

	if( ob->query("marks/fairy")==3)
		return "你不仅做过手术，而且已经恢复过经验，还来干什么？\n";
        if( ob->query("marks/手术") ) 
		return "老夫不能为你做两次手术。\n";
        if( ob->query("combat_exp") < 15000)
                 return "你体质太弱了，先去练练功夫吧\n";
	ob->start_busy(20);
	remove_call_out("do_opration");
	call_out("do_opration",1,ob,0);
	ob->add("combat_exp", -15000);
	ob->add("con", 1); 
	ob->set("marks/手术",1);
	ob->set("marks/con",1);
		return YEL"药王笑着看着你。\n"NOR;
}

void do_opration(object ob, int stage)
{
	tell_object(ob, make_msg[stage]);
	if( ++stage < sizeof(make_msg) )
	{
	call_out("do_opration", 5, ob, stage );
        	return;
	} 
	ob->start_busy(5);
}
	
