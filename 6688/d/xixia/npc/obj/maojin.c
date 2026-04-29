#include <weapon.h>

inherit WHIP;

void create()
{
        set_name("毛巾", ({ "mao jin", "jin" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
                set("value", 100);
                set("material", "cloth");
        }
        init_whip(2);
        setup();
}
