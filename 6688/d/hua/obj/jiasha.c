// jiasha.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("木棉袈裟", ({ "jiasha" }) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这是一件希世珍品。\n");
		set("unit", "件");
		set("value", 10000000);
		set("material", "cloth");
		set("armor_prop/armor", 1000);
		set("armor_prop/attack", 100);
                set("armor_prop/personality", 100);
                set("armor_prop/intelligence", 100);
                set("armor_prop/composure", 100);
	}
	setup();
}
