#include <weapon.h>

inherit DAGGER;

void create()
{
	set_name("匕首", ({ "dagger" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 10000);

		set("material", "steel");
	}
	init_dagger(15);
	setup();
}
