// buddha_staff.c

#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
	set_name( BLK"木禅杖"NOR, ({ "wood staff", "staff" }) );
	set_weight(800);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("long", "一条又粗又长，豪不起眼的木禅杖。\n");
		set("value", 6200);
		set("material", "wood");
		set("wield_msg", "$N拿出一根黑乎乎的$n握在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
		set("unpawnable",1);
	}

	init_staff(90);
	setup();
}
