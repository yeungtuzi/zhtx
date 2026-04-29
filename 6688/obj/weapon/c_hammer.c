#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("比武用锤", ({ "hammer" }) );
        set_weight(9000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 50);
                set("material", "steel");
                set("long","这是一把专供比武用的铁锤\n");
                set("wield_msg", "$N抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插入腰间的束带间。\n");
        }
	init_hammer(15);
        setup();
}
