// /obj/clothes/rollshoe.c

#include <armor.h>

inherit BOOTS;

void create()
{
        set_name( "旱冰鞋", ({ "roll shoes", "shoes" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "双");
                set("value", 12800);
                set("material", "fur");
                set("armor_prop/armor", 1);
                set("armor_apply/dodge", 5);
        }
        setup();
}
