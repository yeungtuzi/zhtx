// /obj/toy/cddrive.c

inherit ITEM;

void create()
{
        set_name("光驱", ({ "cddrive", "guangqu" }) );
        set_weight(400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "只");
        set("long","这是一只八速光驱,印着8x字样.\n");
        set("value", 45000);
        }
}
