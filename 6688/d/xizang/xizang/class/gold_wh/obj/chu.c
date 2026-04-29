// /d/xizang/class/gold_wh/obj/chu.c

#include <weapon.h>
inherit HAMMER;

void create()
{
	set_name("降魔杵",({"xiang mo chu", "chu"}));
	set_weight(30000);
	if( clonep() )
                set_default_object(__FILE__);
	else {
                set("unit", "柄");
		set("long", "这是仿照法王弟子达尔巴所用兵器打造的降魔杵\n");
		set("value", 1000);
		set("material", "steel");
	}
	init_hammer(60);
	setup();
}
