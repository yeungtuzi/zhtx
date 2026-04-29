#include <ansi.h>
inherit NPC;

string *hirelist=({});
int number=1;
int abs(int);
int give_bonus(object);
int give_penalty(object);
int tokill(string);

void create()
{
	set_name("孙老头", ({ "sun laotou", "sun","laotou" }));
        set("title","酒店老板");
	set("long", "他看上去平平常常，不过大家都不知道他的来历。\n");
	set("gender", "男性");
	set("age", 60);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 25);
	set("int", 30);
	set("con", 28);
        set("dex", 58);
        set("inquiry", ([
                "杀手帮" : "这个嘛...，嗯...，你有什么事？\n",
		]) );
	
	set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: exert_function, "kuihua" :),
		(: exert_function, "recover" :),
        }) );

	set("max_kee", 5000);
	set("max_gin", 5000);
	set("atman", 300);
	set("max_atman", 300);
	set("mana", 300);
	set("max_mana", 300);
	set("force", 8000);
	set("max_force", 5000);
	set("force_factor", 100);
	set("combat_exp", 2000000);
	set("score", 1000000);

	set_skill("force", 100);
	set_skill("kuihua-shengong", 150);
	set_skill("dodge", 150);
	set_skill("mo-zhang-jue", 150);
	set_skill("strike", 100);
	set_skill("mo-jian-jue", 150);
	set_skill("parry", 100);
	set_skill("sword", 100);
	set_skill("literate", 100);
        set_skill("daguanming",150);

	map_skill("force", "kuihua-shengong");
	map_skill("strike", "mo-zhang-jue");
	map_skill("parry", "mo-jian-jue");
	map_skill("sword", "mo-jian-jue");
	map_skill("dodge", "kuihua-shengong");

	prepare_skill("strike", "mo-zhang-jue");

	setup();

	carry_object("obj/cloth/cloth")->wear();
	carry_object("obj/weapon/gangjian")->wield();
}


void init()
{
	add_action("do_quest","pkquest");
	add_action("do_hirekill","hirekill");
	add_action("do_report","pkreport");
	add_action("do_cancel","cancel");
	add_action("do_retreat","retreat");
	add_action("do_decide","decide");
	add_action("do_join","join");
	add_action("do_swear","swear");
}

int do_quest(string arg)
{
	object *ob,me,victim,paper;
	string victimid,*list=({}); 
	int i,myexp,obexp;

	me=this_player();
	if( !me->query("is_pker") )
		return notify_fail("你不是杀手，还要什么任务?小心你的脑袋。\n");
	if(me->query("pkquest"))
		return notify_fail("你已经有任务在身，还要什么任务?\n");
	myexp=me->query("combat_exp");

//先在黑名单中找，如果没有，就随机从线上抽取满足一定条件的player来kill.
	i=sizeof(hirelist);
	while(i--)
	{
		if(hirelist[i]!=me->query("id") && find_player(hirelist[i]))
			list+=({hirelist[i]});
	}
	if(!sizeof(list))
	{
		ob=users();
		i=sizeof(ob);
		while(i--)
		{
			obexp=ob[i]->query("combat_exp");
			if ( obexp >= myexp*1 && obexp <= myexp*15/10
				&& me->query("id")!=ob[i]->query("id")
				&& !wizardp(ob[i]) )
				list+=({ob[i]->query("id")});
		}
	}
	if(!sizeof(list)) return notify_fail("今天没有任务。\n");

	victimid=list[random(sizeof(list))];
	victim=find_player(victimid);

	me->set("pkquest/victimid",victimid);
	me->set("pkquest/victimexp",victim->query("combat_exp"));

	paper=new(__DIR__"obj/paper");
	paper->set("number",number++);
	paper->set("long",RED"黑名单\n\n"+victim->query("title")+"   "
			+victim->query("name")+"(" + victimid +")"+"\n"NOR);
	paper->move(me);

	tell_object(me,"孙老头递给你一个纸条，说道：好吧，给你一个任务。\n");
	hirelist-=({victimid});

	return 1;
}

