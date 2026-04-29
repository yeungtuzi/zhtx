// /obj/clothes/necklace.c

#include <armor.h>

inherit NECK;

void create()
{
        set_name( "项链", ({ "necklace" }) );
        set_weight(40);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
                set("long", "一条镀金项链.\n");
                set("value", 2000);
                set("armor_prop/personality", 1);
                set("female_only", 1);
        }
        setup();
}
