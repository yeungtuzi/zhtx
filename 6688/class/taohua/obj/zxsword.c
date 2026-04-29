#include <weapon.h>
inherit SWORD;
void create()
{
	set_name("[1;35m追星蝴蝶剑[2;76;0m", ({ "swo" }) );
      set("no_get",1);
	set_weight(7600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把看黑色的长剑，份量不轻。\n");
                set("rigidity",760);
                set("value",0);
		set("material", "steel");
		set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
	}
	init_sword(76);
	setup();
}
