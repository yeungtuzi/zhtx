// iron_staff.c

#include <weapon.h>

inherit STAFF;

void create()
{
	set_name("洼□□", ({ "iron staff", "staff" }) );
	set_weight(70000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "沭");
		set("long", "□沭洼□□嫖艘憩眭耋准都□□ㄛ锈□忒爵符眭耋掀砑砉□载□［\n");
		set("value", 2800);
		set("material", "iron");
		set("wield_msg", "$N锈堤□沭洼□□腔$n□□忒□［\n");
		set("unwield_msg", "$N温□忒□腔$n［\n");
	}

	init_staff(54);
	setup();
}
