// mother.c
//by tlang

#include <ansi.h>
inherit NPC;

int accept_object(object who,object what);
string ask_tingqin();

void create()
{
	set_name("鸨母", ({ "mother" }) );
	set("gender", "女性" );
	set("age", 49);
	set("str", 10);
	set("per", 26);
	set("long", @LONG
    鸨母是个浓妆艳抹的中年女子，身材微胖，全身上下珠光宝气。
LONG
);
	set("combat_exp", 10);
	set("attitude", "friendly");

	set_skill("unarmed", 100);
	set_skill("parry", 50);

	set("chat_chance_combat", 15);
	set("chat_msg_combat", ({
		"鸨母说道：你当这里是什么地方，敢来这里骚扰？\n",
	}) );

	set("inquiry",([
	"听琴" : (: ask_tingqin :),
	"过夜" : ({
		(: command,"blush" :),
		(: command,"say 这种事情你应该给我钱，然后上楼找我们的姑娘。。。。" :),
		}),
	]));
	set("count",1);
	add("trigger",1);
	
	setup();
	
	carry_object("/d/cloud/obj/npc/lm_guard/color_cloth")->wear();
	carry_object("/obj/toy/poison_dust.c");
}

int accept_object(object who,object what)
{
	int myexp,myage,right;

	myexp=who->query("combat_exp");
	myage=who->query("age");
	right=myexp*1/100+myage*10;

	if(query("count")<1)
		return notify_fail("我们姑娘今天不接客人了。\n");
	if(who->query("gender")!="男性")
	{
		tell_object(who,RANK_D->query_respect(who)+"恐怕不适合上去吧。。。\n");
		return notify_fail("看来她不想收下你的东西。\n");
	}
	if(userp(what))
		return notify_fail("这东西我怎么敢要。。。。。\n");
	if(what->query("money_id") && what->value()>=right )
	{
	add("count",-1);
	command("say 哈哈，这位大爷请上楼。。。。。。我们院里最好\n的姑娘正在等你。。。\n");
	who->set_temp("sleep/mother",1);
	who->set_temp("up/allowed",1);
	destruct(what);
		return 1;
	}
	command("say 这点东西太少了吧。。。。\n");
		return notify_fail("看来她不想收下你的东西。\n");
}


string ask_tingqin()
{
	object obj;
	object ob=this_player();

	if(query("trigger")<1)
		return "今天我们姑娘不唱了。\n";
	switch (MONEY_D->player_pay(ob, 1000) )
        {
        case 0:
                return "穷光蛋，一边呆着去！\n";
        case 2:
                return "您的零钱不够了，银票又没人找得开。\n";
        default:
		add("trigger",-1);
		ob->set_temp("tingqin/mother",1);
                message_vision("$N从衣袋里拿出一些钱来交给老鸨。\n",ob);
                obj=new("/d/suzhou/npc/s_girl2");
		obj->move(environment(this_object()));
	              return "于是一个漂亮的女孩子应声而来。\n";
        }
}