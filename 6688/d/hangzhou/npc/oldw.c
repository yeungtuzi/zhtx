//by tlang

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("老妇人", ({ "old woman","woman"}) );
	set("age", 65+random(4));
	set("gender","女性");
        set("long","这是一位到杭州旅游的老妇人。\n");

	set("attitude", "friendly");

	set("chat_chance",2);
        set("chat_msg", ({
               	(: random_move :),
        }) );
	
	setup();
	add_money("coin",100);   
	carry_object(__DIR__"obj/cloth.c")->wear(); 
}

