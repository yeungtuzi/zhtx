#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("宫女服", ({ "maid dress", "dress" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("value", 1000);
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("armor_prop/personality", 1);
	}
	setup();
}
