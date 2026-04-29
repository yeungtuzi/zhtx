//random staff
//by meteoric
#include <ansi.h>
#include "/ldg/std/adv_weapon.h"

inherit ADV_STAFF;

void create()
{
	set_name("杖", ({ "staff" }) );
	set_weight(100);
	set("random",1);
	set("unit", "根");
        set("material", "steal");
        init_staff(25);
        set("wield_msg", "$N把$n紧紧地握在手中。\n");
        set("unwield_msg", "$N松开了手中的$n。\n");
	setup();
}