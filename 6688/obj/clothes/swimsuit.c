// /obj/swimsuit.c
// swimsuit for girls only

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("游泳衣", ({ "swimsuit", "suit" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("value", 3000);
                set("material", "cloth");
                set("armor_prop/personality", 2);
                set("female_only", 1);
        }
        setup();
}
