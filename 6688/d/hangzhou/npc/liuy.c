//NPC:/d/suzhou/npc/liuy.c 
//by dwolf   
//97.11.4

#include <ansi.h>
inherit NPC;           

void create()
{
	set_name(HIM"柳永"NOR, ({ "liu yong", "liu"}) );
	set("gender", "男性" );
	set("age", 28);
        set("long",
		"这是一位相当富有才气的年青人，穿得不错，正在这儿抒情。\n");
	
	set("per", 30);
	set("int", 30);  
	set("str", 20);

	set("combat_exp", 10000);
	set("attitude", "friendly");
	set("pursuer", 1);      

	set("chat_chance",2);
        set("chat_msg", ({
                YEL"寒蝉凄切，对长亭晚－－－－。\n"NOR,
                RED"今霄酒醒何处，杨柳岸晓风残月－－－－\n"NOR,
               
        }) );
	
	setup();
	add_money("silver",5);   
	carry_object("/d/suzhou/npc/obj/cloth2.c")->wear();
}

