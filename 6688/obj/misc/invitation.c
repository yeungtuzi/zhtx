// invitation.c
//writteb by tang

#include <ansi.h>

inherit ITEM;

void create()
{
        	set_name("请帖", ({"invitation"}) );
	set("long","朋友请你去作客(zuoke)的请帖\n");
        	set_weight(10);                   

        	if( clonep() )
                	set_default_object(__FILE__);
        	else 
	{
                	set("unit", "封");             
	set("no_sell",1);
                	set("material", "paper");
        	}
}

void init()
{
        	add_action("do_gohome", "zuoke" );
}                                                                                  

int do_gohome()
{                                
	string arg;		
	
	if( file_name(environment(this_player()))!="/d/road/kaifeng" )
		return notify_fail("主人家不在附近。\n");

	arg=query("roomid");
	if( file_size("/data/room/"+arg+".c") <1 )            
	{
		destruct(this_object());
		tell_object(this_player(),"主人的家被毁了。\n");	         
		return 1;
	}

	message_vision("$N去朋友家作客了。\n",this_player());
	this_player()->move("/data/room/"+arg);
	message_vision("$N说道:「我来作客啦。」\n",this_player());

	destruct(this_object());
	return 1;
}

void owner_is_killed() 
{ 
	destruct(this_object()); 
}                                           

