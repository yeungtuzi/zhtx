//by tlang

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIC"溪水"NOR);
	set("long", @LONG
	
LONG
        );
        setup();
}

void init()
{
	add_action("do_swim","swim");
}

int do_swim(string arg)
{
	object ob=this_player();

	if(!arg || arg=="" )
	{
		tell_object(ob,"你不知道往哪个方向游才好。\n");
		return 1;
	}
	if(arg=="center")
	{
		if(!ob->query_temp("swimming_center")
 	|| ob->query_temp("swimming_center")<5 )
		{
			if(ob->query_temp("swimming_outside")>=1)
			{
			ob->add_temp("swimming_outside",-1);
			ob->add_temp("swimming_center",1);
			message_vision("$N往中心的一个小岛游去。\n",ob);
				return 1;
			}
		ob->add_temp("swimming_center",1);
		message_vision("$N往中心的一个小岛游去。\n",ob);
			return 1;
		}
		message_vision("$N游到了小岛上。\n",ob);
		ob->delete_temp("swimming_center");
		ob->delete_temp("swimming_outside");
		ob->move("/d/hangzhou/h_river3");
			return 1;	
	}
	if(arg=="outside")
	{
		if(!ob->query_temp("swimming_outside") 
	|| ob->query_temp("swimming_outside")<5 )
		{ 
			if(ob->query_temp("swimming_center")>=1)
			{
			ob->add_temp("swimming_center",-1);
			ob->add_temp("swimming_outside",1);
			message_vision("$N往岸边游去。\n",ob);
				return 1;
			}
		ob->add_temp("swimming_outside",1);
		message_vision("$N往岸边游去。\n",ob);
			return 1;		
		}
		message_vision("$N游到了岸上。\n",ob);
		ob->delete_temp("swimming_outside");
		ob->delete_temp("swimming_center");
		ob->move("/d/hangzhou/h_river2");
		return 1;
	}
}