// write by qqqqq
#include <ansi.h>
inherit NPC;

string give_tang();

void create()
{
        set_name("孟婆", ({ "mengpo", "woman" }) );
        set("title", "阴间百姓");
        set("gender", "女性");
        set("long", "她在奈何桥上卖汤已经有很长时间了,\n过桥的人都要先到她这来喝碗孟婆汤。\n");
        set("age", 200);
        set("attitude", "friendly");
        set("combat_exp", 1);
        set("env/wimpy", 100);
        set("chat_chance", 15);
        set("chat_msg", ({
                RANK_D->query_respect(this_player()) + "喝碗汤再走吧!\n" ,
                "新鲜的汤啊，快来喝碗汤吧.\n",
		"过去的事情就让它过去吧！\n",
        }) );
        set("inquiry",([
                "投胎": "过了奈何桥就可以投胎转世了。",
                "还阳": "既然上了奈何桥，还怎能还阳？",
                "孟婆汤": (: give_tang :),
        ]) );
        setup();
}

void init() {

	add_action("do_nod","nod");


}

string give_tang()
{
        object sb,one_tang;
        sb = this_player();
        if(!sb->query_temp("mengpo_gived"))
        {
	command("say 你真的肯忘记过去的恩怨了吗？如果你真的想忘记过去就点一下头吧。");
	sb->set_temp("mengpo_asked", 1);
        }
        else return "不是已经给过你一碗了吗？\n";
}

int do_nod() {
        object sb,one_tang;
        sb = this_player();
        one_tang = new(__DIR__"obj/tang.c");
	if (!sb->query_temp("mengpo_asked")) return 0; 
	sb->delete_temp("mengpo_asked");
	if(!sb->query_temp("mengpo_gived")) {
		command("sigh ");
                if(one_tang->move(sb)){
                        message_vision("$N给了$n一碗孟婆汤。\n",this_object(),sb);
                        sb->set_temp("mengpo_gived", 1);
                        command("say 这碗汤你就拿去趁热喝了吧。");
                }
		return 1;
	}	
	return 0;
}
