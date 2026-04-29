// buddha_staff.c

#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
	set_name( HIY "青天白云杖" NOR, ({ "cloud staff", "staff" }) );
	set_weight(800);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("long", "一条又粗又长，非常沈重的青铜禅杖，上面镶著十八个白金环。\n");
		set("value", 6200);
		set("material", "brass");
		set("wield_msg", "$N拿出一根青色的$n握在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
		set("unpawnable",1);
	}

	init_staff(90);
	setup();
}
