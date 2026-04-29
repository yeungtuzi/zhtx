//xian.c

#include <ansi.h> 
inherit NPC;
                                                                             
int ask_me();            
                       
string *make_msg = ({  
    HIR"下面新郎与新娘拜堂！\n\n"NOR,    
    HIR" 一 拜 天 地  \n\n"NOR,
    HIR" 二 拜 高 堂  \n\n"NOR,
    HIR" 夫 妻 对 拜  \n\n"NOR,
    HIR" 新 郎 新 娘  入 洞 房！\n\n"NOR
});

string *sss=({
	"作天真状。\n",
	"作小鸟依人状。\n",
	"一副傻呆呆的样子。\n",
	"看着新娘子傻笑。\n",
	"躲在一旁与其它人高谈阔论。\n",
	"左手指夹着一根烟，眼睛闭着，正在享受。\n",
	"拎着酒瓶到处找人灌酒。\n",
	"看着新娘子，口水流得满身都是。\n",
	"一脸羡慕地瞧着新郎。\n",
	"痴呆呆地盯着新娘看。\n",
});

void create()
{
	set_name("冼老板" NOR, ({ "xian laoban","xian","boss" }) );
	set("gender", "男性" );
	set("age", 45);
                                                          
	set("combat_exp", 100000);
	set("attitude", "friendly");
	set("inquiry", ([
		"酒席" : (:ask_me:),
		]) );
	set_skill("literate", 70);
	set_skill("dodge", 500);
	set_skill("unarmed", 300);
/*
	set("num",30);
	set("in_busy",1);
	set("level",2);
	set("host1","tang");
	set("host2","tang");
*/
	setup();
	add_money("gold", 3);
}

void init()
{
//        add_action("do_decide", "decide");                           
	add_action("do_toast", "toast");
	add_action("do_toast", "cheer");
	add_action("do_qingke", "qingke");
}

