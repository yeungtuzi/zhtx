// /d/xizang/class/gold_wh/npc/obj/quan2.c

#include <weapon.h>
inherit HAMMER;

void create()
{
	set_name("金刚圈",({"jingang quan", "quan", "ring"}));
	set_weight(8000);
	if( clonep() )
                set_default_object(__FILE__);
	else {
                set("unit", "个");
		set("long", "这是仿照法王弟子桑吉多所用兵器打造的金刚圈\n");
		set("value", 100);
		set("material", "steel");
	}
	init_hammer(7);
	setup();
}
