//by tlang

#include <ansi.h>
inherit NPC;

string ask_moon();

void create()
{
	set_name("道可道", ({ "dao dao","dao"}) );
	set("title","无中生有");
	set("gender", "男性" );
	set("age", random(80));
        set("long","纵横天下的天神，被小霖拖下了凡，无奈整天只好呆在西湖。\n");
	set("combat_exp", 200000+random(50000));
	set("attitude", "peaceful");
	set("chat_chance",10);
        set("chat_msg", ({
                (: command,"smile" :),
		(: command,"say disc,你什么时候出国？\n" : ),
        }) );

	set("inquiry",([
	"平湖秋月" : (: ask_moon :),
	"moon" : (: ask_moon :),
	"小霖" : ({
		(: command,"smile" :),
		(: command,"say 就是他把我拖下凡的，害得我都不好惩罚温暖了。\n" :),
		}),
	"xiaolin" : ({
		(: command,"smile" :),
		(: command,"say 就是他把我拖下凡的，害得我都不好惩罚温暖了。\n" :),
		}),
	"游戏人生" : ({
		(: command,"say 他和我同为这个站的天神，可惜他要出国了。\n" : ),
		(: command,"sigh" :),
		}),
	"disc" : ({
		(: command,"say 他和我同为这个站的天神，可惜他要出国了。\n" : ),
		(: command,"sigh" :),
		}),
	"温暖" : ({
		(: command,"?" :),
		(: command,"say 没听说过......�\n" :)
		}),
	"wennuan" : ({
		(: command,"?" :),
		(: command,"say 这是谁的名字？\n" :)
		}),
	"wwwl" : ({
		(: command,"heng" :),
		(: command,"say 她竟然敢偷偷下凡，我们总有一天要抓她回去。\n" :)
		}),
	]));
	
        set_skill("unarmed", 220);
        set_skill("throwing", 300);
        set_skill("dodge", 200);
        set_skill("force", 230);
        set_skill("literate", 20);

	set_skill("qidaoforce", 200);
        set_skill("meihua-shou", 200);
        set_skill("fall-steps", 200);
        map_skill("unarmed", "meihua-shou");
        map_skill("dodge", "fall-steps");

	setup();
	add_money("gold",2);   
	carry_object("/d/suzhou/npc/obj/baishan.c")->wear(); 
	carry_object("/d/hangzhou/npc/obj/bqi")->wield();
}

string ask_moon()
{
	object ob=this_player();

	if(ob->query_temp("moon/dao"))
	{
		command("hmm "+ob->query("id"));
			return "........你不是已经问过了吗？\n";
	}
	ob->set_temp("moon/dao",1);
	command("smile");
	return "平湖秋月就在这儿，你仔细看看。。。。够美吧。。。\n";
}