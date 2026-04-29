// /obj/food/zimizhou.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("籽米粥", ({"zi mizhou", "zhou" }) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一碗香喷喷冒着热气的籽米粥,快喝,否则就凉了!\n");
                set("unit", "碗");
                set("value", 50);
                set("food_remaining", 2);
                set("food_supply", 10);
                set("water_supply", 10);
        }

        setup();
}

void init()
{
        if( this_player()==environment() )
                add_action("do_eat", "eat");
                add_action("do_eat", "drink");

}

int do_eat(string arg)
{
        if( !arg || (arg != "zi mizhou" && arg !="zhou") )
return notify_fail("你要吃什么呢? \n");
//                if( !this_object()->id(arg) ) return 0;
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
  message_vision("$N几口就把碗里的籽米粥喝光了.\n",this_player());
        } else 
  message_vision("$N拿起碗来喝了一大口籽米粥.\n",this_player());
        return 1;
}

