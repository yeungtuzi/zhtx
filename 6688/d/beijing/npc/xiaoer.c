// xiaoer.c 小二

#include <ansi.h>
#include <localtime.h>


inherit NPC;

int ask_room(object who);
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
	set("inquiry",([
	  "上房":"本店有上房若干，一宿五两银子。",
	  "goodroom":"本店有上房若干，一宿五两银子。",
	  "上次的上房":(: ask_room :),
	  "latest goodroom":(: ask_room :),
		]));
	setup();
	carry_object("/obj/cloth")->wear();
}

void init()
{	
	object ob; 
	ob = this_player();
	::init();
	if( interactive(ob) && !is_fighting() ) {
			remove_call_out("greeting");
			call_out("greeting", 1, ob);
	}

}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
			say( "店小二笑咪咪地说道：这位" + RANK_D->query_respect(ob)
				+ "，进来吃碗面，歇歇腿吧。\n");
			break;
		case 1:
			say( "店小二用脖子上的毛巾抹了抹手，说道：这位" + RANK_D->query_respect(ob)
				+ "，请进请进。\n");
			break;
	}
      call_out("check",1);
}
void check()
{	int t;
	object room;
	mixed *local;
	local = localtime(time()*6);
        t = local[2] * 60 + local[1]; 
	room=load_object("/d/beijing/kedian1");
	
            if( t>100&&t<300)
	room->add("exits",([
	  "east":"/d/beijing/kedian2",
		]));

}
int accept_object(object who, object ob)
{	
	if(!who->query_temp("haveask"))        
	 {   if(ob->query("money_id") && ob->value() >=500)
              {
                tell_object(who, "小二一哈腰，说道：多谢您老，您请进。\n");
		who->set("haverest",1);
                who->set_temp("rent_paid",1);
                return 1;
              }
             return 0;
	 }
	else
	{ if(ob->query("money_id")&& ob->value() <10000)
	      return notify_fail("店小二说：“这。。。这似乎少了点。”\n");
	else 
	  {
	    say("店小二笑嘻嘻地说：“大爷您等着，我这就去替你查一查，您老上次住\n"+
	    "的上房有没有人住。”\n");
	     call_out("moveplayer",3);
	     return 1;
	   }
	}
	return 0;	
}
int ask_room(object who)
{	who=this_player();
	if(!who->query("haverest"))
	 return notify_fail("店小二上下大量了你几下，说道：“你老还没有在本号住过呢。”\n");
	say("店小二笑嘻嘻地说：“这可是特别服务啊，嘻嘻，您老是不是。。。是不是该打赏一些啊?\n");
	who->set_temp("haveask",1);
	return 1;
}
void moveplayer(object who)
{        object room;
	 who=this_player();
      	room=load_object("/d/beijing/kezhan5");
	say("店小二一合帐簿，说道：“大爷您真赶上了，那个房子正好没人住，我这就带您去。”\n");
	who->move(room);
	this_object()->move(room);
	say("店小二说道：“大爷您慢歇，我出去招呼客人了。”\n");
	command( "south");
	who->add_temp("haveask",-1);
	room->set("nobook",0);

}
