#include <ansi.h>
#include <weapon.h>

inherit WHIP;
inherit F_UNIQUE;

void create()
{
        set_name(BLU"毒龙魔鞭"NOR, ({ "dulong whip","whip"}) );
        set_weight(9000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
                // set("unpawnable",1);

                set("value", 80000);
                set("material", "龙筋");
		set("rigidity",1000000);
                set("long",
                        "毒龙魔鞭，鞭长一丈七尺，上面生满倒刺，令人往而生畏。\n"
                );
                set("wield_msg", "$N从腰间解下$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n缠回腰间。\n");
                set("weapon_prop/attack", 20);
                set("weapon_prop/intelligence", -20);
                set("replica_ob", "/obj/weapon/whip");
        }
        init_whip(250);      
        setup();
}

int wield()
{
	if( this_player()->query_skill("mo-bian-jue",1) < 120)
	{
		return notify_fail("你使不动这件兵器。\n");
	}
	return ::wield();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        if(random(3)>0)
        	victim->start_busy(me->query_skill("mo-bian-jue",1)/170+1);
        return this_object()->name()+ HIY "在$n的$l处又兜了回来，将$n全身紧紧缠住！\n" NOR;
}
