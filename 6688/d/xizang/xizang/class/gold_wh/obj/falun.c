// /d/xizang/class/gold_wh/obj/falun.c

#include <weapon.h>
inherit HAMMER;

void create()
{
	set_name("法轮",({"fa lun", "lun"}));
	set_weight(30000);
	if( clonep() )
                set_default_object(__FILE__);
	else {
                set("unit", "个");
		set("long", "这是仿照法王自用的金轮打造的铁轮\n");
		set("value", 1000);
		set("material", "steel");
	}
	init_hammer(65);
	setup();
}
