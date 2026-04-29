#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("一袭深情蝶衣轻", ({ "white dress", "dress" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("value", 6000);
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("armor_prop/personality", 10);
	}
	setup();
}
