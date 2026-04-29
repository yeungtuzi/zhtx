//by tlang

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("渔家少女", ({ "fish girl","girl"}) );
	set("age", 15+random(4));
        set("long","这是一位住在西湖乡的打鱼少女，看样子刚送了鱼进城。\n");
	set("gender","男性");
	set("attitude", "friendly");
	
	set("combat_exp",3000);
       	
	setup();
	add_money("coin",500);   
	carry_object(__DIR__"obj/cloth.c")->wear(); 
}

