// /obj/food/roujiamo.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("肉夹馍", ({"rou jia mo", "mo" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一个香喷喷冒着热气的陕西风味肉夹馍.\n");
                set("unit", "个");
                set("value", 80);
                set("food_remaining", 3);
                set("food_supply", 20);
        }
        setup();
}

