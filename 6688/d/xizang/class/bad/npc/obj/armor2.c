// /d/xizang/class/bad/npc/obj/armor2.c

#include <armor.h>
#include <ansi.h>

inherit ARMOR;

void destruct_me(object me);
void create()
{
        set_name(HIY"怒龙锦胄" NOR, ({ "dragon armor", "armor" }) );
        set_weight(3000);
        set("code_name", "怒龙锦胄");
	set("been_hit", 0);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一件据说是於兰天武的护身宝衣怒龙锦胄");
                set("value", 10000000);
                set("unit", "件");
                set("material", "goldsilk");
                set("armor_prop/armor", 20);
		set("armor_prop/armor_vs_force", 100);
		set("armor_prop/dodge", -5);
        }
        setup();
}

int dispersion_damage(object killer,object victim,int damage)
{
	add("been_hit", 1);
	if((int)query("been_hit")>=10) {
		tell_object(victim,"甲被打破了");
		call_out("destruct_me", 1, this_object());
	}
	return damage-random(20);
}

void destruct_me(object me)
{
	destruct(me);
}
