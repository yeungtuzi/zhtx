#include <armor.h>

inherit HEAD;

void create()
{
        set_name( "斗蓬",({ "cape" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long","一个黑色的斗蓬，把人罩住只露一双眼睛。\n");                
                set("material", "bronze");
                set("value",1000);
                set("armor_prop/armor", 5);
                set("wear_msg", "$N把一个斗蓬戴在头上。\n");
                set("unequip_msg", "$N轻轻地把$n从头上除了下来。\n");
        }
        setup();
}


