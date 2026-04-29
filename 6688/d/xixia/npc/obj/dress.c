#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name(HIY"天凤宝衣"NOR, ({ "phoenix dress", "dress"}) );
	set_weight(1100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("value", 60000);
		set("material", "silk");
		set("armor_prop/armor", 3);
		set("armor_prop/personality", 3);
		set("armor_prop/dodge", 10);
		set("female_only", 1);
	}
	setup();
}
