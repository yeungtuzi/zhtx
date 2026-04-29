// jinyi.c
// wriiten by tang

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("锦衣", ({ "jinyi" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
		set("armor_prop/armor", 5);
	}
	setup();
}
