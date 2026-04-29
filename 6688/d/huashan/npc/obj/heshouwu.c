// heshouwu.c

inherit ITEM;
inherit F_FOOD;
#include <ansi.h>
void do_eat(string arg);
void create()
{
	set_name(BLK"何首乌"NOR, ({ "he shou wu","shouwu", }) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一棵约百年的何首乌，虽没有成型，但是也很难得了。\n");
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
			return notify_fail("你太饱了，吃不下这根何首乌。\n");
		if(this_player()->query("max_mana")<500)
		{
			if(!random(30))
			{
				this_player()->add("max_mana",random(4));
				tell_object(this_player(),"你一边咀嚼着这棵何首乌，一边把何首乌的精华纳入全身经脉。\n");
				
			}
		}
		message_vision("只见$N把这根何首乌吃了下去，似乎精神为之一振。\n",this_player());
		if(this_player()->query("mana")<this_player()->query("max_mana"))
			this_player()->set("mana",this_player()->query("max_mana"));
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