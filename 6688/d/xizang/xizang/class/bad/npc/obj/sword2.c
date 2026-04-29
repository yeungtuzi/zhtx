// /d/xizang/class/bad/npc/obj/sword2.c

#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void destruct_me(object me);
void create()
{
	set_name( HIW "邪剑穿灵" NOR, ({ "soulimpaler", "sword" }) );
        set_weight(5000);
        set("code_name", "邪剑穿灵");
	set("been_used", 0);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这据说是寒於三宝之一的邪剑穿灵");
                set("value", 2000000);
                set("unit", "把");
                set("material", "crimsonsteel");
	set("wield_msg", "$N「刷」地一声抽出一柄闪著寒光的$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插入腰间的剑鞘。\n");
                set("rigidity", 40);
        }
	init_sword(61);
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
