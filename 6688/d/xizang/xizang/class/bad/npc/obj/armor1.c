// /d/xizang/class/bad/npc/obj/armor1.c

#include <armor.h>

inherit ARMOR;

void destruct_me(object me);
void create()
{
        set_name("软猬甲", ({ "ruan wei jia", "jia", "armor" }) );
        set_weight(3000);
        set("code_name", "软猬甲");
	set("been_hit", 0);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一件据说是桃花岛的至宝软猬甲");
                set("value", 5000000);
                set("unit", "件");
                set("material", "copper");
                set("armor_prop/armor", 10);
		set("armor_prop/dodge", -5);
        }
        setup();
}

int dispersion_damage(object killer,object victim,int damage)
{
//killer很明显是动手打人的
//victim是被打的，
//damage是将要给的伤害值。
	if(!killer->query_temp("weapon") && damage>0) {
//空手打软猬甲自伤,打的越狠伤的越重
		killer->receive_damage("kee", damage);
		tell_object(killer,
"你打中对方身体,觉得一阵剧烈的刺痛,原来这家伙穿了软猥甲!\n");
	}
	add("been_hit", 1);
	if((int)query("been_hit")>=10) {
		tell_object(victim,"甲被打破了");
		call_out("destruct_me", 1, this_object());
	}
	return damage-random(10);
}

void destruct_me(object me)
{
	destruct(me);
}
