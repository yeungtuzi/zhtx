
#include <ansi.h>
#include <weapon.h>

inherit STAFF;
inherit F_UNIQUE;

void create()
{
	set_name(HIR "紫金杖" NOR , ({ "zijin zhang", "staff" }) );
	set_weight(18000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("long", "一把用紫金精心打造的禅杖，紫光中透着寒气，令人不寒而栗\n");
		set("value", 20000);
		set("material", "violet-gold");
		set("no_sell",1);
		set("no_paimai",1);
		set("unpawnable",1);
		set("wield_msg", HIM "一道紫光闪过之后，$N手里多了把称心如意的$n" HIM + "。天地间刹时黯然失色，$N只觉得全身充满了力量。\n" NOR);
		set("unwield_msg", "$N放下手中的$n。\n");
		set("replica_ob","/class/lama/obj/9staff.c");
	}

	init_staff(230);
	setup();
}
