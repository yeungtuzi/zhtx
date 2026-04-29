// /obj/food/pommes_f.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("炸薯条", ({ "pommes frites", "shu tiao", "potato" }) );
        set_weight(77);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一包香喷喷的炸薯条.\n");
                set("unit", "包");
                set("value", 150);
                set("food_remaining", 6);
                set("food_supply", 10);
        }
        setup();
}
