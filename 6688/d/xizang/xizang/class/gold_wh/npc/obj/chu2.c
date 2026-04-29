// /d/xizang/class/gold_wh/npc/obj/chu2.c

#include <weapon.h>
inherit HAMMER;

void create()
{
	set_name("降魔杵",({"xiang mo chu", "chu"}));
	set_weight(10000);
	if( clonep() )
                set_default_object(__FILE__);
	else {
                set("unit", "柄");
		set("long", "这是仿照法王弟子达尔巴所用兵器打造的降魔杵\n");
		set("value", 100);
		set("material", "steel");
	}
	init_hammer(30);
	setup();
}
