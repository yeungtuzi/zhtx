// /obj/weapon/luncher.c 
// an example weapon

#include <weapon.h>

inherit LUNCHER;

void create()
{
	set_name("火箭筒", ({ "luncher", "rocket luncher" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "支");
		set("long", 
"这是一支反坦克火箭筒,当然不是只能用来打坦克,打人也一样厉害.\n");
		set("value", 4000);
		set("material", "steel");
	}
	init_luncher(150);

// These properties are optional, if you don't set them, it will use the
// default values.
                set("wield_msg", "$N把$n握在手中,打开保险,准备射击.\n");
                set("unequip_msg", "$N合上$n的保险,背在背上.\n");

// The setup() is required.

	setup();
}
