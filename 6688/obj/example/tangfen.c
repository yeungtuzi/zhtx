// /obj/example/tangfen.c


inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("汤粉", ({ "tang fen", "tangfen", "fen" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一碗热得烫手的汤粉.\n");
                set("unit", "碗");
                set("value", 100);
                set("food_remaining", 1);
                set("food_supply", 15);

                set("water_supply", 15);
              }
        setup();
}

void init()
{
        if( this_player()==environment() ) {
                add_action("do_eat", "eat");
                add_action("do_eat", "drink");
                }                
}

int do_eat(string arg)
{
    if( !arg || ((arg != "tang fen") && (arg!= "fen") && (arg!="tangfen")))
          return notify_fail("你要吃什么呢? \n");
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
  message_vision(
"$N几口就把碗里的汤粉吃光了,连汤也喝得精光,烫得直吐舌头.\n",this_player());
        } else 
  message_vision(
"$N几口就把碗里的汤粉吃光了,连汤也喝得精光,烫得直吐舌头.\n",this_player());
        return 1;
}