int do_decide(string arg)
{
	string arg1,arg2,cardname,target;
	object me,who,obj,*guest,*usr;
	int baseprice,factor,i;                        
	
	if (!arg || sscanf(arg,"%s and %s" ,arg1,arg2)!=2)                
		return notify_fail("decide <档次> and <规模> \n");       

	if( query("in_busy") )	return notify_fail("别急，慢慢来。\n");             
                        
	me=this_player();                     
	usr=users();

	if( !me->query("is_married") )	
		return notify_fail("你还没有结婚，无法举行婚礼！\n");
	if( !present("marrycard", me) )	
		return notify_fail("你没有结婚证，还不能举行婚礼！\n");

	cardname = present("marrycard",me)->query("name");

	if (sscanf(cardname,"你和%s的婚约" ,target)!=1)
                	return notify_fail("你还没有伴侣，怎么结婚。\n");
                                                                              
	if( !present(target,environment(me)) )
		return notify_fail("你伴侣不在身边，不能举行婚礼。\n");          
                                                
	switch (arg1)
	{
	case "高档":                 
		set("level", 2);
		baseprice=200000;
		break;
	case "中档":                                             
		set("level", 1);
		baseprice=100000;
		break;
	case "低档":
		baseprice=50000;
		break;
	default:
		return notify_fail("本店只承办高中低档酒席。\n");
	}
                         
	switch(arg2)
	{
	case "here":                                         
		if( sizeof(usr)<3 )	                                                              
			return notify_fail("现在玩家很少，是不是改日再举行婚礼。\n");
		factor=0;             
		guest=all_inventory(environment(me));
		for(i=0;i<sizeof(guest);i++)
			if( userp(guest[i]) )	factor++;
		factor=(factor-2)/4+1;
		break;
	case "all":
		if( sizeof(usr)<3 )	
			return notify_fail("现在玩家很少，是不是改日再举行婚礼。\n");
                             	factor=(sizeof(usr)-2)/4+1;  
		break;
	default:
		return notify_fail("本店不承办客官所订规模的酒席。\n");
	}
                                          
	switch (MONEY_D->player_pay(me, baseprice*factor) )
	{
	case 0:
		return notify_fail("你的钱不够办酒席！”\n");
	case 2:
		return notify_fail("冼老板赔笑道：“您的黄金不够了，银票又没人找得开。”\n");
	default:
		;
	}
                                                                            
	who=find_player(target);
                                                                 
        	CHANNEL_D->do_channel( this_object(), "chat",
        		sprintf( HIR"五分钟后，%s 和 %s 在紫阳楼举行婚礼，希望大家前来观礼! \n"NOR, 
        		me->query("name"), who->query("name") ) );

	if( arg2=="here" )
	{                                                                   
		guest=all_inventory(environment(me));
		for(i=0;i<(sizeof(guest));i++)
		{                                                                                      
			if( userp(guest[i]) )
			{
				if( guest[i] != me && guest[i] != who )
				{
					obj=new(__DIR__"obj/xitie");
					obj->move(guest[i]);
					tell_object(guest[i], me->query("name")+"和"+who->query("name")+"结婚，请你去观礼。\n");
				}
			}
		}				
	}

	if( arg2=="all" )
	{
		for(i=0;i<(sizeof(usr));i++)
		{              
			if( usr[i] != me && usr[i] != who )
			{
				obj=new(__DIR__"obj/xitie");
				obj->move(usr[i]);
				tell_object(usr[i], me->query("name")+"和"+who->query("name")+"结婚，请你去观礼。\n");
			}
		}				
	}
                                                                                       
	set("host1", me->query("id"));
	set("host2", target);                                         
	set("in_busy", 1);
                          
	if( query("level") )
	{                      
		if( me->query("gender")=="女性" )
		{                                      
			obj=new(__DIR__"obj/hunsha");
			obj->move(me);
			obj=new(__DIR__"obj/suit");
			obj->move(who);
		} 
		if( me->query("gender")=="男性" )
		{                                      
			obj=new(__DIR__"obj/suit");
			obj->move(me);
			obj=new(__DIR__"obj/hunsha");
			obj->move(who);
		}
		message_vision("这是你们的结婚礼服。\n",me);
	}

        	CHANNEL_D->do_channel( this_object(), "chat",
        		sprintf( HIR"参加婚礼的(包括主人)可以给新郎新娘灌酒\n
		(toast or cheer)，持有喜帖的可将喜帖交与小人我，\n
		如无人敬酒，将自动安排新郎新娘入洞房！\n"NOR) );

	message_vision("小人在三楼恭候客官。\n", me);
	this_object()->move("/d/jingcheng/zyl3");     
	me->move("/d/jingcheng/zyl3");     
	who->move("/d/jingcheng/zyl3");     

	remove_call_out("make_stage");
	call_out( "make_stage", 300, 0 );          		

	for(i=0;i<(sizeof(usr));i++)
	{              
		if( usr[i] != me && usr[i] != who )	usr[i]->move("/d/jingcheng/zyl3");
	}				

	return 1;
}                                                                     

int do_toast(string argg)                                                                
{                                                 
	object 	who,room,photo,host1,host2,*inv;
	string 	arg;
	int 	i;
	
	who=this_player();                 
	host1=find_player(query("host1"));          
	host2=find_player(query("host2"));          

	if( !query("in_busy") )
		return notify_fail("婚礼 已经结束啦。\n");

	if( query("num") <30 )
	{                                                         
		if( who->is_busy() )
			return notify_fail("你先喝完你杯里的酒再说。\n");
		who->start_busy(10);
		switch (random(10))
		{
		case 0: 
			if( who->query("id") == query("host1") || who->query("id") == query("host2") )
				message_vision("谢谢大家的捧场，干杯！\n", who);
			else	message_vision("恭喜恭喜，来，来，来，新郎倌干了这杯。 \n", who);
			add("num",1);                            
			break;
		case 1:
			if( who->query("id") == query("host1") || who->query("id") == query("host2") )
				message_vision("大家多吃点，不要客气。 \n", who);
			else	message_vision("祝新郎与新娘白头偕老，永结同心。 \n", who);
			add("num",1);
			break;
		case 2:                        
			if( who->query("id") == query("host1") || who->query("id") == query("host2") )
				message_vision("招待不周，望大家海涵。 \n", who);
			else	message_vision("$N解花献佛，敬新郎一杯。 \n", who);
			add("num",1);
			break;
		case 3:                        
			if( who->query("id") == query("host1") || who->query("id") == query("host2") )
				message_vision(" 喝完这杯，再...玩...玩...\n", who);
			else	message_vision("来，来，来，大家敬新娘一杯。 \n", who);
			add("num",1);
			break;
		case 4:                        
			if( who->query("id") == query("host1") || who->query("id") == query("host2") )
			{
				if( who->query("gender")=="女性" )
					message_vision("外子不胜酒力，大家就饶了他吧。 \n", who);
				else	message_vision("内人不胜酒力，我替她喝了这杯。 \n", who);
			}
			else	message_vision("祝两位早生贵子，干了这杯。 \n", who);
			add("num",1); 
			break;
		default:
			if( who->query("id") == query("host1") || who->query("id") == query("host2") )
				message_vision(" 喝完这杯，再...玩...玩...\n", who);
			else	message_vision("来，来，来，大家敬新娘一杯。 \n", who);
			add("num",1);
		}                                          
	
		inv=all_inventory(environment(who));
		for( i=0;i<sizeof(inv);i++)
		{                                              
			if( userp(inv[i]) )
			{
				inv[i]->add("water",5);
				inv[i]->add("food", 5);
			}
		}                                                         
		if( query("level")==2 )
		{
			room=environment(this_object());

			arg=room->query("long")+"\n";
			for(i=0;i<sizeof(inv);i++)
			{
				if( userp(inv[i]) && inv[i]!=host1 && inv[i]!=host2 )
				{
					arg+=inv[i]->query("name");
					arg+=sss[random(10)];
				}
			}                  
			if( query("host1") && query("host2") )
			{
				arg+=host1->name()+"偎在"+host2->name()+"的怀里。\n";
				arg+=host2->name()+"深情地看着怀里的"+host1->name()+"。\n";
			}
			message_vision( "咔嚓！\n", this_object() );
			photo=new(__DIR__"obj/photo");
			photo->set("long",arg);
			photo->move(who);
		}

		remove_call_out("make_stage");
		call_out( "make_stage", 60, 0 );          		
		return 1;
	}                                                

	if( query("ok") )	return notify_fail("现在正在举行大礼。\n");
	                                                        
	set("ok", 1);
                                                                                                        
	remove_call_out("make_stage");
	call_out( "make_stage", 2, 0 );

	return 1;
}

void make_stage(int stage)
{                                 
	object room,host1,host2,photo,*inv;
	int i;
	string arg;
	                            
       	CHANNEL_D->do_channel(this_object(), "chat",
	        sprintf( make_msg[stage] )); 

	if (++stage < sizeof(make_msg) ) {
		call_out( "make_stage", 10, stage);
		return;
	}                                  

	host1=find_player(query("host1"));          
	host2=find_player(query("host2"));          

	if( query("level")==2 )
	{
		room=environment(this_object());
		inv=all_inventory(room);

		arg=room->query("long")+"\n";
		for(i=0;i<sizeof(inv);i++)
		{
			if( userp(inv[i]) && inv[i]!=host1 && inv[i]!=host2 )
			{
				arg+=inv[i]->query("name");
				arg+=sss[random(10)];
			}
		}                                              
		if( query("host1") && query("host2") )
		{
			arg+=host1->name()+"偎在"+host2->name()+"的怀里。\n";
			arg+=host2->name()+"深情地看着怀里的"+host1->name()+"。\n";
		}

		message_vision( "咔嚓！\n", this_object() );
		photo=new(__DIR__"obj/photo");
		photo->set("long",arg);
		photo->move(host1);

		photo=new(__DIR__"obj/photo");
		photo->set("long",arg);
		photo->move(host2);
	}
	
	host1->move("/d/jingcheng/dongfang");
	host1->set_temp("enter", 1);		

	host2->move("/d/jingcheng/dongfang");
	host2->set_temp("enter", 1);		

	destruct(this_object());
	return;
}                                  

int do_qingke(string arg)
{
	object me,obj,*guest;
	int factor,i;  

	if( !arg )	return notify_fail("qingke here or all \n");
	
	if( is_busy() )	return notify_fail("别急，慢慢来。\n");             
                        
	me=this_player();                     
                      
	switch(arg)
	{
	case "here":                            
		factor=0;             
		guest=all_inventory(environment(me));
		for(i=0;i<sizeof(guest);i++)
			if( userp(guest[i]) )	factor++;
		break;
	case "all":                     
		guest=users();
                             	factor=sizeof(guest);  
		break;
	default:
		return notify_fail("本店不承办客官所订规模的酒席。\n");
	}
                                          
	switch (MONEY_D->player_pay(me, 10000*factor) )
	{
	case 0:
		return notify_fail("你的钱不够办酒席！”\n");
	case 2:
		return notify_fail("冼老板赔笑道：“您的黄金不够了，银票又没人找得开。”\n");
	default:
		;
	}
                                                                            
	if( arg=="here" )	
	{
	        	CHANNEL_D->do_channel( this_object(), "chat",
	        		sprintf( "%s 请在紫阳楼上的豪杰吃饭，大家不要客气! \n", 
	        		me->query("name") ) );
		guest=all_inventory(environment(me));
	}
	if( arg=="all" )
	{
	        	CHANNEL_D->do_channel( this_object(), "chat",
	        		sprintf( "%s 请大家吃肉喝酒，大家不要客气! \n", 
	        		me->query("name") ) );
		guest=users();
	}
	
	for(i=0;i<sizeof(guest);i++)
	{                                              
		if( userp(guest[i]) )
		{
 			obj=new(__DIR__"obj/kaoya");
			obj->move(guest[i]);
			obj=new(__DIR__"obj/nverhong");
			obj->move(guest[i]);                                        
			if( guest[i] !=me )
				tell_object(guest[i], me->query("name")+"请你吃肉喝酒。\n");
		}
	}
	return 1;
}                                                                     

int ask_me()
{
	object who;
    	who=this_player();  
	
	write("本店承办各类酒席，分为高、中、低三档，
\n有 here 和 all两种规模，其中低档 5 gold 一桌，中档 10 gold 一桌，
\n赠送婚纱一套，高档 20 gold 一桌，赠送婚纱一套，另免费拍摄婚
\n纱照一套，每桌四人，请客官自行决定 (decide) 档次与规模。\n");

	return 1;
}
        
int accept_object(object who, object ob)
{
     	object me,obj;
     	string objname;

     	me = this_player();
     	objname = (string)ob->name();

        	if ( objname != "喜帖" )  	return 0;        

	if( !query("in_busy") )	return notify_fail("你来晚啦，婚礼已经结束啦。\n");      

	obj=new(__DIR__"obj/nverhong");
	obj->move(me);
	obj=new(__DIR__"obj/kaoya");
	obj->move(me);
	obj=new("/d/latemoon/npc/obj/food");
	obj->move(me);
	obj=new("/d/latemoon/npc/obj/food2");
	obj->move(me);

	return 1;
}
	
