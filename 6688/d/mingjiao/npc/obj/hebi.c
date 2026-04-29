
#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("鹤笔", ({ "crane sword","sword" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是鹤笔翁的成名兵器，笔端锐如鹤嘴，却是晶光闪亮。\n");
		set("value", 400);
		set("material", "steel");
		set("wield_msg", "$N「唰」地一声抽出一对$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插入腰间。\n");
	}
	init_sword(80);
	setup();
}
