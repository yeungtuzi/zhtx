#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	set_name(MAG"淑女剑"NOR, ({ "girl sword", "sword" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 10000);

		set("material", "steel");
		set("long", "这是一把又细又长的剑，散发出萤荧紫光，轻飘飘的像是女孩子家的玩意。这是天山童姥传给梅兰竹菊四姐妹的。\n");
		set("wield_msg", "$N抽出一把剑身细长的剑，握在手中。\n");
		set("unequip_msg", "$N放下手中的$n。\n");
		set("weapon_prop/courage", -2);
		set("weapon_prop/composure", 2);
		set("weapon_prop/personality", 2);
	}
	init_sword(40);
	setup();
}
