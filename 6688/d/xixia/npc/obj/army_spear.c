// spear.c

#include <weapon.h>

inherit SPEAR;

void create()
{
        set_name("军枪", ({ "spear" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "杆");
                set("value", 500);
                set("material", "iron");
                set("long", "这是一杆闪着寒光的军枪,锋利无比。\n");
                set("wield_msg", "$N抽出一杆明晃晃的$n握在双手。\n");
        }
        init_spear(20);
        setup();
}

