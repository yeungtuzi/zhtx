#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("和服", ({ "cloth" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "件");
                set("value", 100);
                set("armor_prop/armor", 1);
        }
        setup();
}
