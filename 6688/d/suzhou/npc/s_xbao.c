//s_xbao.c

#include <ansi.h>
inherit NPC;
string ask_for_du(object ob);

void create()
{
        set_name("韦小宝", ({ "wei xiaobao","xiaobao","wei" }) );
        set("gender", "男性" );
        set("age", 18);
        set("long", "他脸上的表情仿佛是看到了你口袋里的钱一般，一双眼睛贼兮兮的。\n");
        set("per", 20+random(10));
        set("combat_exp", 1500000);
        set("attitude", "friendly");
        set_skill("unarmed", 50);
        set_skill("parry", 70);
	set_skill("dodge",200);
	set_skill("move",200);
	set_skill("xiaoyaoyou",150);
	map_skill("dodge","xiaoyaoyou");

        set("inquiry", ([
                "赌" : (: ask_for_du :),
	]) );

        setup();
        carry_object("/d/suzhou/npc/obj/baishan")->wear();
	carry_object("/d/suzhou/npc/obj/tiejia")->wield();
        carry_object("/obj/example/dagger")->wield();
}

string ask_for_du(object ob)
{
	if(ob->query("gender")!="女性")
	{
		command("haha");
		command("say 到赌馆来当然是赌，你就下注吧。\n");
		return "";
	}
	command("loveshoe "+ob->query("id"));
	return "";
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( "快来赌，快来赌啦！\n");
                        break;
                case 1:
                        say( "赢了可是利滚利啊！\n");
                        break;
        }
}

void pay_player(object who, int amount)
{
        object ob;

        if( amount < 1 ) amount = 1;
        if( amount/100 ) {
                ob = new(SILVER_OB);
                ob->set_amount(amount/100);
                ob->move(who);
                amount %= 100;
        }
        if( amount ) {
                ob = new(COIN_OB);
                ob->set_amount(amount);
                ob->move(who);
        }
}

int accept_object(object who, object ob)
{
        int val;

        val = ob->value();
        if( !val ){
                return notify_fail("物品不能折价，您还是先去折现吧！\n");
                return 0;
        }
        else{
		switch(random(2))
		{
		case 0:
		        say("什么？ 您押小？！好的。\n"); 
			if( random(10) < 8 ) {
                        say( "宝官说道：开！押大的赢啦！这位"
                                + RANK_D->query_respect(who)
                                + "，您下次一定好运！\n");
                	} else {
                        say( "宝官说道：开！押小的赢啦！这位"
                                + RANK_D->query_respect(who)
                                + "真是好运道！这是您的赢头。\n");
                        pay_player(this_player(), val * 2);
                	}
			break;
		case 1:
			say("什么？ 您押大？！好的。\n"); 
			if( random(10) < 8 ) {
			
                        say( "宝官说道：开！押小的赢啦！这位"
                                + RANK_D->query_respect(who)
                                + "，您下次一定好运！\n");
                	} else {
                        say( "宝官说道：开！押大的赢啦！这位"
                                + RANK_D->query_respect(who)
                                + "真是好运道！这是您的赢头。\n");
                        pay_player(this_player(), val * 2);
 	              	}
			break;
		}
	ob->destruct();
 	return 1;
        }
}

