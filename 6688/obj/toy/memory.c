// /obj/toy/memory.c

inherit COMBINED_ITEM;

void create()
{
        set_name("内存", ({ "memory", "ram" }) );
//        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "对");
        set("long","这是一条16M,EDO内存条,一般的机器要装两条.\n");
        set("base_unit", "条");
        set("base_value",30000);
        set("base_weight", 20);
        set_amount(2);
        }
}
