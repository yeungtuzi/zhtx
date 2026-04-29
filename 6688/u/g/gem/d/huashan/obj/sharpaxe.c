#include <ansi.h>
#include <weapon.h>

inherit AXE;
inherit F_UNIQUE;

void create()
{
        set_name(RED"劈山神斧"NOR, ({ "cuthill axe", "axe" }) );
        set_weight(150000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
		set("unpawnable",1);
                set("value", 1);
                set("material", "sophie");
		set("rigidity",1000000);
                set("long",
                        "斧长七尺五寸左右，上铸“仙家宝斧，七尺有五，赐予沉香，劈山救母”十六个字。\n");
                set("wield_msg", "$N抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n放在地上。\n");
                set("weapon_prop/attack", 30);
                set("weapon_prop/defense", -10);
         }
        init_axe(155);      
        setup();
}

int wield()
{
	if( this_player()->query_str()+this_player()->query("max_force")/100 < 70)
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
