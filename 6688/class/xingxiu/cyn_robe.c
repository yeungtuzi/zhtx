#include <armor.h>

inherit CLOTH;

void create()
{
    set_name("青色道袍", ({ "cyn robe","robe" }) );
    set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
         set("unit", "件");
         set("material", "cloth");
         set("armor_prop/armor", 4);
         set("armor_prop/personnality",1);
         set("value",5000);
         set("male_only",1);
	}
	setup();
}
