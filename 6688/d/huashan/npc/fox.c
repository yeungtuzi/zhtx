//fox.c
//茶篷的女老板，平时看起来并没有什么出众之出，当然除了她的容貌
//但是背地里面却有着最灵通的消息，在江湖中，人们总会称呼她“万事通”
//当然，这些是不会写在描述里面的
//在这个NPC身上，会判断你时候带齐了在长老那里带来的mark，并且随身携带了
//湛卢剑，如果这些都没满足的话，那么对不起了。:)
//并且还可以跟这个NPC问一些别的问题，别忘记了，她可是个万事通哦。

#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

string ask_news();
string ask_me_1();
string ask_me_2();
string ask_goods();

void create()
{
        set_name(HIC"小狐狸"NOR, ({ "xiao huli","fox","waiter" }) );
        set("gender", "女性" );
        set("age", 23);
        set("long",
@LONG
小狐狸就是这间小茶棚的女老板，除了容貌以外，她看起来跟平常人没有
什么区别。她长的很是漂亮，尤其是一双水汪汪的大眼睛，简直是勾人魂魄
一头如云的秀发直垂到腰间，总穿着一身雪白的衣衫，却不见衣衫因为每日
的操劳变的有一丝脏乱和不洁。你仔细一看，她竟然脚上是没有穿鞋的，露
出一双雪白的天足。
LONG
);
		set("per",100);
     set("combat_exp",5000);
   set_skill("dodge",300);
        set("attitude", "friendly");
        set("rank_info/respect", "小小狐狸");
        set("vendor_goods", ([
                __DIR__"obj/tea": 50,
                __DIR__"obj/huasheng": 50,
                __DIR__"obj/flower": 10,
                
        ]) );                    
	set("chat_chance",2);
        set("chat_msg", ({
                (: command("say 不许看我，小心我咬你!") :),
                (: command("blush") :),
                (: command("cry corpse") :),                                
        }) );
        
        
        set("inquiry", ([
                "戒指" :         (: ask_me_1 :),//最重要的......
                "风清扬" :       (: ask_me_2 :),
                "消息" :	 (: ask_news :),
		"好东西":        (: ask_goods:),
        ]));
        setup();
	carry_object(__DIR__"obj/whiteskirt.c")->wear();
	carry_object(__DIR__"obj/crystalclasp.c")->wear();
	carry_object(__DIR__"obj/jadebracelet.c")->wear();
	carry_object(__DIR__"obj/onyxnecklace.c")->wear();
	carry_object(__DIR__"obj/dingdang.c")->wear();
	

}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
		add_action("do_buy","buy");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(3) ) {
                case 0:
                        say( "小狐狸笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，进来喝杯茶，歇歇腿吧。\n");
                        break;
                case 1:
                        say( "小狐狸用手旁的毛巾抹了抹手，说道：这位" + RANK_D->query_respect(ob)
                                + "，请进请进。\n");
                        break;
                case 2:
                        say( "小狐狸说道：这位" + RANK_D->query_respect(ob)
                                + "，进来喝几盅小店的香茶吧，这几天才采的香片。\n");
                        break;
        }
}

string ask_news()
{
   if(this_player()->query("mark/secret_fail"))
		return "瞎问什么，上次不都告诉你了么。\n";
   if(this_player()->query("mark/secret/kill_fox"))
	    return "哼！\n";
   message_vision("小狐狸瞪了$N一眼：“我这里只是茶棚，四方走的都是客，虽说消息灵通，但是也不是白给的。”\n");
   set_temp("mark/ask_for_news",1);
   return "除非......\n";
}

string ask_goods()
{
   object ppl=this_player();
   
   if(ppl->query("mark/secret/kill_fox"))
	    return "哼！\n";
   
   if(!ppl->query_temp("mark/ask_for_news"))
	   return "不知道，我这里只卖香茶，花生和鲜花，要买别的东西，找别人去，我这里可没有。";
   ppl->delete_temp("mark/ask_for_news");
   ppl->set_temp("mark/ask_for_goods",1);
   set("vendor_goods", ([
                __DIR__"obj/tea": 50,
                __DIR__"obj/huasheng": 50,
                __DIR__"obj/flower": 10,
				__DIR__"obj/paper": 1,
   ]) );
   return "看你这一番诚意，便宜你点，卖给你了。";
}

