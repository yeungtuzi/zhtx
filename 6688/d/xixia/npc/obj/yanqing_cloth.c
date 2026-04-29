#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name(CYN"青布长袍"NOR, ({ "chang pao", "pao" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("value", 6000);
		set("material", "cloth");
		set("armor_prop/armor", 8);
		set("armor_prop/personality", 1);
	}
	setup();
}
