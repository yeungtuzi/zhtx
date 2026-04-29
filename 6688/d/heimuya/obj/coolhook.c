#include <ansi.h>
#include <weapon.h>

inherit HOOK;
inherit F_UNIQUE;

void create()
{
        set_name(CYN"断玉魔钩"NOR, ({ "duanyu gou", "gou" }) );
        set_weight(9000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 80000);
                // set("unpawnable",1);

                set("material", "刚玉");
		set("rigidity",500000);
                set("long",
                        "切金断玉，是为魔钩。\n"
		);
                set("wield_msg", "$N抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回背上。\n");
                set("weapon_prop/attack", 10);
                set("weapon_prop/defense", 15);
                set("replica_ob", "/d/heimuya/obj/gou");
        }
        init_hook(150,EDGED | SECONDARY);      
        setup();
}

int wield()
{
	if( this_player()->query_skill("mo-gou-jue",1) < 120)
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
                        weap_name = weap->query("name");
                        weap->unequip();
                        weap->move(environment(victim));
                        weap->set("name", "断掉的" + weap->query("name"));
	                weap->set("value", 0);
                        weap->set("weapon_prop", 0);
                        weap->set("long", weap->query("long")+"可是，现在却已经断为两截，不知道还有什么用处。\n");
                        victim->reset_action();
                        return HIY"$N用" + query("name") 
				+ "扣住$n手中的" + weap_name+"，运力一扳，“啪”！\n"NOR;
                }
                                
        }
	else 
		return damage_bonus*2;
}
