// /obj/toy/pticket.c

inherit ITEM;

void create()
{
        set_name("飞机票" , ({ "plane ticket", "ticket", "pticket1" }) );
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("long","这是一张飞往美国的单程机票.");
        set("value", 500000);
        }
}