int do_hirekill(string arg)
{
	int victimexp;
	object me,victim;

	me=this_player();

	if(me->query("combat_exp")<100000)  return notify_fail("一个小孩还结什么仇家。\n");
	if(me->query("is_pker")) return notify_fail("你已经是杀手了，不能再雇佣杀手。\n");
	if(me->query("pk_betrayer")) return notify_fail("你还来做什么？小心你的狗命！\n");	
	if(!arg) return notify_fail("你想雇佣杀手杀谁?\n");
	if(me->query("id")==arg)  return notify_fail("还是用suicide比较快一些。\n");
	if( !(victim=find_player(arg)) )
		return notify_fail("对不起，我们现在找不到你要杀的人。\n");
	if(wizardp(victim)) 
		return notify_fail("不能杀巫师.\n");
	if( (victimexp=victim->query("combat_exp")) < 100000 )
		return notify_fail("这么面的主，我们不屑去杀，你还是找其他人吧。\n");

	switch (MONEY_D->player_pay(me, victimexp*3))
	{
	case 0:
		return notify_fail("孙老头道：”没钱的话就不要到这来！”\n");
	case 2:
		return notify_fail("孙老头道：“您的零钱不够了，银票又没人找得开。”\n");
	default:
		tell_object(me, "孙老头道：行了，钱收下了，你就等着听好消息吧。\n");
	}

	tokill(arg);
	return 1;
}

	

int do_report(string arg)
{
	object me,paper; 
	int i;
	
	me=this_player();

	if(!(me->query("pkquest")) )
	        	return notify_fail("你想报告什么！\n");
	if( !me->query("is_pker"))
                	return notify_fail("孙老头不会对此感兴趣的！\n");

	if(me->query("pkquest/pkdone")) 
        {
                tell_object(me,"孙老头告诉你：恭喜你！你又完成了一项任务！\n");
                give_bonus(me);    
                me->set("pkquest",0);
		destruct(present("paper",me));
		me->delete_temp("apply/id");
		me->delete_temp("apply/name");
		me->delete_temp("apply/short");
		me->delete_temp("apply/long");
		me->delete_temp("pker_masked");

		if(me->query("combat_exp")<100000 )
		{
			me->delete("pkquest");
			me->delete("is_pker");
			me->delete("pkrepute");
			tell_object(me,"你的水平太低,你已经被开除了.\n");
			return 1;
		}
		return 1;
        }

	if(me->query("combat_exp")<100000 )
	{
		destruct(present("paper",me));

		me->delete_temp("apply/id");
		me->delete_temp("apply/name");
		me->delete_temp("apply/short");
		me->delete_temp("apply/long");
		me->delete_temp("pker_masked");

		me->delete("pkquest");
		me->delete("is_pker");
		me->delete("pkrepute");
		tell_object(me,"你的水平太低,你已经被开除了.\n");
		return 1;
	}

	if(!present("paper",me) )
	{
		paper=new(__DIR__"obj/paper");
		paper->set("number",number++);
		paper->set("long",RED"黑名单\n\n" + me->query("pkquest/victimid") +"\n"NOR);
		paper->move(me);
	}

	if(!(i=me->query("pkquest/bekilled")) )
		return notify_fail("你的任务还没完成，还不快去！\n");
	if(i<3)
		tell_object(me,"孙老头道：被杀了吧，没关系，继续干。\n");
	else
		tell_object(me,"孙老头道：如果不行,就取消吧。\n");
	return 1;
	
}

int do_cancel(string arg)
{
	object me;
	int i;

	me=this_player();

	if(!me->query("pkquest"))
		return notify_fail("你没有任务，取消什么？\n");
	if(!(i=me->query("pkquest/bekilled")))
		return notify_fail("你太不尽心了，不能取消。\n");

	if( i<3 )  give_penalty(me);    

        me->set("pkquest",0);
	destruct(present("paper",me));
	tell_object(me,"好吧，就取消这次任务吧。\n");
	return 1;
}

int do_retreat(string arg)
{
	object me;

	me=this_player();
	if( !me->query("is_pker") )
		return notify_fail("你不是杀手,隐退什么?\n");
	tell_object(me,"若想隐退,必须要付出代价,你决定(decide)吗?\n");
	me->set_temp("ask_retreat",1);
	return 1;
}

int do_decide(string arg)
{
	object me;
	me=this_player();

	if(!(me->query_temp("ask_retreat") )   )
		return notify_fail("先敲retreat,才能decide.\n");
	//tokill(me->query("id"));
	me->delete("is_pker");
	me->delete("pkquest");
	me->delete("pkrepute");
	me->delete_temp("ask_retreat");       
	me->set("shen",-100000);  
	me->set("score",me->query("score")/2);    
	me->set("pk_betrayer",1);
	tell_object(me,"你现在已经脱离我们的组织了，不过你以后可要小心点。别装成正人君子的模样。\n");	
	CHANNEL_D->do_channel(this_object(),"rumor",me->name()+"在暗杀了"+me->query("pkrepute")+"个玩家之后，决定退出杀手组织。\n");
	return 1;
}

