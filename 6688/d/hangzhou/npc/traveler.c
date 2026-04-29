//by tlang
         
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("观光客", ({ "traveler", "man"}) );

	set("long","一边外地来的观光客。\n");
	set("combat_exp", 10000);

	set("attitude", "friendly");

	set_skill("dodge",50+random(40));
	set_skill("parry",50+random(40));
	set_skill("finger",50+random(40));
	set_skill("nianhua-zhi",60);
	map_skill("parry","nianhua-zhi");
	map_skill("finger","nianhua-zhi");
	
	setup();
	add_money("gold",1);
	carry_object("/d/hangzhou/npc/obj/girth2")->wear();
}


