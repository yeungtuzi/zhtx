// qian.c 长枪

#include <weapon.h>
inherit SPEAR;

void create()
{
	set_name("比武用枪", ({ "spear", "qian" }));
	set_weight(3000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄武者自己打造的红缨枪,上面缠着防止手滑的麻布\n");
		set("value", 10);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回枪囊。\n");
	}
	init_spear(15);
	setup();
}
