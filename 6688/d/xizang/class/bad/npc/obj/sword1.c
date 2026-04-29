// /d/xizang/class/bad/npc/obj/sword1.c

#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void destruct_me(object me);
void create()
{
	set_name( CYN "风泉之剑" NOR, ({ "sword of windspring", "sword" }) );
        set_weight(10000);
        set("code_name", "风泉之剑");
	set("been_used", 0);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这据说是步玄派的掌门信物风泉之剑");
                set("value", 10000000);
                set("unit", "把");
                set("material", "sapphire");
	set("wield_msg", "$N「刷」地一声抽出一柄闪著寒光的$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插入腰间的剑鞘。\n");
                set("weapon_prop/courage", 15);
                set("weapon_prop/intelligence", 15);
                set("weapon_prop/personality", 15);
                set("rigidity", 40);
        }
	init_sword(55);
        setup();
}

int hit_ob(object me, object victim, int damage_bonus);
//me = attacker
//victim = target
{
	add("been_used", 1);
	if((int)query("been_used") >=10) {
		tell_object(me, "剑断掉了");
		call_out("destruct_me", 1, this_object());
	}
	return damage_bonus+random(25);
}

void destruct_me(object me)
{
	destruct(me);
}
