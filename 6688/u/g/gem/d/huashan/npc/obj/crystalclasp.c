#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
        set_name( HIC"水晶簪"NOR , ({ "crystal clasp","clasp" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "支");
                set("value", 1500);
                set("material", "crystal");
                set("armor_prop/armor", 1);
        set("wear_msg", "$N将$n拿出插在头发上。\n");
        }
        setup();
}
