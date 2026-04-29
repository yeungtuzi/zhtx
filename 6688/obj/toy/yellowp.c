// /obj/toy/yellowp.c

inherit ITEM;

void create()
{
        set_name("黄色通行证", ({ "yellow pass", "pass", "ypass", "yellowp" }));
        set_weight(2);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("long","这是一张黄色通行证,不知道作什么用处的.\n");
        set("value", 1);
        }
}
