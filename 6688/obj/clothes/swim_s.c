// /obj/swim_s.c

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("游泳裤", ({ "swimshorts", "shorts" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("value", 1200);
                set("material", "cloth");
        }
        setup();
}
