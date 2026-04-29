//goldencloth.c
//by masterall

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(HIC"青衫"NOR, ({ "cyan cloth", "cloth" }) );
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",
                        HIC"这是一件普通的青衫，没社么特别的。\n"NOR);
                set("unit", "件");
                set("no_drop","这件宝贝这么珍贵你怎么舍得扔了卖了？也不能给别人。");
                set("no_sell",1);
                set("unpawnable",1);
                set("value", 10000);
                set("material", "gold");
                set("armor_prop/armor", 100);
                set("armor_prop/armor_vs_force", 100);
                set("armor_prop/attack", 50);
                set("armor_prop/personality", 15);
        }
        setup();
}

