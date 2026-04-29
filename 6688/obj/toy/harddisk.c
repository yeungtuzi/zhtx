// /obj/toy/harddisk.c

inherit ITEM;

void create()
{
        set_name("硬盘", ({ "harddisk", "hdd" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "只");
        set("long","这是一只大脚硬盘.\n");
        set("value", 130000);
        }
}
