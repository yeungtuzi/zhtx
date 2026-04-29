#include <weapon.h>

inherit WHIP;

void create()
{
	set_name("羊鞭", ({ "sheep whip", "whip" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 100);

		set("material", "silk");
	}
	init_whip(5);
	setup();
}
