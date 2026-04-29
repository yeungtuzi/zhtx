
#include <weapon.h>

inherit THROWING;

void create()
{
	set_name("寒光", ({ "souhun zhen","zhen" }) );
	set("no_decrease",1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"一根细细的银针，发出蓝油油的光芒。\n");
		set("value", 0);
		set("unit","根");
		set("base_unit", "根");
		set("base_weight", 1);
		set("base_value", 1);
	}
	set("poison/amount",10000);
	set("poison/type","tm_poison");
	set_amount(1);
	init_throwing(99);
	setup();
}
