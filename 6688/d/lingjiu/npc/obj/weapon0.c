#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("长剑", ({ "sword" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 10000);

		set("material", "steel");
	}
	init_sword(15);
	setup();
}
