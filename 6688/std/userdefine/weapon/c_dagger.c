#include <weapon.h>

inherit DAGGER;

void create()
{
        set_name("比武用匕", ({ "dagger" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 50);
                set("material", "steel");
                set("long","这是一把武者自己打造的匕首\n");
                set("wield_msg", "$N抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插入腰间的束带间。\n");
        }
	init_dagger(15);
        setup();
}
