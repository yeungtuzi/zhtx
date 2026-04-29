//random blace
//by meteoric
#include <ansi.h>
#include "/ldg/std/adv_weapon.h"

inherit ADV_BLADE;

void create()
{
	set_name("刀", ({ "blade" }) );
	set_weight(100);
	set("random",1);
	set("unit", "把");
	set("material", "steal");
	set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
	set("unwield_msg", "$N将手中的$n插入腰间的刀鞘。\n");
	init_blade(25);
	setup();
}
