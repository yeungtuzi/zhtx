// /d/xizang/class/gold_wh/npc/obj/weapon.c

#include <weapon.h>
inherit HAMMER;

string * name_list=({
"降魔杵",
"金刚圈",
"法轮",
"短棒",
"扣钟"
});

string * unit_list=({
"柄",
"个",
"个",
"条",
"个"
});

void create()
{
	int i;
	i = random(sizeof(name_list));
	set_name(name_list[i],({"weapon", "bingqi"}));
	set_weight(3000 +500*random(11));
	if( clonep() )
                set_default_object(__FILE__);
	else {
                set("unit", unit_list[i]);
		set("long", "这是一件法王的弟子喜欢使用的笨重短兵器\n");
		set("value", 0);
		set("material", "steel");
	}
	init_hammer(20+random(50));
	setup();
}
