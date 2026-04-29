// zjzsword.c 

#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
	set_name(RED "无刃" NOR, ({ "wu ren","sword"}));
	set_weight(20000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "一把毫不起眼的长剑。\n");
		set("value", 300000);
                set("rigidity", 1000000);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抖出一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回腰间。\n");
	}
	init_sword(100);
	setup();
}
