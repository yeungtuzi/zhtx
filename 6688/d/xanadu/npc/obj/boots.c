//belt.c

#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
	set_name(HIG"穿花蛇影鞋"NOR, ({ "boots" }) );
	set_weight(100);
	set("no_get",1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "leather");
		set("unit", "双");
		set("value", 0);
		set("armor_prop/armor", 85);
		set("armor_prop/armor_vs_force",80);
	}
	setup();
}
