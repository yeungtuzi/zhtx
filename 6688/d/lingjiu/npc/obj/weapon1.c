#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("单刀", ({ "blade" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 10000);

		set("material", "steel");
	}
	init_blade(15);
	setup();
}
