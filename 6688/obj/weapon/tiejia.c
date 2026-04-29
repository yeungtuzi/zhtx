// /obj/weapon/tiejia.c

#include <armor.h>

inherit ARMOR;

void create()
{
        set_name( "铁甲", ({ "armor", "tiejia", "jia" }));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("value", 1000);
                set("material", "iron");
                set("armor_prop/armor", 10);
        }
        setup();
}
