//by tlang

#include <ansi.h>
inherit NPC;

string ask_hill();
string ask_monk();
void open_road();
void close_road();

void create()
{
	set_name("济公和尚", ({ "ji gong","monk"}) );
	set("age", 25+random(4));
        set("long","这是脏脏地，疯疯癫癫的和尚。\n");

	set("attitude", "friendly");
    	set("rank_info/respect", "圣僧");


	set("inquiry",([
	"飞来峰" : (: ask_hill :),
	"hill" : (: ask_hill :),
	"名字" : ({
		(: command,"xixi" :),
		"贫僧无名无姓，人称济公。\n",
		}),
	"name" : ({
		(: command,"xixi" :),
		"贫僧无名无姓，人称济公。\n",
		}),
	"济公" : (: ask_monk :),
	"jigong" : (: ask_monk :),
	]));
	set("count",1);
		
       set("no_get",1);
	setup();
	add_money("silver",1);   
	carry_object(__DIR__"obj/cloth.c")->wear(); 
}

string ask_hill()
{
	object ob=this_player();
	
	tell_object(ob,"你想上这山峰？那还不容易，看我的。。。。。\n");
	remove_call_out("open_road");
	call_out("open_road",1);
		return "只见济公把手中的破扇子一晃，一条通向峰顶道路出现了。\n";
}

string ask_monk()
{
	object obj;
	object ob=this_player();

	if(ob->query_temp("marks/jigong") || query("count")<1)
		return "今天好象有人找我打听过了。。。。\n";
	ob->set_temp("marks/jigong",1);
	add("count",-1);
	command("haha");
	command("say 我之所以叫这个名字，就是因为我爱帮助人。。。。。\n");
	tell_object(ob,"说完后给了你一两银子。\n");
	obj=new("/obj/money/silver");
	obj->move(ob);
		return "有困难你可以来找我。。。\n";
}

void init()
{
	object ob=this_player();

	remove_call_out("greeting");
	call_out("greeting",1,ob);
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) 
		return;
	command("xixi "+ob->query("id"));
}

void open_road()
{
	object me=this_object();

        environment(me)->set("exits/up","/d/hangzhou/h_flf2");
        command("say 上去吧。。。。。\n");
	remove_call_out("close_road");
	call_out("close_road",10);
}

void close_road()
{
	object room;

	room=environment(this_object());
        room->delete("exits/up");
	message("vision", "路自动合上了。\n", room);
}
