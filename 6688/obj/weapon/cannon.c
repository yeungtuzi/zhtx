// /obj/weapon/cannon.c 
// an example weapon

#include <weapon.h>

inherit CANNON;

void create()
{
	set_name("加农炮", ({ "cannon", "gun" }) );
// normally 100kg is still too light for a cannon
	set_weight(100000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "门");
		set("long", 
"这是一门加农炮,似乎不是步兵用的武器,而是装在一些车辆上的装备.\n");
		set("value", 4000000);
		set("material", "steel");
	}
	init_cannon(250);

// These properties are optional, if you don't set them, it will use the
// default values.
                set("wield_msg", "$N把$n握在手中,打开保险,准备射击.\n");
                set("unequip_msg", "$N合上$n的保险,背在背上.\n");

// The setup() is required.

	setup();
}
