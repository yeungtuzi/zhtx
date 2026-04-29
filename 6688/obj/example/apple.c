// /obj/example/apple.c

#include <weapon.h>

inherit THROWING;
//inherit F_FOOD;

void create()
{
	set_name("大苹果", ({ "apple", "big apple" }) );
//	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一半青一半红的富士大苹果.\n");
		set("unit", "个");
                set("base_unit", "个");
                set("base_weight", 350);
                set("base_value", 150);
		set("value", 150);
		set("food_remaining", 3);
		set("food_supply", 10);
                set("water_supply", 10);
//		set("material", "bone");
	}
        set_amount(1);
        init_throwing(7);
	setup();
}

void init()
{
        if( this_player()==environment() )
                add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        if( !arg || arg != "apple")  return notify_fail("你要吃什么呢? \n");
                if( query_amount() <1 ) return 0;
        if( !this_object()->id(arg) ) return 0;
        if( this_player()->is_busy() )
                return notify_fail("你上一个动作还没有完成.\n");
        if( !query("food_remaining") )
                return notify_fail( name() + "已经没什么好吃的了.\n");
        if( (int)this_player()->query("food") >= 
(int)this_player()->max_food_capacity() )
                return notify_fail("你已经吃太饱了,再也塞不下任何东西了.\n");
        this_player()->add("food", query("food_supply"));
if (query("water_supply")) this_player()->add("water", query("water_supply"));
        if( this_player()->is_fighting() ) this_player()->start_busy(2);

        // This allows customization of drinking effect.
        if( query("eat_func") ) return 1;

        set("value", 0);
        add("food_remaining", -1);
        if( !query("food_remaining") ) {
                message_vision("$N将剩下的" + name() + "吃得干干净净.\n", 
this_player());
                if( !this_object()->finish_eat() )
//                        destruct(this_object());
        add_amount(-1);

        } else 
         message_vision(
         "$N拿起大苹果来,狠狠地咬了一口.\n",this_player()  );
        return 1;
}

int finish_eat()
{
	if( !query("weapon_prop") ) return 0;
	set_name("苹果核", ({ "core" }) );
	set_weight(50);
	set("long", "大苹果吃完剩下的苹果核.\n");
	return 1;
}
