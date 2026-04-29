// gangdao.c

#include <weapon.h>
inherit AXE;

void create()
{
	set_name("斧头", ({ "blade" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long","这是一柄斧头。\n");
		set("value", 0);
		set("material", "steel");
		set("unpawnable",1);
		set("no_get",1);		
		set("no_drop",1);
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回刀鞘。\n");
	}
	init_axe(15);        
	setup();
}   

