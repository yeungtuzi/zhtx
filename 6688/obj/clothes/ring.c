// /obj/clothes/ring.c

#include <armor.h>

inherit FINGER;
void create()
{
        set_name("戒指", ({ "ring" }) );
        set_weight(30);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "枚");
                set("value", 3000);
                set("material", "iron");
                set("long", "一枚镀金戒指.\n");
                set("armor_prop/personality", 1);
        }
        setup();
}
