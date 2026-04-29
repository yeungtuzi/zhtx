#include <weapon.h>

inherit STAFF;

void create()
{
        set_name("打狗棒", ({ "dagou bang", "staff", "stick" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("value", 50);
                set("material", "bamboo");
                set("wield_msg", "$N将一杆$n抄在手中。\n");
        }
        init_staff(15);
        setup();
}
