// gangzhang.c 钢杖

#include <weapon.h>
inherit STAFF;

void create()
{
	set_name("钢杖", ({ "gangzhang" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", "这是一根又粗又重的钢杖。\n");
		set("value", 1500);
		set("rigidity",100);
 	        set("material", "steel");
		set("wield_msg", "$N将一根$n握在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}
  	init_staff(20);
	setup();
}
