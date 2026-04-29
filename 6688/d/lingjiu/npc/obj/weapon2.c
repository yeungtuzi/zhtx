#include <weapon.h>

inherit WHIP;

void create()
{
	set_name("长鞭", ({ "whip" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 10000);

		set("material", "silk");
	}
	init_whip(15);
	setup();
}
