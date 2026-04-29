// /obj/toy/iron.c
// iron.c : an example weapon

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("烙铁", ({ "iron" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把烧红的电烙铁\n");
		set("value", 400);
		set("material", "steel");
		set("wield_msg", "$N拿出一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n放在烫不着自己的地方。\n");
	}
	init_sword(25);
	setup();
}
