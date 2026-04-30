#include <ansi.h>
#include "/ldg/std/adv_weapon.h"

inherit ADV_BLADE;

void create()
{
	set_name( YEL"横行刀"NOR, ({ "hengxing blade", "blade" }) );
	set_weight(800);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", YEL"此刀每一面的刀身上都镌有四个字，一面是一刀在手，\n"
			    "另一面是快意恩仇，刀把末端还有横行两个字，刀名横行\n"NOR);
		set("value", 6200);
		set("material", "brass");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回刀鞘。\n");
	}
	init_blade(150);
	setup();
}

void owner_is_killed(object killer)
{
        // 2026-04-30: unused variable commented out
        // object owner;
	if(environment()->query("id")!="pu gongwang")
	{
		destruct(this_object());
		return;
	}
	::owner_is_killed(killer);
	return;
}