#include <weapon.h>
#include <ansi.h>

inherit STAFF;

void create()
{
        set_name(HIW"钢杖"NOR, ({ "steel staff", "staff" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("value", 50000);
		set("rigidity", 20);
                set("material", "steel");
                set("wield_msg", "$N将一杆$n抄在手中。\n");
        }
        init_staff(90);
        setup();
}
