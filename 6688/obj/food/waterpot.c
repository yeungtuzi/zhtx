// /obj/food/waterpot.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("水壶", ({ "water pot", "pot" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一个加大容积的铁皮水壶,能装两升多水.\n");
                set("unit", "个");
                set("value", 50);
                set("max_liquid", 10);
        }

        // The liquid contained in the container is independent, we set a copy
        // in each cloned copy.
        set("liquid", ([
                "name": "清水",
                "remaining": 10,
        ]) );
}
