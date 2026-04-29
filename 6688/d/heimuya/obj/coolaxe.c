#include <ansi.h>
#include <weapon.h>

inherit AXE;
inherit F_UNIQUE;

void create()
{
        set_name(RED"破天魔斧"NOR, ({ "sky axe", "axe" }) );
        set_weight(9000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
		// set("unpawnable",1);
                set("value", 0);
                set("material", "刚玉");
		set("rigidity",500000);
                set("long",
                        "这种斧头的刃长柄短，是专门用来做兵器的斧头，近战具有相当强的\n"
                        "杀伤力。\n");
                set("wield_msg", "$N抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插入腰间的束带间。\n");
                set("weapon_prop/attack", 10);
                set("weapon_prop/defense", -20);
                set("replica_ob", "/d/heimuya/obj/axe");
        }
        init_axe(150,EDGED | SECONDARY);      
        setup();
}

int wield()
{
	if( this_player()->query_skill("mo-fu-jue",1) < 120)
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
                        return "$n手中的" + weap_name
                                + "被$N挟雷霆万钧之势劈成两段！\n";
                }
                                
        }
	else 
		return damage_bonus*2;
}
