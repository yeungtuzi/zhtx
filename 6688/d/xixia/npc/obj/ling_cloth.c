#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("素绸衫", ({ "white cloth", "cloth" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这件衣服是用上好的绸缎做的，还镶着红边。\n");
		set("unit", "件");
		set("value", 6000);
		set("material", "cloth");
		set("armor_prop/armor", 8);
		set("armor_prop/personality", 5);
	}
	setup();
}
