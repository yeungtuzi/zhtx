// /d/xizang/class/bad/npc/obj/blade1.c

#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void destruct_me(object me);
void create()
{
	set_name( GRN "妖刀狗屠" NOR, 
	({ "houndbane blade", "houndbane", "blade" }) );
        set_weight(15000);
        set("code_name", "妖刀狗屠");
	set("been_used", 0);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这据说是於兰天武的兵刃妖刀狗屠");
                set("value", 8000000);
                set("unit", "把");
		set("material", "crimsonsteel");
                set("wield_msg", "$N「飕」地一声抽出一把背厚刃薄的$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插入腰间的刀鞘。\n");
                set("weapon_prop/courage", 10);
                set("rigidity", 40);
        }
	init_blade(75);
        setup();
}

int hit_ob(object me, object victim, int damage_bonus);
//me = attacker
//victim = target
{
	add("been_used", 1);
	if((int)query("been_used") >=10) {
		tell_object(me, "刀断掉了");
		call_out("destruct_me", 1, this_object());
	}
	return damage_bonus+random(25);
}

void destruct_me(object me)
{
	destruct(me);
}
