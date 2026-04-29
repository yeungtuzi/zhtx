// lingzhi.c

inherit ITEM;
inherit F_FOOD;
#include <ansi.h>
void do_eat(string arg);
void create()
{
	set_name(HIM"灵芝"NOR, ({ "ling zhi","zhi","agaric" }) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一棵约百年的灵芝，长形非常好，看来是个宝贝。\n");
		set("unit", "棵");
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
	if(arg=="he shou wu"||arg=="shouwu")
	{
		if((this_player()->max_food_capacity()-this_player()->query("food"))<300)
			return notify_fail("你太饱了，吃不下这根灵芝。\n");
		if(this_player()->query("max_atman")<500)
		{
			if(!random(30))
			{
				this_player()->add("max_atman",random(4));
				tell_object(this_player(),"你一边咀嚼着这棵灵芝，一边把灵芝的精华纳入全身经脉。\n");
				
			}
		}
		message_vision("只见$N把这根灵芝吃了下去，似乎精神为之一振。\n",this_player());
		if(this_player()->query("atman")<this_player()->query("max_atman"))
			this_player()->set("atman",this_player()->query("max_atman"));
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