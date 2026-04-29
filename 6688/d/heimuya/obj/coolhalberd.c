#include <ansi.h>
#include <weapon.h>

inherit HALBERD;
inherit F_UNIQUE;

void create()
{
        set_name(GRN"温侯魔戟"NOR, ({ "wenhou ji", "ji" }) );
        set_weight(9000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 80000);
                // set("unpawnable",1);

                set("material", "刚玉");
		set("rigidity",500000);
                set("long",
                        "温侯魔戟，兵中之王。\n"
		);
                set("wield_msg", "$N抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插入背后的长曩。\n");
                set("weapon_prop/attack", 5);
                set("weapon_prop/defense", 10);
                set("replica_ob", "/d/heimuya/obj/ji");
        }
        init_halberd(150,EDGED | SECONDARY);      
        setup();
}

int wield()
{
	if( this_player()->query_skill("mo-ji-jue",1) < 120)
	{
		return notify_fail("你使不动这件兵器。\n");
	}
	return ::wield();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        object weap;
        int    wap,wdp;
        string weap_name;

        if(victim == me) return;
        if( objectp(weap = victim->query_temp("weapon")) )
        {

                wap = weight() / 500
                        + query("rigidity")
                        + me->query("str");

                wdp = (int)weap->weight() / 500
                        + (int)weap->query("rigidity")
                        + (int)victim->query("str");

                if(  random(wap) > wdp )
                {
                       weap->move(environment(me));
                        victim->reset_action();
                        return HIY"$n手中的" + weap_name
                                + "被$N挟雷霆万钧之势一挑，脱手飞出！\n"NOR;
                }
                                
        }
	else 
		return damage_bonus*2;
}
