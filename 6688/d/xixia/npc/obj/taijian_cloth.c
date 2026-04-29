#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("太监服", ({ "cloth" }) );
	set_weight(1100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("value", 600);
		set("material", "cloth");
		set("armor_prop/armor", 1);
	}
	setup();
}
