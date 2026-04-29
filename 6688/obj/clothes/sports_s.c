// /obj/clothes/sports_s.c

#include <armor.h>

inherit BOOTS;

void create()
{
        set_name( "运动鞋", ({ "sports shoes", "shoes" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "双");
                set("value", 2800);
                set("material", "fur");
                set("armor_prop/armor", 1);
                set("armor_apply/dodge", 3);
        }
        setup();
}
