
/* knife.c*/

#include <weapon.h>

inherit DAGGER;

void create()
{
        set_name("碧玉刀", ({ "knife" }) );
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一把晶莹剔透的碧玉刀。\n");
                set("unit", "把");
                set("value", 600);
              
                set("wield_msg", "$N抽出一把$n，握在手中当武器。\n");
                set("material", "steel");
        }
        init_dagger(8);
        setup();
}

