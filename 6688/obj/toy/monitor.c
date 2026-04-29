// /obj/toy/monitor.c

inherit ITEM;

void create()
{
        set_name("显示器", ({ "monitor", "crt", "screen" }) );
        set_weight(12000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "台");
        set("long","这是一台15寸平面方角philips显示器,不过是深圳装的.\n");
        set("value", 150000);
        }
}
