//belt.c

#include <ansi.h>
#include <armor.h>

inherit WAIST;

void create()
{
	set_name(HIC"吹雪残云带"NOR, ({ "belt" }) );
	set_weight(100);
	set("no_get",1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "leather");
		set("unit", "条");
		set("value", 0);
		set("armor_prop/armor", 85);
		set("armor_prop/armor_vs_force",80);
	}
	setup();
}