int do_join(string arg)
{
	object me;
	me=this_player();
	if(me->query("pk_betrayer")) return notify_fail("你还来做什么？小心你的狗命！\n");	
	if(me->query("is_pker"))
		return notify_fail("你已经是杀手了。\n");
	if(me->query("combat_exp")<100000)
		return notify_fail("你的功夫太低,还是回去好好练功吧。\n");
	tell_object(me,"加人我们组织，随时有死亡的危险，你且发个誓来(swear)。\n");
	me->set_temp("ask_join",1);
	return 1;
}

int do_swear(string arg)
{
	object me;
	me=this_player();

	if(!(me->query_temp("ask_join") ) )
		return notify_fail("先敲join,才能swear.\n");
	me->set("is_pker",1);
	me->delete_temp("ask_join");
	tell_object(me,RED"你对天发誓道：\n"
		+"我志愿加如杀手组织，不惜一切代价完成组织交给的任务。\n\n"NOR
		+"恭喜你，你已经加入我们的组织。\n");
	return 1;
}

int tokill(string str)
{
	int victimexp,obexp,i,flag=0;
	object victim,*ob,pker,paper,*pkerlist=({});

	if(!(victim=find_player(str)))
 		return notify_fail("对不起，我们现在找不到你要杀的人。\n");
	victimexp=victim->query("combat_exp");
//先在线上找满足一定条件的pker来，如果找不到，就找与被杀的人的经验最接近的pker.
//如果再找不到，就加入到黑名单。
	ob=users();
	i=sizeof(ob);
	while(i--)
	{
		if(ob[i]->query("is_pker") && str!=ob[i]->query("id")
				&&!ob[i]->query("pkquest")
				&& !wizardp(ob[i]) )
		{
			obexp=ob[i]->query("combat_exp");

			if ( victimexp >= obexp*9/10 && victimexp <= obexp*15/10)
			{
				pker=ob[i];
				flag=1;
				break;
			}
			pkerlist+=({ob[i]});
		}
		
	}
	if(!flag)
	{
		i=sizeof(pkerlist);
		if(i>0) {pker=pkerlist[0];flag=1;}
		while(i--)
		{
			if( abs(pker->query("combat_exp")-victimexp)
				 > abs(pkerlist[i]->query("combat_exp")-victimexp) )
					pker=pkerlist[i];
		}
	}
	if(flag)
	{
		pker->set("pkquest/victimid",str);
		pker->set("pkquest/victimexp",victimexp);

		paper=new(__DIR__"obj/paper");
		paper->set("number",number++);
		paper->set("long",RED"黑名单\n\n"+victim->query("title")+"   "
			+victim->query("name")+"(" + str +")"+"\n"NOR);
		paper->move(pker);
		tell_object(pker,"一只鸽子飞到你的肩上,你飞快地从鸽子脚上取下一张信笺。\n");
	}
	else
	{
		hirelist+=({str});
	}

	return 1;
}	

int give_bonus(object me)
{
	int victimexp,pkrepute,expbonus,potbonus,goldbonus;
	object money;

	victimexp=me->query("pkquest/victimexp");
	pkrepute=me->query("pkrepute");

	expbonus=(pkrepute+1)*victimexp/2000;
	if(expbonus>10000) expbonus=10000;
	potbonus=(pkrepute+1)*victimexp/2000;
	if(potbonus>500) potbonus=500;	
	goldbonus=(pkrepute+1)*victimexp/2000;
	if(goldbonus>100) goldbonus=100;

	if(me->query("pkrepute") < 10)
		me->add("pkrepute",1);
        me->add("combat_exp",expbonus);
        me->add("potential",potbonus );

	money = new("/obj/money/gold");
	money->set_amount(goldbonus);
	money->move(me);

        tell_object(me,HIW"你被奖励了：\n" +
                 chinese_number(expbonus) + "点实战经验\n"+
                 chinese_number(potbonus - me->query("learned_points")) + "点潜能\n" +
		 chinese_number(goldbonus) + "两金子\n"
                 NOR);

	return 1;

}

int give_penalty(object me)
{
	int pkrepute;

	pkrepute=me->query("pkrepute");
	me->set("pkrepute",pkrepute/2+random(pkrepute/2));
	return 1;
}

int abs( int i)
{
	if (i<0) return -i;
	return i;
}

int accept_kill(object me)
{
	if(userp(me))
	{
		message_vision(RED"孙老头对$N嘿嘿一笑，赞道：有胆量。\n"NOR,me);

		tokill(me->query("id"));
		return 1;
	}
	return 1;
}
