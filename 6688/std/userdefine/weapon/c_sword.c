
#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("「剑」", ({ "sword" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄武者常用的兵器。\n");
		set("value", 0);
		set("unpawnable",1);
		set("no_get",1);		
		set("no_drop",1);		
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回剑鞘。\n");
	}
	init_sword(15);
	setup();
}
