// /obj/toy/floppy.c

inherit ITEM;

void create()
{
        set_name("软驱", ({ "floppydisk", "fdd" }) );
        set_weight(240);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "只");
        set("long","这是一只3.5寸软驱.\n");
        set("value", 9000);
        }
}
