// longsword.c 长鞭

#include <ansi.h>
#include "/ldg/std/adv_weapon.h"

inherit ADV_SWORD;

void create()
{
	set_name(RED"血剑"NOR, ({"blood sword","sword" }));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", RED"一柄血色长剑，杀气冲天。\n"NOR);
		set("value", 100);
		set("material", "steal");
		set("adv_props/add_max_kee",20);
		set("adv_props/defense",10);
		set("wield_msg", "$N「唰」的一声抖出一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回腰间。\n");
	}
	init_sword(120);
	setup();
}

void owner_is_killed(object killer)
{
        // 2026-04-30: unused variable commented out
        // object owner;
	if(environment()->query("id")!="yan bei")
	{
		destruct(this_object());
		return;
	}
	::owner_is_killed(killer);
	return;
}
