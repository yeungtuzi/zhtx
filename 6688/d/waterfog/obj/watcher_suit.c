// watcher_suit.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("□□跨侗岈墓", ({ "watcher suit", "suit" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "璃");
		set("material", "cloth");
		set("value", 2000);
		set("armor_prop/armor", 4);
	}
	setup();
}
