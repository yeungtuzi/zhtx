// /d/xizang/class/bad/npc/obj/hook.c

#include <ansi.h>
#include <weapon.h>

inherit HOOK;

void destruct_me(object me);
void create()
{
	set_name( MAG "离别钩" NOR, ({ "leave hook", "hook" }) );
        set_weight(5000);
        set("code_name", "离别钩");
	set("been_used", 0);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这据说是七种兵器之一的离别钩");
                set("value", 1400000);
                set("unit", "把");
                set("material", "steel");
	set("wield_msg", "$N「刷」地一声抽出一柄闪著寒光的$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插入腰间的剑鞘。\n");
                set("rigidity", 40);
        }
	init_hook(51);
        setup();
}

int hit_ob(object me, object victim, int damage_bonus);
//me = attacker
//victim = target
{
	add("been_used", 1);
	if((int)query("been_used") >=10) {
		tell_object(me, "离别钩断掉了");
		call_out("destruct_me", 1, this_object());
	}
	return damage_bonus+random(25);
}

void destruct_me(object me)
{
	destruct(me);
}
