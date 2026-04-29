#include <weapon.h>

inherit WHIP;

void create()
{
        set_name("铁爪", ({ "iron claw", "tiezhao"}) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 600);
                set("material", "iron");
        }
        init_whip(42);
        setup();
}
