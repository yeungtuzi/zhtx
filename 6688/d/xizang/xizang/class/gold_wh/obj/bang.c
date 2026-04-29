// /d/xizang/class/gold_wh/obj/bang.c

#include <weapon.h>
inherit HAMMER;

void create()
{
	set_name("短棒",({"duan bang", "bang", "stick"}));
	set_weight(28000);
	if( clonep() )
                set_default_object(__FILE__);
	else {
                set("unit", "条");
		set("long", "这是金轮派一般高级弟子常用的短铁棒\n");
		set("value", 500);
		set("material", "steel");
	}
	init_hammer(50);
	setup();
}
