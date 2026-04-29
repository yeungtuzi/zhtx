// /d/xizang/class/budala/npc/obj/staff.c

#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
	set_name("镔铁禅杖" , ({ "iron staff", "staff" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("long", "一条黝黑发亮的镔铁禅杖,显然刚刚打造好\n");
		set("value", 30);
		set("material", "iron");
		set("wield_msg", "$N拿出一条黝黑发亮的$n握在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}

	init_staff(14);
	setup();
}
