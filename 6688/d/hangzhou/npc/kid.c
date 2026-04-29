//by tlang

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("小孩", ({ "kid","xiao hai"}) );
	set("age", 5+random(4));
        set("long","这是一位到杭州旅游的小孩。\n");

	set("attitude", "friendly");

	set("chat_chance",2);
        set("chat_msg", ({
               	(: random_move :),
        }) );
	
	setup();
	add_money("coin",10);   
	carry_object(__DIR__"obj/cloth.c")->wear(); 
}

