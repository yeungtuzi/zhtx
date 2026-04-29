#include <weapon.h>

inherit THROWING;

void create()
{
	set_name("飞刀", ({ "knife" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "些");
		set("base_unit", "把");
		set("value", 10000);

		set("material", "steel");
	}
	init_throwing(15);
	set_amount(50);
	setup();
}
