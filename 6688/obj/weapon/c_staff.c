
#include <weapon.h>
inherit STAFF;

void create()
{
	set_name("比武用杖", ({ "staff" }));
	set_weight(8000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long","这是一根专供比武用的钢杖。\n");
		set("value", 1000);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一根$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回腰间。\n");
	}
	init_staff(15);
	setup();
}
