#include <weapon.h>
inherit SPEAR;

void create()
{
	set_name("红缨枪", ({  "spear" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一杆红缨枪\n");
		set("unit", "杆");
		set("value", 100);
		set("material", "iron");
		set("wield_msg", "$N将$n握在手中。\n");
		set("unequip_msg", "$N将$n背在身后。\n");
	}
	init_spear(15);
	setup();
}
