
#include <weapon.h>

inherit QIN;

void create()
{
	set_name("比武用琴", ({ "qin" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 1000);
		set("material", "steel");
                set("long","一把专供比武用的琴\n");
                set("wield_msg", "$N从琴套中抽出一把$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n放入琴套中。\n");

	}
	init_qin(15);

	setup();
}
