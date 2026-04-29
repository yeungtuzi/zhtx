//可以解fushi-du, by gem

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("糯米", ({ "nuo mi", "mi" }) );
	set_weight(160);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一块亮晶晶的糯米，在中原也许算不什么，但是在西夏可是很难得。\n");
		set("unit", "块");
		set("value", 50000);
		set("food_remaining", 3);
		set("food_supply", 20);
	}
}

int do_eat(string arg)
{
	if( !this_object()->id(arg) ) return 0;
	if( this_player()->is_busy() )
		return notify_fail("你上一个动作还没有完成。\n");
	if( !query("food_remaining") )
		return notify_fail( name() + "已经没什麽好吃的了。\n");
	if( (int)this_player()->query("food") >= (int)this_player()->max_food_capacity() )
		return notify_fail("你已经吃太饱了，再也塞不下任何东西了。\n");

	this_player()->add("food", query("food_supply"));
	if( this_player()->is_fighting() ) this_player()->start_busy(2);

	// This allows customization of drinking effect.
	if( query("eat_func") ) return 1;

	set("value", 0);
	add("food_remaining", -1);
	if( !query("food_remaining") ) {
		message_vision("$N将剩下的" + name() + "吃得乾乾净净。\n", this_player());
		if( !this_object()->finish_eat() )
			destruct(this_object());
	} else 
		message_vision("$N拿起" + name() + "咬了几口。\n", this_player());

	if (this_player()->query_condition("fushi-du")) {
		write("你感到全身舒服多了。\n");
		this_player()->clear_condition("fushi-du");
	}

	return 1;
}
