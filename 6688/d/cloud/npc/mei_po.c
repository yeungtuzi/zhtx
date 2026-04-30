//NPC:/d/suzhou/npc/meipo.c
//changed by tang
//97.11.4

#include <ansi.h> 
inherit NPC;

void create()
{
	set_name("媒婆", ({ "meipo" }) );
	set("title", RED "红娘庄" NOR);
        	set("gender", "女性" );
        	set("age", 53);
        	set("long",
                "一位精明能干的老媒婆\n");
        	set("combat_exp", 10000);
        	set("attitude", "friendly");
        	set("inquiry", ([
                "婚约" : MAG"是啊... 这里就可以缔结和解除婚约"NOR,
		"补办手续": MAG"如果婚约丢了可以补办"NOR,
	        ]) );
        	set_skill("literate", 70);
        	set_skill("dodge", 500);
        	set_skill("unarmed", 300);
        	setup();
        	add_money("gold", 5);
}

void init()
{
        	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_marry", "marry");
	add_action("do_unmarry", "unmarry");
	add_action("do_remarry","remarry");
}

int do_marry(string arg) 
{
	object marry_card, obj, me,*inv;
	int i;

	me = this_player();                                                               

	if( me->query("gender")=="无性" )	 
		return notify_fail("你无根无性, 还要婚约作什么?\n");

	if(wizardp(me)) 
		return notify_fail("还没玩够呀？巫师不能结婚！\n");
	
	if( !environment() || base_name(environment()) != query("startroom") )
		return notify_fail(
			"真是抱歉，请您等一下到红娘庄来找我吧。\n");

	if( !arg || !userp(obj = present(arg, environment(me))) )
		return notify_fail("你想和谁缔结良缘？\n");                       

	if( me->query("wife") || me->query("husband") )
		return notify_fail(
			"你已经和别人有婚约了吧?这里不允许重婚的。\n");
                                                                                                        
	if( obj->query("wife") || obj->query("husband") )
		return notify_fail(
               		"你的对象已经和别人有婚约了吧?这里不允许重婚的。\n");

	if ( marry_card=present("marrycard",me) )
		destruct(marry_card);

	if ( marry_card=present("marrycard",obj) )
		destruct(marry_card);

	if( !living(obj) )
		return notify_fail(obj->name() + "已经无法和你缔结良缘了。\n"); 

	if(obj==me)	return notify_fail("你不能和自己缔结婚约。\n");

	if((string)obj->query("gender")== (string)me->query("gender"))
		return notify_fail("你不怕" + RED"AIDS"NOR + "吗？\n");

	if( (string)me->query("class")=="bonze" || (string)me->query("class")==
		"lama" || 
		(string)me->query("class")=="shaolin" )
		return notify_fail("和尚怎么能结婚呢？？？\n");



	if ( (((int)me->query("age")<17) && ((string)me->query("gender")=="男性")) ||
		(((int)me->query("age")<14) && ((string)me->query("gender")=="女性")) )
		return notify_fail("你太小啦，怎么可以啦？\n");  

	if( !((object)obj->query_temp("m_"+me->name(1))) )
	{                                                
		inv=all_inventory(me);
		i=sizeof(inv);
		while(i--)
		{               
			if( me->query_temp("m_"+inv[i]->name(1)) ) 
			{
				tell_object(inv[i], YEL + me->name() + 
					"取消了和你结婚的念头。\n" NOR);
				me->delete_temp("m_"+obj->name(1));
				break;
			}
		}
		
		message_vision(MAG "\n$N对著$n说道：" 
			+ RANK_D->query_self(me) + me->name() + "，愿意和"
			+ RANK_D->query_respect(obj) + 
			"结为夫妇\n\n"NOR, me,obj);           
		
		me->set_temp("m_"+obj->name(1), 1);
		tell_object(obj, MAG "如果你愿意和对方结为夫妇，请你也对" 
			+me->name() + "("+(string)me->query("id")+
			")"+ "下一次 marry 指令。\n" NOR);
		write(MAG  
			"现在你急切盼望着你的心上人说同意...\n" NOR);
		return 1;
	}
        
	obj->delete_temp("m_"+me->name(1));
	
	marry_card = new("/obj/misc/marry_card");
	marry_card->set("name","你和"+obj->query("id")+"的婚约");
	marry_card->move(me);
	marry_card = new("/obj/misc/marry_card");
	marry_card->set("name","你和"+me->query("id")+"的婚约");
	marry_card->move(obj);
	me->set("is_married", 1);
	obj->set("is_married", 1);

	if( me->query("gender")=="女性" )  
	{
		me->set("husband/id", obj->query("id"));
		me->set("husband/name", obj->query("name"));
		obj->set("wife/id", me->query("id"));
		obj->set("wife/name", me->query("name"));
	}
	if( me->query("gender")=="男性" )  
	{
		obj->set("husband/id", me->query("id"));
		obj->set("husband/name", me->query("name"));
		me->set("wife/id", obj->query("id"));
		me->set("wife/name", obj->query("name"));
	}

	message_vision(MAG "恭喜 $N 和 $n ，一对璧人喜结良缘。\n" NOR,	obj, me);
	message("chat", me->name() + "和" + obj->name() + 
		"现在开始是夫妇啦\n", environment(me),me); 
	CHANNEL_D->do_channel(this_object(), "chat",
		sprintf( "%s 和 %s 现在开始是夫妇啦! \n", 
		me->name(1), obj->name(1)));

	return 1;
}

