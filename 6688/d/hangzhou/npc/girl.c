//NPC:/d/suzhou/npc/girl.c 
//by dwolf   
//97.11.4

#include <ansi.h>
inherit NPC;

void create()
{
	set_name(YEL"浣纱女孩"NOR, ({ "girl"}) );
	set("gender", "女性" );
	set("age", 18);
        set("long",
		"这是一位在西湖边长大的女孩，正微笑着和同伴浣纱，说笑。\n");
	set("combat_exp", 200);
	set("attitude", "friendly");
	set("rank_info/respect", "美女");
	set("pursuer", 1);
	set("chat_chance",2);
        set("chat_msg", ({
                "女孩对同伴说道：“听说西施当年也在这儿浣纱喔！”\n",
                "女孩看着你，笑道：“你是来游西湖的么？”\n",
        }) );
	
	setup();
	add_money("silver",1);   
	carry_object(__DIR__"obj/cloth.c")->wear(); 
	carry_object(__DIR__"obj/sha");
}

