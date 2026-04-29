// s_girl.c
//by tlang

#include <ansi.h>
inherit NPC;

void sleep_here(object ob,int stage);
void play_piano(object ob,int stage);
string ask_me_tq();
string ask_me_gy();
string ask_me_pj();

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

string *sleep_msg=({
	MAG"只见她轻轻地为你斟上一杯三十年陈的女儿红，\n\n"NOR,
	MAG"然后她叫你闭上眼睛，一会儿你睁眼看时，只见。。。\n\n"NOR,
	YEL"她穿着件宽大而舒适的鲜红衣裳，秀发松松地挽起，\n\n"NOR,
	YEL"露出一双晶莹修长的玉腿，赤着纤秀的，完美无缺的双足\n\n"NOR,
	YEL"，轻轻走到你的身边，面上绽开了甜蜜妩媚的微笑，\n\n"NOR,
	YEL"就好象百花俱在这一刻开放。。。。。。。\n\n"NOR,
	HIW"你不由得呆了，看着你的傻样，她眼波流动，脉脉含情，\n\n"NOR,
	HIW"若说世界上有一种女子的脸能使男子停止呼吸，那么就是这女子的脸了；\n\n"NOR,
	HIW"若说世界上有一种女子的眼波能让男子的心跳停止，那么就是这女子的眼波了。\n\n"NOR,
	HIM"在恍惚中，你好象觉得有一个软玉似的身体扑进你的怀里，\n\n"NOR,
	HIM"就这样你被迷迷糊糊地带到床上。。。。。。\n\n"NOR,
	"					\n\n",
	"					\n\n",
	HIC"良久，你从昏睡中醒过来，只见她已经穿好了衣服，\n\n"NOR,
	HIC"俏生生地站在床前，见你醒来，他服侍你穿好衣服，\n\n"NOR,
	HIC"然后你们又喝了一会儿茶，调笑了一会儿。。。。\n\n"NOR,
	HIC"时间不早了，你得走了。。。。。\n\n"NOR,
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
		"过夜": (: ask_me_gy :),
		"嫖妓": (: ask_me_pj :),
		"听琴" : (: ask_me_tq :),
	]) );

	setup();
	
	carry_object("/d/cloud/obj/npc/girl/pink_cloth")->wear();
}


string ask_me_tq()
{
	object me=this_object();
	object ob=this_player();
	
	if(!ob->query_temp("sleep/mother"))
		return "你还没有给钱呢。。。。\n";
	me->start_busy(40);
	ob->start_busy(40);
	ob->add("shen",10);
	remove_call_out("play_piano");
	call_out("play_piano",1,ob,0);
	return "她点了点头，拿出一把琴，开始弹了起来。\n";	
}

string ask_me_gy()
{
	object me=this_player();
	object ob=this_player();
	int ob_sen,ob_gin;

	ob_sen=ob->query("max_sen")*9/10;
	ob_gin=ob->query("max_gin")*9/10;

	if(ob->query("gender")!="男性")
		return "你问这个干嘛？\n";

	if(!ob->query_temp("sleep/mother"))
	{
		command("? "+ob->query("id"));
		return "官人难道不知道规矩么？\n";
	}
	if(ob->query("sen")<ob_sen || ob->query("gin")<ob_gin)
	{
		tell_object(ob,"官人精神不好，待妾身为你奏上一曲。\n");
		ob->start_busy(50);
		remove_call_out("play_piano");
		call_out("play_piano",1,ob,0);
		return "说罢抄起一把琴弹了起来。\n";
	}
	command("lovelook "+ob->query("id"));
	call_out("sleep_here",1,ob,0);
	me->start_busy(40);
	ob->start_busy(40);
		return "官人你真可爱！\n";
}

string ask_me_pj()
{
	object ob=this_player();
	

	if(ob->query("gender")!="男性")
		return "你问这个干嘛？\n";
	if(!ob->query_temp("sleep/mother"))
	{
		command("angry "+ob->query("id"));
		return "你怎么这么粗俗？！\n";
	}
	command("kick "+ob->query("name"));
	message_vision("$N生气地把$n踢到了街口。\n",this_object(),ob);
	ob->move("/d/suzhou/xxiang6");
	return "你怎么这么粗俗？！\n";
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
	if(ob->query_temp("sleep/mother") )
	ob->delete_temp("sleep/mother");
		return;
}


void sleep_here(object ob,int stage)
{
	int ob_gin;int ob_sen;

	ob_gin=ob->query("gin");
	ob_sen=ob->query("sen");

	tell_object(ob,sleep_msg[stage]);
	if( ++stage < sizeof(sleep_msg) )
        {
        call_out("sleep_here", 5, ob, stage );
                return;
        }
	ob->add("shen",-10);
	ob->receive_damage("sen",ob_sen*9/10);
	ob->receive_damage("gin",ob_gin*9/10);
	ob->add("combat_exp",5);
	ob->add("potential",-5);
	command("bye "+ob->query("id"));
	if(ob->query_temp("sleep/mother"))
	ob->delete_temp("sleep/mother");
		return;
}