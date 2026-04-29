// lovefan.c

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("美人扇", ({ "lover fan" }));
	set_weight(7000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是多情公子候希白的成名武器。扇面上是他亲手所绘美人图。\n");
		set("value", 10000);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声打开一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回颈中。\n");
	}
	init_blade(80);
	setup();
}