int do_buy(string arg)
{
    object ppl=this_player();
    object owner;
    string item, targ;

     
     if( !arg 
     ||  sscanf(arg, "%s from %s", item, targ)!=2 )
        return notify_fail("指令格式：buy <某物> from <某人>\n");
     if( !objectp(owner = present(targ, environment(ppl))) )
        return notify_fail("你要跟谁买东西？\n");

     if(!ppl->query_temp("mark/ask_for_goods"))
		return 0;
     if(item=="letter")
	{
	int price=1000000;
	switch (MONEY_D->player_pay(ppl, price))
	{
        case 0:
                return notify_fail("穷光蛋，一边呆着去！\n");
        case 2:
                return notify_fail("您的零钱不够了，银票又没人找得开。\n");
        default:
		{
			owner->compelete_trade(ppl, "letter");
			ppl->set_temp("mark/buy_goods",1);
			return 1;
		}
	}
	}
	return 0;
}

string ask_me_2()
{
	object ppl=this_player();
	
	if(ppl->query("mark/secret/kill_fox"))
	    return "哼！\n";
   	
	if(!present("zhanlu sword",this_player())
	||  ppl->query("mark/secret_fail"))
		return "你是谁啊，我不认识你。\n";
	if(!ppl->query("mark/secret_1_ask_zhanglao")
	 ||!ppl->query("mark/secret_2_give_zhanglao")
	 ||!ppl->query("mark/secret_3_can_ask_zhanglao")
	 ||!ppl->query("mark/secret_4_can_learn")
	 ||!ppl->query("mark/secret_5_lookforfeng")
	 )
	    return "甭在这里瞎问，打搅我做生意。\n";
	if(!ppl->query_temp("mark/buy_goods"))
		return "本姑娘今天心情不好，别来烦我。\n";
	command("tell "+ppl->query("id")+" 你问老头子啊，他经常在上面的一个山洞里面呆着，嘴里面还经常唠叨着一个女人的名字。
		不过从来不见外人，这样吧，你拿刚才那张纸去找他吧，看在我的面子上大概他会见你。");
	ppl->set("mark/secret/6_ask_fox",1);
	command("xixi");
	return "你这就去吧。\n";
}

string ask_me_3()
{
	object ppl=this_player();

	if(ppl->query("mark/secret/kill_fox"))
	    return "哼！\n";
   
	if(ppl->query("mark/secret_fail"))
		return "哼，不长进的东西，又来问我啊。\n";
	if(!ppl->query("mark/secret/7_ask_feng"))
		return "你没去见过老头子啊。\n";
	if(!ppl->query_condition("rest_time")
	&& !ppl->query("mark/serret/8_lookforring"))
	{
		this_player()->set("mark/secret_8_lookforring",1);
		command("say 据说老头子年轻的时候被一个姑娘骗的很惨，才会隐居到这里来的。");
		command("sigh");
		command("say 真是“问世间情为何物，直教人生死相许。”，连老头子也不能免俗啊。");
		command("tell "+this_player()->query("id")+" 根据我多年来收集的情报，那个女的据说就住在西湖旁。不如......");
		command("walkby");
		this_player()->apply_condition("rest_time",300);
			return "快去快回哦。\n";
	}
	if(!ppl->query("mark/secret/9_getring"))
	{
		ppl->set("mark/secret_fail",1);
		ppl->delete("mark/secret");
		return "你可真够笨的啊，算了，我也帮不了你了。\n";
	   }
	else
		return "赶紧去见老头子吧，他肯定很高兴。\n";

}
void die()
{
	object killer=this_object()->query_temp("last_damage_from");
	killer->set("mark/secret/kill_fox",1);
	if(killer->query("family/family_name")=="华山派剑宗")
		killer->add("hatred/华山派气宗",-100000);
	::die();
}
