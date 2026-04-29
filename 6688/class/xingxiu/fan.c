// fan.c 

#include <weapon.h>

inherit DAGGER;

void create()
{
	set_name("鹅毛扇", ({ "fan" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "不管春夏秋冬，丁春秋手里总是拿着这把扇子。\n");
		set("value", 1000);
		set("material", "feather");
	}
	init_dagger(1);
	setup();
}
