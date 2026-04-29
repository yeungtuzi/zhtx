// /d/xizang/npc/obj/sun.c
// 长河落日
// a better shield than leather shield
// by mscat

#include <armor.h>
#include <ansi.h>

inherit SHIELD;

void create()
{
        set_name(HIC"长河"+HIY"落"+HIR"日"NOR, ({ "river sun", "sun", "shield"}));
        set_weight(2200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "steel");
		set("unit", "面");
		set("long", "这是卜鹰自己打造的盾牌\n");
		set("value", 1000);
		set("rigidity", 200);
		set("armor_prop/armor", 22);
		set("armor_prop/defense", 17);
		set("armor_prop/armor_vs_force", 97);
	}
	setup();
}
