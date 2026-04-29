//by tlang

#include <ansi.h>
inherit NPC;           

void create()
{
	set_name(HIC"刘禹锡"NOR, ({ "liu yuxi", "liu"}) );
	set("gender", "男性" );
	set("age", 28);
        set("long",
		"这是一位相当富有才气的年青人，穿得不错，正在这儿抒情。\n");
	
	set("per", 24);
	set("int", 30);  
	set("str", 20);

	set("combat_exp", 20000);
	set("attitude", "friendly");
	set("pursuer", 1);      

	set("chat_chance",2);
        set("chat_msg", ({
                "月落乌啼霜满天，江枫渔火对愁眠。\n",
                "姑苏城外寒山寺，夜半钟声到客船。\n",
               
        }) );
	
	setup();
	add_money("silver",5);   
	carry_object("/d/suzhou/npc/obj/baishan.c")->wear();
}

