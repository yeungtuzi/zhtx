#include <weapon.h>

inherit THROWING;

void create()
{
	set_name("绣花针", ({ "needle" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("base_unit", "枚");
		set("unit", "些");
                set("value", 1);

		set("material", "steel");
	}
        set_amount(50);
	init_throwing(15);
        set("unpawnable", 1);
	setup();
}
