//by tlang

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("老人", ({ "old man","man"}) );
	set("age", 65+random(4));
	set("gender","男性");
        set("long","这是一位到杭州旅游的老人。\n");

	set("attitude", "friendly");
	set("combat_exp",10000);

	set("chat_chance",2);
        set("chat_msg", ({
               	(: random_move :),
        }) );
	
	setup();
	add_money("coin",500);   
	carry_object(__DIR__"obj/girth2.c")->wear(); 
}

