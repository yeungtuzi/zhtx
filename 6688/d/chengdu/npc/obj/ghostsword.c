
#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("幻影剑", ({ "ghostsword" }));
	set_weight(6000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是影子刺客的成名武器，剑身黑而无光，杀气逼人。\n");
		set("value", 20000);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一把黑而无光的$n，顿时杀气逼人！\n");
		set("unwield_msg", "$N将手中的$n藏回袖中，杀气顿敛。\n");
	}
	init_sword(150);
	setup();
}
