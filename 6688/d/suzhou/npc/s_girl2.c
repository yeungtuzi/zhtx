// s_girl.c
//by tlang

#include <ansi.h>
inherit NPC;

void play_piano(object ob,int stage);
string ask_me_tq();
int dest();

string *play_msg=({
HIC"只见她轻轻弹了起来，琴声如怨如恕，让人感伤不已。\n"NOR,
HIC"然后她突然唱了起来：\n"NOR,
HIC"红尘多可笑，痴情最无聊，目空一切也好。\n"NOR,
HIC"。。。。。。。。\n"NOR,
HIC"天越高，心越小，不问因果有多少，任我逍遥。\n"NOR,
HIC"今天哭，明天笑，。。。。。。。。独自醉倒。\n"NOR,
HIC"。。。。。。。。。。。。。。。。。\n"NOR,
HIC"歌在唱，舞在跳，长夜漫漫不觉晓。。。。。。\n"NOR,
HIC"忽然她微微一笑，停止不唱，而琴声转而旋律优美，让人叹为观止。\n"NOR, 
HIC"。。。。。。。。。。。。。。。。\n"NOR,
HIC"听来似乎是高山流水。。。。。。。。\n"NOR,
HIC"良久，琴声渐渐歇了下来。。。。。\n"NOR,
});

void create()
{
	switch(random(3))
	{
		case 0:
		set_name("莲莲", ({ "lian lian","girl" }) );
		break;
		case 1:
		set_name("丽丽", ({ "li li","girl"}));
		break;
		case 2:
		set_name("香香",({"xiang xiang","girl"}));
		break;
	}
	set("title", "名妓");
	set("gender", "女性" );
	set("age", 22+random(5));
	set("str", 10);
	set("per", 23+random(7));
	set("long", @LONG
    	她可是院里的名妓，精通琴棋书画，周围的纨绔子弟们常往这
里钻。
LONG
);
	set("combat_exp", 10);
	set("attitude", "friendly");

        set_skill("literate", 50);
	set_skill("music",50);

	set("inquiry", ([
		"过夜": ({
			(: command,"blush" :),
			(: command,"say 我只给客人弹琴唱歌。\n" :),
		}),
		"嫖妓": ({
			(: command,"angry" :),
			(: command,"say 你怎么可以问我这样的问题？\n" :),
			(: command,"cry" :),
		}),
		"听琴" : (: ask_me_tq :),
	]) );

	setup();
	
	carry_object("/d/cloud/obj/npc/girl/pink_cloth")->wear();
}


string ask_me_tq()
{
	object me=this_object();
	object ob=this_player();
	
	if(!ob->query_temp("tingqin/mother"))
		return "你还没有给钱呢。。。。\n";
	me->start_busy(40);
	ob->start_busy(40);
	ob->add("shen",10);
	remove_call_out("play_piano");
	call_out("play_piano",1,ob,0);
	return "她点了点头，拿出一把琴，开始弹了起来。\n";	
}


void play_piano(object ob,int stage)
{
	tell_object(ob,play_msg[stage]);
	if(++stage<sizeof(play_msg) )
	{
	call_out("play_piano",5,ob,stage);
		return;
	}
	ob->set("eff_gin",ob->query("max_gin"));
	ob->set("gin",ob->query("max_gin"));
	ob->set("eff_sen",ob->query("max_sen"));
	ob->set("sen",ob->query("max_sen"));
	command("say 好些了吗？\n");
	tell_object(ob,"官人，今天就到这儿吧。。。。。\n");
	if(ob->query_temp("tingqin/mother") )
	ob->delete_temp("tingqin/mother");
	call_out("dest",1);
		return;
}

int dest()
{
	command("say 我走了。\n");
	destruct(this_object());
	return 1;
}


