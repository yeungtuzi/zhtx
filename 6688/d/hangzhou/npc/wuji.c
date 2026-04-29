//NPC:/d/hangzhou/npc/wuji.c 
//by dwolf   
//97.11.4

#include <ansi.h>
inherit NPC;

void create()
{
	set_name(GRN"舞姬"NOR, ({ "wu ji", "girl"}) );
	set("gender", "女性" );
	set("age", 18);
        set("long",
		"这是一位采藕的小女孩，正愉快地唱着歌。\n");
	set("combat_exp", 200);
	set("attitude", "friendly");  
	set("per", 30);
	set("rank_info/respect", "美女");
	set("pursuer", 1);
	set("chat_chance",2);
        set("chat_msg", ({
             "女孩看着你，笑道：“能把你的鱼给我么？”\n",
        }) );
	
	setup();
	add_money("silver",1);   
	carry_object("/d/suzhou/npc/obj/cloth2.c")->wear();
}     

int accept_object(object me, object what)
{                                 
        if( !me->query("mark/fish") ) return 0;
    	command("xixi");
        command("tell "+me->query("id")+" 你真是个好人，我告诉你一个秘密：\n
	问过那边的小霖后去雪山找胡斐，有希望恢复做手术掉的经验喔。\n");  
	me->delete("mark/fish");
	me->set("marks/wuji",1);
        remove_call_out("dest");
        call_out("dest", 1, what);
        return 1;                   
}

void dest(object ob)
{
        destruct(ob);
}   
                                   

