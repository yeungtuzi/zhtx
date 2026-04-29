// /obj/toy/candle.c

inherit ITEM;

void create()
{
       set_name("蜡烛", ({ "candle", "lazhu", "la", "zhu" }) );
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "支");
                set("long","这是一支普普通通的蜡烛.\n");
        set("value", 10);
        }
}
