// spear.c : an example weapon

#include <weapon.h>
#include <ansi.h>
inherit SPEAR;

void create()
{
	set_name("长枪", ({ "spear","qiang" }) );
	set_weight(15000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", HIG"这是一把看起相当锋利的长枪，枪尖绿光闪烁。\n"NOR);
		set("value", 1000);
		set("material", "steel");
	}
	init_spear(30);
		set("poison/type","tm_poison");
		set("poison/amount",100);

// These properties are optional, if you don't set them, it will use the
// default values.

	set("wield_msg", "$N「唰」地一声,把$n横在胸前。\n");
	set("unwield_msg", "$N将手中的$n收起。\n");

// The setup() is required.

	setup();
}
