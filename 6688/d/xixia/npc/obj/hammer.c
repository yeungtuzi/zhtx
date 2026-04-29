#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("八角铜锤", ({ "octangular hammer", "hammer" }) );
        set_weight(40000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 500);
                set("material", "bronze");
		set("rigidity", 40);
                set("long", "这柄铜锤形大如斗。\n");
                set("wield_msg", "$N猛吸一口气，将一柄$n握在手中。\n");
        }
        init_hammer(60);
        setup();
}
