//by tlang

#include <ansi.h>
inherit NPC;

string ask_xiaolin();
string ask_lucy();

string *story_msg=({
HIC"几年前，我在苏州城外碰见一个女孩子，我见她失魂落魄的，就忍不住\n"NOR,
HIC"跟着想看看发生了什么事情。结果她出了北门，站在运河边，看样子是要\n"NOR,
HIC"寻死。我正要上去劝止她，突然出来几个流氓，嘻嘻哈哈地上去调戏她。\n"NOR,
HIC"正在这时候，一个少年出现了，一挥手就把几个流氓扫进运河中。少女受\n"NOR,
HIC"到惊吓后，暂时也不想死了。我上去和他们搭话，才知道那少女叫露露，\n"NOR,
HIC"被男朋友抛弃了，所以想要自杀。多亏了那少年，你猜他是谁，正是我现\n"NOR,
HIC"在的结拜兄弟小霖，他原来是大仙，于是施展法力把少女的记忆封闭起来\n"NOR,
HIC"，交给我找了一个地方保护起来。后来小霖有了未婚妻，才由他们保护起来\n"NOR,
HIC"。我们一直在等那个负心的小子来找她，唉，几年过去了。。。。。这希\n"NOR,
HIC"望可能太小了。\n"NOR,
});

void create()
{
	set_name(MAG"紫袍老人"NOR, ({ "old guy","man","guy"}) );
	set("gender", "男性" );
	set("age", 64);
        set("long","一位看上去让人琢磨不透的老人。\n");
	set("combat_exp", 1000000);
	set("attitude", "friendly");
	set("pursuer", 1);
	set("chat_chance",2);
        set("chat_msg", ({
                "老人笑道：“老夫生平最喜欢与人牵线搭桥！”\n",
		"老人恨恨道：“老夫生平最恨负心薄情的人。”\n",
                "老人自负地微笑道：“在这杭州城内，没有谁感对老夫说过不字。”\n",
        }) );
	set_skill("dodge",200);
	set_skill("move",200);
	set_skill("unarmed",200);
	set_skill("parry",200);	

	set("inquiry",([
	"小霖" : (: ask_xiaolin :),
	"xiaolin" : (: ask_xiaolin :),
	"露露" : (: ask_lucy :),
	"lucy" : (: ask_lucy :),
	]));

	setup();
	carry_object(__DIR__"obj/girth2.c")->wear(); 
}

string ask_xiaolin()
{
	object ob=this_player();
	object me=this_object();

	if(me->is_busy() )
		return "我现在没有空。\n";
	if(ob->is_busy() )
		return "你先忙完了再来问吧。\n";
	if(!ob->query_temp("save_lucy/xiaolin")
 || !ob->query_temp("save_lucy/lucy"))
	{
		command("haha "+ob->query("id"));
		return "小霖是老夫的结拜兄弟，你问这个干什么？\n";
	}
	ob->set_temp("save_lucy/oldguy",1);
	command("sigh");
	command("tell "+ob->query("id")+" 我们等的人终于到了，你回去告诉
我的小霖兄弟，让他带你去见露露姑娘。\n");
	return "露露这个苦命的孩子终于有救了！\n";
}

string ask_lucy()
{
	object ob=this_player();
	object me=this_object();

	if(me->is_busy() )
		return "我现在没有空。\n";
	if(ob->is_busy() )
		return "你先忙完了再来问吧。\n";
	if(ob->query_temp("save_lucy/lucy") )
		return "我已经给你说过关于露露的故事了，你还问什么？！\n";
	remove_call_out("tell_story");
	call_out("tell_story",1,ob,0);
		return "老人张口说出一个让人心酸的故事来。\n";
}

void tell_story(object ob,int stage)
{
	tell_object(ob,story_msg[stage]);
	if(++stage<sizeof(story_msg) )
	{
	call_out("tell_story",2,ob,stage);
		return;
	}
	ob->set_temp("save_lucy/lucy",1);
	command("sigh");	
}
