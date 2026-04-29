//NPC:/d/suzhou/npc/xiaoer2.c 
//by dwolf
//97.117

#include <ansi.h>
inherit NPC;
//inherit F_UNIQUE;

int do_clone();

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
	set_name("店小二", ({ "xiao er", "xiao", "waiter" }) );
        set("gender", "男性" );
	set("age", 22);
	set("long",
		"这位店小二正笑咪咪地忙著，还不时拿起挂在脖子上的抹布擦脸。\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("rank_info/respect", "小二哥");
	setup();
	carry_object("/d/hangzhou/npc/obj/cloth")->wear();
//blocked by tlang for not finished
//	call_out("do_clone",5);
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(3) ) {
		case 0:
			say( "店小二笑咪咪地说道：这位" + RANK_D->query_respect(ob)
				+ "，进来住一宿，歇歇腿吧。\n");
			break;
		case 1:
			say( "店小二用脖子上的毛巾抹了抹手，说道：这位" + RANK_D->query_respect(ob)
				+ "，请进请进。\n");
			break; 
                case 2:
			say( "店小二点头哈腰，往后面一指说道：这位" + RANK_D->query_respect(ob)
				+ "，后院有雅房，请。\n");
			break;
	}
}

int do_clone()
{
	object obj,me;
	string startroom;

	me=this_object();
	obj=new("class/guard/npc/poisoner");
	startroom = start_loc[random(sizeof(start_loc))];  
	obj->move(startroom);
//	obj->move(environment(me));
	if(present("wen shen",environment(me) ) )
	{
		command("chat 瘟神又出来了！唉！\n");
			return 1;
	}	
	command("chat 唉，瘟神还在世界上游荡。\n");
		return 1;  
}

int accept_object(object who, object ob)
{
	
    if(ob->query("money_id") && ob->value() >=500)
	{
		tell_object(who, "小二一哈腰，说道：多谢您老，您请进。\n");

		who->set_temp("rent_paid",1);

		return 1;
	}

	return 0;
}


