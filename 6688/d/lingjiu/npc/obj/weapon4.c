#include <weapon.h>

//inherit HOOK;
inherit SWORD;

void create()
{
	set_name("铁钩", ({ "hook" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 10000);

		set("material", "steel");
	}
	init_sword(15);
//	init_hook(15);
	setup();
}
