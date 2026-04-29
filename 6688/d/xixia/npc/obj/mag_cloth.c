#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name(MAG"紫衫"NOR, ({ "mag dress", "dress" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("value", 1000);
		set("material", "cloth");
		set("armor_prop/armor", 5);
		set("armor_prop/personality", 1);
	}
	setup();
}
