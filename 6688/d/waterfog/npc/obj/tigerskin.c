// suit.c
//
// This is the basic equip for players just login.

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("虎皮", ({ "tiger skin","skin"}) );
	set_weight(3000);
        set("value", 5000);
       	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "skin");
		set("armor_prop/armor", 40);
	}
	setup();
}
