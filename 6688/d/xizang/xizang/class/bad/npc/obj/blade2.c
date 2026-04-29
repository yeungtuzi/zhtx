// /d/xizang/class/bad/npc/obj/blade2.c

#include <weapon.h>

inherit BLADE;

void destruct_me(object me);
void create()
{
	set_name( "碧玉胡刀" ({ "jade blade", "blade" }) );
        set_weight(51000);
        set("code_name", "碧玉胡刀");
	set("been_used", 0);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这把便是传说中的碧玉胡刀");
                set("value", 8000000);
                set("unit", "把");
		set("material", "jade");
                set("wield_msg", "$N「飕」地一声抽出一把背厚刃薄的$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插入腰间的刀鞘。\n");
                set("rigidity",140);
        }
	init_blade(95);
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
