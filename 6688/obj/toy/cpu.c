// /obj/toy/cpu.c

inherit ITEM;

void create()
{
        set_name("CPU", ({ "cpu" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
        set("long","这是一个CPU,上面印着intel inside,不过有点儿象是\n" +
                "remark过的.\n");
        set("value", 175000);
        }
}


