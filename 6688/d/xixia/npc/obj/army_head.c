// cloud_armor

#include <armor.h>

inherit HEAD;

void create()
{
        set_name( "战盔",({ "army head","head" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long","一个青铜头盔\n");                
                set("material", "bronze");
                set("value",1000);
                set("armor_prop/armor", 5);
                set("wear_msg", "$N把一个头盔戴在头上。\n");
                set("unequip_msg", "$N轻轻地把$n从头上除了下来。\n");
        }
        setup();
}


