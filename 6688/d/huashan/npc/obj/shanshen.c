// shanshen.c

inherit ITEM;
inherit F_FOOD;
#include <ansi.h>
void do_eat(string arg);
void create()
{
	set_name(HIW"老山参"NOR, ({ "lao shanshen","shen","ginseng" }) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一根约半尺长的老山参，很珍贵的。\n");
		set("unit", "根");
		set("value", 300000);
		set("food_remaining", 1);
		set("food_supply", 500);
	}
}

void init()
{
	add_action("do_eat","eat");
}
int do_eat(string arg)
{
	if(!arg||arg=="")
		return notify_fail("你要吃什么？\n");
	if(arg=="ginseng"||arg=="lao shanshen"||arg=="shen"||arg=="shanshen")
	{
		if((this_player()->max_food_capacity()-this_player()->query("food"))<300)
			return notify_fail("你太饱了，吃不下这根老山参。\n");
		if(this_player()->query("max_force")<2500)
		{
			if(!random(30))
			{
				this_player()->add("max_force",2);
				tell_object(this_player(),"你一边咀嚼着这根老山参，一边把老山参的精华纳入全身经脉。\n");
				
			}
		}
		message_vision("只见$N把这根老山参吃了下去，似乎精神为之一振。\n",this_player());
		if(this_player()->query("force")<this_player()->query("max_force"))
			this_player()->set("force",this_player()->query("max_force"));
		this_player()->add("food",300);
		this_player()->start_busy(1);
		remove_call_out("destroy");
		call_out("destroy",1,this_object());
		return 1;
	}
	return notify_fail("你要吃什么？\n");
}

void destroy(object ob)
{
	destruct(ob);
}