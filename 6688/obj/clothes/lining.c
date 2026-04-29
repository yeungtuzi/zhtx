// /obj/clothes/lining.c

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("李宁服", ({ "lining suit", "sports suit", "suit" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "套");
                set("value", 12000);
                set("material", "cloth");
                set("armor_prop/armor", 1);
        }
        setup();
}
