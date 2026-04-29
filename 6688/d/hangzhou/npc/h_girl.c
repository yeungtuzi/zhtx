//by tlang

#include <ansi.h>
inherit NPC;

void create()
{
	set_name(HIM"春游女孩"NOR, ({ "little girl","girl"}) );
	set("gender", "女性" );
	set("age", 14+random(4));
        set("long",
		"这是一位到杭州旅游的女孩。\n");
	set("combat_exp", random(250));
	set("attitude", "friendly");
	set("rank_info/respect", "美女");
	set("pursuer", 1);
	set("chat_chance",2);
        set("chat_msg", ({
                "女孩对同伴说道：“春游的时候最好带上点饮料！”\n",
                "女孩看着你，笑道：“你是来游西湖的么？”\n",
		(: random_move :),
        }) );
	
	setup();
	add_money("silver",1);   
	carry_object(__DIR__"obj/girth.c")->wear(); 
}

