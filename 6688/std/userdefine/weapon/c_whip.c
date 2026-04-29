// whip.c

#include <weapon.h>

inherit WHIP;

void create()
{
    set_name( "比武用鞭", ({ "whip" }) );
    set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
        set("value", 50);
                set("material", "steel");
                set("rigidity", 70);
                set("wield_msg", "$N从腰间解下一条$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n缠回腰间。\n");
                set("long","一条武者自己打造的长鞭\n");

        }
        init_whip(15);
        setup();
}
