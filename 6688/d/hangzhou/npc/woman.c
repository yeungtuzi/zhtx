//by tlang

#include <ansi.h>
inherit NPC;

void create()
{
	set_name(HIW"春游女子"NOR, ({ "a woman","woman"}) );
	set("gender", "女性" );
	set("age", 20+random(4));
        set("long",
		"这是一位到杭州旅游的女子。\n");
	set("combat_exp", random(2500)); 
	set("attitude", "friendly");
	set("rank_info/respect", "美女");
	set("pursuer", 1);
	set("chat_chance",2);
        set("chat_msg", ({
                "女子对同伴说道：“外子不知道又一个人到哪儿逛去了？”\n",
                "女子深深地叹了一口气。”\n",
		(: random_move :),
        }) );
	
	setup();
	add_money("silver",1);   
	carry_object(__DIR__"obj/girth3.c")->wear(); 
}

