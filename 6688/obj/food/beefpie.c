// /obj/food/beefpie.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("牛肉饼", ({"beefpie", "beef", "pie"}) );
        set_weight(60);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一块烙得焦黄,冒着香气的牛肉饼.\n");
                set("unit", "块");
                set("value", 100);
                set("food_remaining", 3);
                set("food_supply", 20);
        }
        setup();
}


