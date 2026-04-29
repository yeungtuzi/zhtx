#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name(RED"大红袍"NOR, ({ "red robe", "robe" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这件大红袍子上门还锈着一头张牙舞抓的老虎。\n");
		set("unit", "件");
		set("value", 6000);
		set("material", "cloth");
		set("armor_prop/armor", 10);
		set("armor_prop/courage", 2);
	}
	setup();
}
