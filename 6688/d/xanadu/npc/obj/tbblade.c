
#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
	set_name(HIY"天兵宝刀"NOR, ({ "tianbing baodao", "baodao", "blade" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 0);
		set("material", "iron");
		set("long", "刀名“天兵”，边缘隐隐透出血光。\n");
		set("wield_msg", "$N抽出一把明晃晃的$n握在手中。\n");
		set("unequip_msg", "$N将手中的$n插入腰间的刀鞘。\n");
		set("weapon_prop/attack",50);
	}
	init_blade(120);
	setup();
}
