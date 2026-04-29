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
                set("adv_props/armor_vs_force",100);
                set("adv_props/armor",100);
                set("adv_props/add_max_kee",150);
                set("adv_props/add_max_sen",80);
                set("adv_props/add_max_gin",80);
                set("wear_msg", "$N将$n戴在右手中指上，立即感受到一种奇异的力量在丹田团聚！\n");
        }
    setup();
}

void owner_is_killed(object killer)
{
        object owner;
        if(environment()->query("id")!="niumo wang")
	{
		destruct(this_object());
		return;
	}
	::owner_is_killed(killer);
	return;
}

int wear()
{
        if( this_player()->query_skill("force",1) < 350 )
                return notify_fail("你的内功不够，无法驾御魔戒之王强大的能量。\n");
        if( this_player()->query("wlshw") < 100 )
                return notify_fail("你的武林声望不够，不配佩带魔戒之王。\n");
        return ::wear();
}
