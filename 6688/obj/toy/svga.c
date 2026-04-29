// /obj/toy/svga.c

inherit ITEM;

void create()
{
        set_name("显示卡", ({ "displaycard", "xianshika", "svga" }) );
        set_weight(180);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
        set("long","这是一块丽台图形加速卡.\n");
        set("value", 65000);
        }
}
