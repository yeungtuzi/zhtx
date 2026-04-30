#include <ansi.h>
#include "/ldg/std/adv_armor.h"

inherit ADV_FINGER;

void create()
{
    set_name( HIW"魔戒之王"NOR, ({"demon ring of king","ring"}) );
    set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "枚");
    		set("value", 500);
                set("material", "diamond");
                set("rigidity", 170);
                 set("adv_props/armor_vs_force",9000);
                 set("adv_props/armor_vs_spells",9000);
                 set("adv_props/armor",3000);
                 set("adv_props/parry",1000);
                 set("adv_props/defense",1000);
                 set("adv_props/add_max_kee",1000);
                 set("adv_props/add_max_sen",1000);
                 set("adv_props/add_max_gin",1000);
                 set("adv_props/dodge",900);
                set("wear_msg", "$N将$n戴在右手中指上，立即感受到一种奇异的力量在丹田团聚！\n");
        }
    setup();
}

void owner_is_killed(object killer)
{
        // 2026-04-30: unused variable commented out
        // object owner;
        if(environment()->query("id")!="niumo wang")
	{
		destruct(this_object());
		return;
	}
	::owner_is_killed(killer);
	return;
}

