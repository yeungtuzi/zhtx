// /obj/food/pepsi.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("百事可乐", ({ "pepsi" }) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一杯冰镇的百事可乐.\n");
                set("unit", "杯");
                set("value", 110);
                set("food_remaining", 2);
                set("water_supply", 35);
        }

        setup();
}

void init()
{
        if( this_player()==environment() )
                add_action("do_eat", "drink");

}

int do_eat(string arg)
{
        if( !arg || arg != "pepsi")return notify_fail("你要喝什么呢? \n");
                if( !this_object()->id(arg) ) return 0;
        if( this_player()->is_busy() )
                return notify_fail("你上一个动作还没有完成.\n");
        if( !query("food_remaining") )
                return notify_fail( name() + "已经没什么好喝的了.\n");
        if( (int)this_player()->query("water") >= 
(int)this_player()->max_water_capacity() )
                return notify_fail("你已经喝得太多,再也喝不下一滴水了.\n");

if (query("water_supply")) this_player()->add("water", query("water_supply"));
        if( this_player()->is_fighting() ) this_player()->start_busy(2);

        // This allows customization of drinking effect.
        if( query("eat_func") ) return 1;

        set("value", 0);
        add("food_remaining", -1);
        if( !query("food_remaining") ) {
  message_vision("$N几口就把杯中的百事喝光了.\n",this_player());
        } else 
  message_vision("$N拿起装百事可乐的纸杯来,喝了一大口.\n",this_player());
        return 1;
}


