//by tlang

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("游人", ({ "you ren","ren","traveler"}) );
	set("gender", "男性" );
	set("age", 34+random(6));
        set("long",
		"这是一位到杭州旅游的男子。\n");
	set("combat_exp", random(5000));
	set("attitude", "friendly");
	set("rank_info/respect", "公子");
	set("pursuer", 1);
	set("chat_chance",2);
        set("chat_msg", ({
                "游人笑道：“早就想来杭州旅游了！”\n",
                "游人微微一笑：“随便买点东西给内子带回去。”\n",
		(: random_move :),
        }) );
	
	setup();
	add_money("silver",3);   
	carry_object(__DIR__"obj/girth2.c")->wear(); 
}

