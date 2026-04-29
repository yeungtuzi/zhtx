#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("丝衣", ({ "silk dress", "dress"}) );
	set_weight(1100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("value", 10000);
		set("material", "silk");
		set("armor_prop/armor", 1);
		set("armor_prop/personality", 3);
		set("armor_prop/dodge", 5);
		set("female_only", 1);
	}
	setup();
}
