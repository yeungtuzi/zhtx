// dagger.c 42book奖励
#include <ansi.h>
#include "/ldg/std/adv_weapon.h"

inherit ADV_DAGGER;

void create()
{
        set_name(HIR "匕"+HIW"首" NOR, ({ "bi shou","dagger" }));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "细看那匕首，剑身如墨，无半点光泽。\n");
                set("value", 500);
                set("material", "steel");
                set("unpawnable",1);
                set("adv_props/add_max_kee",25);
                set("adv_props/attack",10);
                set("adv_props/defense",5);
                set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中，只觉一股寒气扑面而来。\n");
                set("unwield_msg", "$N将手中的$n插回剑鞘，只听嗤的一声轻响。\n");

        }
        init_dagger(150);      
        setup();
}
int wield()
{
       object me,ob;
       me = this_player();
       ob = this_object();

              if( !me->query("book42_finished"))
                return notify_fail("这把匕首不属于你，你也用不了它。\n");

        return ::wield();
}

