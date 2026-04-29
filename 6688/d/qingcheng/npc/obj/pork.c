
/*pork.c*/


inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("山猪肉", ({ "pork" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一块很好的山猪肉。\n");
                set("unit", "块");
                set("value", 50);
                set("food_remaining", 5);
                set("food_supply", 50);
                set("material", "bone");
        }
        setup();
}

int finish_eat()
{
        if( !query("weapon_prop") ) return 0;
        set_name("啃得精光的山猪骨头", ({ "pine" }) );
        set_weight(150);
        set("long", "一根啃得精光的山猪骨头。\n");
        return 1;
}
                       