//zhuting.c
//written by tang

#include <ansi.h> 
inherit NPC;

void create()
{
	set_name(RED "朱亭" NOR, ({ "zhu ting","zhu" }) );
	set("nickname", YEL "老板" NOR);
	set("gender", "男性" );
	set("age", 45);
	set("long", "专门给已婚夫妇盖房子的木匠师傅。\n");
	set("combat_exp", 10000);
	set("attitude", "friendly");
	set("inquiry", ([
		"房子" : MAG"你找对人啦，我就是专门给已婚夫妇盖房子的。\n"NOR,
		]) );
	set_skill("literate", 70);
	set_skill("dodge", 500);
	set_skill("unarmed", 300);
	setup();
	add_money("silver", 5);
}

void init()
{
	add_action("do_mkroom", "makeroom");

}

int do_mkroom()
{
	string arg,argg,cardname,target,file,filename;
	object me,you,obj,paper;
	object house;

	seteuid(getuid());

	if( is_busy() )	return notify_fail("别急，慢慢来。\n");             
                        
	me=this_player();

	if( !me->query("is_married") )	
		return notify_fail("你还没有结婚，居无定所，还不需要买房！\n");
	if( !present("marrycard", me) )	
		return notify_fail("你没有结婚证，还不能买房！\n");

	cardname = present("marrycard",me)->query("name");

	if (sscanf(cardname,"你和%s的婚约" ,target)!=1)
                	return notify_fail("你还没有伴侣，不必买房。\n");

	arg=me->query("id")+"_"+target;
	argg=target+"_"+me->query("id");

	if( file_size(USER_ROOM_DATA_DIR+arg[0..0]+"/"+arg+".c")>1 )
	{
		me->set("room/buy",1);
		me->set("room/id",arg);
	}
	if( file_size(USER_ROOM_DATA_DIR+argg[0]+"/"+argg+".c")>1 )
	{
		me->set("room/buy",1);
		if( file_size(USER_ROOM_DATA_DIR+arg[0..0]+"/"+arg+".c")>1 )	rm(USER_ROOM_DATA_DIR+arg[0..0]+"/"+arg+".c");
		me->set("room/id",argg);
	}

	if( me->query("room/buy") )
	{
		if( me->query("room/id" )==arg || me->query("room/id" )==argg )                           
		{   
			if( obj=present("indenture",me) )
			{
				if( !(me->query("marry_time")) )	me->set("marry_time",me->query("age"));
				return notify_fail("你已经买过房了，房契就在你身上。\n");
			}
			else
			{
				switch (MONEY_D->player_pay(me, 10000) )
				{
					case 0:
						return notify_fail("你的钱不够手续费！”\n");
					case 2:
						return notify_fail("朱亭赔笑道：“您的黄金不够了，银票又没人找得开。”\n");
					default:
						;
				}
				if( !(me->query("marry_time")) )	me->set("marry_time",me->query("age"));
	               		paper = new("/adm/npc/indenture");
	       			paper->set("name","你和"+target+"的房契");
				paper->move(me);
				message_vision("$n递给$N一张薄纸，说:「这是给你补的房契。」\n", me, this_object());
				return 1;
			}
		}                                                
		else
		{	
			destruct(present("marrycard", me));
			return notify_fail("这不是你的婚卡，我扣下了！\n");
		}
	}

	if( !objectp(you=present(target,environment(me))) || !userp(you) )
		return notify_fail("你伴侣不在身边，不能买房。\n");          

        if( ((int)me->query("wlshw")+(int)you->query("wlshw")) < 5 )
                return notify_fail("你们小两口的武林声望不够，不能买房。\n");
	obj=find_player(target);    

	switch (MONEY_D->player_pay(me, 1000000) )
	{
	case 0:
		return notify_fail("你的钱不够买房！”\n");
	case 2:
		return notify_fail("朱亭赔笑道：“您的黄金不够了，银票又没人找得开。”\n");
	default:
		;
	}
                             
	start_busy(2);                          

	file=USER_ROOM_DATA_DIR+arg[0..0]+"/"+arg+".c";
	//创建目录
	if( file_size(USER_ROOM_DATA_DIR+arg[0..0]) != -2 )
	{
		if(!mkdir(USER_ROOM_DATA_DIR+arg[0..0]))
			return notify_fail("无法创建目录，请与巫师联系。目录名称是"+USER_ROOM_DATA_DIR+arg[0..0]+"/\n");		
	}	
	
	if( !write_file(file,read_file(USER_ROOM),1) )
		 return notify_fail("你没有写入档案(" + file +")的权利。\n");       

	load_object(file);
	if( !objectp( house = find_object(file) ) )
		return notify_fail("无法载入你的房间，请与巫师联系。你的房间编号是"+arg+"\n");
	
	house->set("short",me->query("name")+"和"+you->query("name")+"的家");
	house->set("owner",arg);
	house->save();			
        
	paper = new("/adm/npc/indenture");
       	paper->set("name","你和"+target+"的房契");
       	paper->move(me);                                                           

	paper = new("/adm/npc/indenture");
       	paper->set("name","你和"+me->query("id")+"的房契");
       	paper->move(obj);
        
        me->set("wlshw",(int)me->query("wlshw")-5);
        if( me->query("wlshw") < 0 )
        {
        	you->add("wlshw",me->query("wlshw"));
        	me->delete("wlshw");
        }	                    
        
	if( obj->query("room/id")==arg || obj->query("room/id")==argg )
		arg=obj->query("room/id");	

	me->set("room/id", arg);
	me->set("room/buy", 1);
	me->set("marry_time", me->query("age"));

   	obj->set("room/id", arg);
	obj->set("room/buy", 1);
	obj->set("marry_time", obj->query("age"));
	
	message_vision("朱亭给$N"+"和"+obj->name()+"一张薄纸，说:「这是你们的房契。」\n", me);
	message_vision("现在，你们可以去看看你们的新房了！\n", me);	
	me->save();
	obj->save();                                               
	me->move(house);
	you->move(house);
	return 1;
}

