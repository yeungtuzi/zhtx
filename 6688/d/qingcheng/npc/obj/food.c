
/*food.c*/


inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("便当", ({ "food" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一份做的很好的便当，但好像有点凉了。\n");
                set("unit", "份");
                set("value", 50);
                set("food_remaining", 5);
                set("food_supply", 50);
              
        }
        setup();
}

                      