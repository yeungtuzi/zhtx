// w_cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>

inherit CLOTH;

void create()
{
    set_name("青色长袍", ({ "cyn_cloth","cloth" }) );
    set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
         set("unit", "件");
         set("material", "cloth");
         set("armor_prop/armor", 4);
         set("armor_prop/personnality",1);
         set("value",1000);
         set("male_only",1);
	}
	setup();
}

