// /obj/weapon/dagger1.c : an example subweapon

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("短剑", ({ "dagger", "short sword", "sword" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把闪闪发光的短剑,剑柄上镶着紫色的宝石." +
                        "还刻着些花纹样的古怪文字.\n");
		set("value", 500000);
		set("material", "steel");
	}
	init_sword(25, SECONDARY);

// These properties are optional, if you don't set them, it will use the
// default values.

	set("wield_msg", "$N从怀中摸出一把$n握在手中。\n");
	set("unwield_msg", "$N将手中的$n藏入怀中。\n");

// The setup() is required.

	setup();
}
