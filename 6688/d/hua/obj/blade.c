#include <weapon.h>
inherit BLADE;

void create()
{
	set_name("日本刀", ({  "blade" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一把日本刀。\n");
		set("unit", "把");
		set("value", 1000);
		set("material", "iron");
		set("wield_msg", "$N从腰间抽出了$n握在手中。\n");
		set("unequip_msg", "$N将手中的$n插入腰间。\n");
	}
	init_blade(35);
	setup();
}
