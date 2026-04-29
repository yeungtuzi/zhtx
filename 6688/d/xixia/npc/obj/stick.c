#include <weapon.h>

inherit STAFF;

void create()
{
        set_name("大铁杆", ({ "steel stick", "steel" }) );
        set_weight(40000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "杆");
                set("value", 500);
		set("rigidity", 40);
                set("material", "bronze");
                set("long", "这杆铁杆长一丈有八。\n");
                set("wield_msg", "$N将一杆$n抄在手中。\n");
        }
        init_staff(60);
        setup();
}
