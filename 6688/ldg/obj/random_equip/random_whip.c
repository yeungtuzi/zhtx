//random staff
//by meteoric
#include <ansi.h>
#include "/ldg/std/adv_weapon.h"

inherit ADV_WHIP;

void create()
{
	set_name("鞭", ({ "whip" }) );
	set_weight(100);
	set("random",1);
	set("unit", "条");
        set("value", 30000);
        set("material", "steal");
        init_whip(25);
        set("wield_msg", "$N从腰间摸出一条$n握在手中。\n");
        set("unwield_msg", "$N将手中的$n束在腰间。\n");
	setup();
}