int do_remarry(string arg) 
{
	object marry_card,  me;
 	object obj;
	// 2026-04-30: unused variable commented out
	// string cardname,target;

	me = this_player();

	if( me->query("gender")=="无性" )	 
		return notify_fail("你无根无性, 还要婚约作什么?\n");

	if ( (((int)me->query("age")<17)&&((string)me->query("gender")=="男性"))
		 || (((int)me->query("age")<14) && ((string)me->query("gender")=="女性")) )
		return notify_fail("你太小啦，怎么可以啦？\n");
	             
	if( !me->query("wife") && !me->query("husband") )
		return notify_fail("你还没有结婚，想要和谁续良缘？\n");

	if (marry_card = present("marrycard",me)) 
		return notify_fail("你已经有婚约了，还补什么\n");

	if( arg )
	{                                  
		if( !userp(obj = present(arg, environment(me))) )                
			return notify_fail("这个人好象不是你的伴侣。\n");
                                                           
		if( !living(obj) )
			return notify_fail(obj->name() + "已经无法和你再续良缘了。\n"); 

		if( obj->query("id") != me->query("husband/id") && 
			obj->query("id") != me->query("wife/id") ) 
			return notify_fail("这个人好象不是你的伴侣。\n");
	}

	marry_card = new("/obj/misc/marry_card");           
	if( me->query("gender")=="女性" )
		marry_card->set("name","你和"+me->query("husband/id")+"的婚约");
	else	marry_card->set("name","你和"+me->query("wife/id")+"的婚约");
	marry_card->move(me);
	command("say 好了，拿去吧！不要再丢了。");
	return 1;
}

int do_unmarry(string arg)
{
	object me, obj, card,*inv;
	string str2;                    
	int i;
             
	me = this_player();           
                                                                              
	if( !arg )	return notify_fail("你要干什么？\n");              

//	if( !environment() || base_name(environment()) != query("startroom") )
//		return notify_fail("真是抱歉，请您等一下到红娘庄来找我吧。\n");
                                                                
	if ( me->query("gender") == "女性") 
		str2 = "他";
	else	str2 = "她";

	if( !me->query("wife") && !me->query("husband") )
		return notify_fail("你没有伴侣.\n");                       

	if( me->query("husband/id")!=arg && me->query("wife/id")!=arg )
		return notify_fail(str2+"不是你的伴侣，你的伴侣现在不在场.\n");
                                                                                                
	obj=present(arg, environment(me));

	if( !((object)obj->query_temp("um_"+me->name(1))) )
	{     
		inv=all_inventory(me);
		i=sizeof(inv);
		while(i--)
		{
			if( me->query_temp("um_"+inv[i]->name(1)) ) 
			{
				tell_object(inv[i], YEL + me->name() + 
				"取消了和你离婚的念头。\n" NOR);
				me->delete_temp("um_"+obj->name(1));
				break;
			}
		}

		message_vision(MAG "\n$N对著$n说道：" 
			+ RANK_D->query_self(me) 
			+ me->name() + "，咱们解除婚约吧!好吗?\n\n"
			NOR, me, obj);           
		me->set_temp("um_"+obj->name(1), 1);
		tell_object(obj, MAG "如果你愿意解除婚约，请你也对" 
			+me->name() + "("+(string)me->query("id")+
			")"+ "下一次 unmarry 指令。\n" NOR);

		write(MAG  
			"现在你只有等着" +str2 +" 同意啦...\n" NOR);
		return 1;
	}                                                              

	obj->delete_temp("um_"+me->name(1));	                                                                           

	me->delete("wife");
	me->delete("husband");                                               
	me->delete("is_married");
	if ( card=present( "marrycard", me ) )
		destruct(card);
	if ( card=present( "indenture", me ) )
		destruct(card);
	obj->delete("wife");
	obj->delete("husband");    
	obj->delete("is_married");
	if ( card=present( "marrycard", obj ) )
		destruct(card);     
	if ( card=present( "indenture", obj ) )
		destruct(card);
        
	message_vision(MAG " $N 和 $n 从现在开始解除婚约,互不相干!\n" NOR,
		obj, me);
	CHANNEL_D->do_channel(this_object(), "chat",
		sprintf( "%s 和 %s 从现在开始解除婚约,互不相干! \n", 
		me->name(1), obj->name(1)));

	return 1;
}
