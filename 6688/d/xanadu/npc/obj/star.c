// star.c

#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
	set_name(HIY"流星蝴蝶剑"NOR, ({ "star" }) );
	set_weight(100);
	set("no_get",1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 0);
		set("material", "steel");
		set("long", "这是流星雨的成名兵器，剑身细长，十分轻盈。\n");
		set("wield_msg", "$N抽出一把剑身细长的剑，握在手中。\n");
		set("unequip_msg", "$N放下手中的$n。\n");
	}
	init_sword(85);
	setup();
}
