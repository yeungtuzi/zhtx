// /class/xiaoyao/silk_dress.c

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name( HIC"天青丝衣"NOR , ({ "silk dress", "dress" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("value", 40000);
		set("material", "cloth");
		set("armor_type", "cloth");
		set("armor_prop/armor", 1);
		set("armor_prop/dodge", 15);
	}
	setup();
}
