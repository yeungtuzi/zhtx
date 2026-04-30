#include <ansi.h>
#include "/ldg/std/adv_weapon.h"

inherit ADV_WHIP;

void create()
{
    set_name( CYN"天蝉忘情丝"NOR, ({"wangqing si","whip","si"}) );
    set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
    		set("value", 500);
                set("material", "leather");
                set("rigidity", 170);
		set("adv_props/damage",50);
		set("adv_props/add_max_kee",20);
		set("adv_props/add_max_sen",10);
		set("adv_props/add_max_gin",10);
                set("wield_msg", "$N从腰间解下一条$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n缠回腰间。\n");
        }
    init_whip(50);
    setup();
}

void owner_is_killed(object killer)
{
        // 2026-04-30: unused variable commented out
        // object owner;
	if(environment()->query("id")!="nan feiyan")
	{
		destruct(this_object());
		return;
	}
	::owner_is_killed(killer);
	return;
}