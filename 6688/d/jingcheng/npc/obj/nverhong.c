#include <ansi.h>  

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name(RED"女儿红"NOR, ({"nuer hong", "jiu", "wine" }));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", WHT"据说这酒是在女儿出生时就埋在窖里, 专等结婚时取出宴请贵宾的。\n"NOR);
                set("unit", "坛");
                set("value", 1000);
                set("remaining", 3);
                set("drink_supply", 50);
                set("max_liquid", 50);
        }
	setup();
}

void init()
{
	add_action("do_drink", "drink");
}


int do_drink(string arg)
{	
    if( !this_object()->id(arg) ) return 0;
    if( this_player()->is_busy() )
        return notify_fail("你上一个动作还没有完成。\n");
    if(   (int)this_player()->query("water")
       >= (int)this_player()->max_water_capacity() )
     return notify_fail("你已经喝太多了，再也灌不下一滴酒了。\n");

    this_player()->add("water", (int)query("drink_supply"));

 
    add("remaining", -1);
	if ( query("remaining") )
	{
   		 message_vision("$N斟满一杯女儿红，一口喝了下去。\n"+
      		"$N哈哈大笑, 拱手道:恭喜, 恭喜!\n", this_player());
	} else 
	{ 
   		 message_vision("$N捧起酒坛，把剩下的女儿红一饮而尽。\n"+
      		"$N放声大笑: 痛快, 痛快...\n", this_player());
		
		destruct(this_object());
	}

	return 1;
}
