#include <ansi.h>
#include <weapon.h>

inherit SPEAR;
inherit F_UNIQUE;

void create()
{
        set_name(RED"刺日魔枪"NOR, ({ "ciri qiang", "qiang" }) );
        set_weight(9000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                // set("unpawnable",1);

                set("value", 80000);
                set("material", "刚玉");
		set("rigidity",500000);
                set("long",
                        RED"诛天灭地，弑佛杀神，六合八荒，唯我独尊。\n"NOR
		);
                set("wield_msg", "$N抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回背上。\n");
                set("weapon_prop/attack", 30);
                set("weapon_prop/defense", 5);
                set("replica_ob", "/obj/weapon/spear");

        }
        init_spear(250);      
        setup();
}

int wield()
{
	if( this_player()->query_skill("mo-qiang-jue",1) < 120)
	{
		return notify_fail("你使不动这件兵器。\n");
	}
	return ::wield();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	return damage_bonus*6+random(damage_bonus*6);
}
