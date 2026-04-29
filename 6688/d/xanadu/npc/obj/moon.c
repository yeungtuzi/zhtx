// moon.c

#include <ansi.h>
#include <weapon.h>

inherit DAGGER;

void create()
{
	set_name(HIG"天涯明月刀"NOR, ({ "moon" }) );
	set_weight(100);
	set("no_get",1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 0);
		set("material", "steel");
		set("long", "这是流星雨的成名兵器，刀身呈碧绿之色，其薄如纸。\n");
		set("wield_msg", "$N抽出一把碧绿色的$n，握在手中。\n");
		set("unequip_msg", "$N放下手中的$n。\n");
	}
	init_dagger(85);
	setup();
}
