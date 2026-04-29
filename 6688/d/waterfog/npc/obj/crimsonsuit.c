// suit.c
//
// This is the basic equip for players just login.

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("鲜红锦衣", ({ "Crimson suit","suit"}) );
	set_weight(3000);
        set("value", 50);
       	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
		set("armor_prop/armor", 10);
	}
	setup();
}
