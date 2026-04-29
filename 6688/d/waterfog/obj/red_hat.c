// red_hat.c

#include <armor.h>

inherit HEAD;

void create()
{
	set_name("□绽踢□梦", ({ "crimson hat", "hat" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "阶");
		set("long", "□□□□跨□□都渴腔绽伎埴阶签ㄛ签埽眄□□□踢□［\n");
		set("value", 800);
		set("armor_prop/attack", 2);
		set("armor_prop/defense", -2);
		set("armor_prop/armor", 4);
	}
	setup();
}
