// /obj/example/rice.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("米饭", ({ "rice" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "二两一碗的米饭,男生吃的话,怎么也得两碗才能饱.\n");
                set("unit", "碗");
                set("value", 20);
                set("food_remaining", 1);
                set("food_supply", 20);
        }
        setup();
}

