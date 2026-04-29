// /obj/example/chaofen.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("炒粉", ({ "chao fen", "chaofen", "fen" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一盘热腾腾香喷喷的炒米粉.\n");
                set("unit", "盘");
                set("value", 100);
                set("food_remaining", 2);
                set("food_supply", 15);
        }
}
