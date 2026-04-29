// /d/xizang/class/gold_wh/npc/obj/chu.c

#include <weapon.h>
inherit HAMMER;

void create()
{
	set_name("降魔杵",({"xiang mo chu", "chu"}));
	set_weight(70000);
	if( clonep() )
                set_default_object(__FILE__);
	else {
                set("unit", "柄");
		set("long", "这是法王弟子达尔巴所用的降魔杵\n");
		set("value", 30000);
		set("material", "gold");
	}
	init_hammer(160);
	setup();
}
