// /obj/food/hamburg.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("汉堡包", ({ "hamburger" }) );
        set_weight(88);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一个冒热气的汉堡包.\n");
                set("unit", "个");
                set("value", 250);
                set("food_remaining", 3);
                set("food_supply", 18);
        }
        setup();
}

